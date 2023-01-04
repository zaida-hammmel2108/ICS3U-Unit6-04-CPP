// Copyright Zaida Hammel 2022
//
// Created by Zaida Hammel
// Created in Dec 2022
// This program calculates the average

#include <time.h>
#include <array>
#include <iostream>
#include <random>
#include <cmath>

template <int rows, int cols>
float CalculateAverage(int (&passedIn2DList)[rows][cols]) {
    // This function calculates the average
    float average = 0;
    double sum = 0;
    float length = sizeof(passedIn2DList) / sizeof(passedIn2DList[0]);

    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement)
            sum += passedIn2DList[rowElement][columnElement];
    }
    average = round(sum / (rows * cols) * 100) / 100;

    return average;
}

int main() {
    // This function uses an array

    int aRandomNumber;
    double totalAverage;
    const int rows = 3;
    const int columns = 5;
    std::string strRows;
    std::string strColumns;
    int a2DArray[rows][columns];

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, 50);

    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            aRandomNumber = idist(rgen);
            a2DArray[rowElement][columnElement] = aRandomNumber;
            std::cout << aRandomNumber << ", ";
        }
        std::cout << std::endl;
    }

    // call function
    totalAverage = CalculateAverage(a2DArray);
    std::cout << "The average of all the numbers is: " << totalAverage
    << std::endl;

    std::cout << "\nDone." << std::endl;
}
