//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to calculate average temperature
double calculateAverage(double temperature[], int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += temperature[i];
    }

    return sum / size;
}

// Function to calculate variance
double calculateVariance(double temperature[], int size) {
    double mean = calculateAverage(temperature, size);
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += pow(temperature[i] - mean, 2);
    }

    return sum / size;
}

// Function to calculate standard deviation
double calculateStandardDeviation(double temperature[], int size) {
    return sqrt(calculateVariance(temperature, size));
}

// Function to print temperature data
void printTemperatureData(double temperature[], int size) {
    printf("Temperature data:\n");

    for (int i = 0; i < size; i++) {
        printf("%lf\n", temperature[i]);
    }
}

// Function to print temperature chart
void printTemperatureChart(double temperature[], int size) {
    printf("\nTemperature chart:\n");

    for (int i = 0; i < size; i++) {
        printf("*");
    }

    printf("\n");
}

int main() {
    int size;
    double temperature[100];

    // Get temperature data from user
    printf("Enter the number of temperature readings: ");
    scanf("%d", &size);

    printf("Enter the temperature readings:\n");

    for (int i = 0; i < size; i++) {
        scanf("%lf", &temperature[i]);
    }

    // Convert temperature from Celsius to Fahrenheit
    for (int i = 0; i < size; i++) {
        temperature[i] = celsiusToFahrenheit(temperature[i]);
    }

    // Calculate average, variance, and standard deviation
    double average = calculateAverage(temperature, size);
    double variance = calculateVariance(temperature, size);
    double standardDeviation = calculateStandardDeviation(temperature, size);

    // Print temperature data
    printf("\nTemperature data in Fahrenheit:\n");

    for (int i = 0; i < size; i++) {
        printf("%lf\n", temperature[i]);
    }

    // Print temperature chart
    printf("\nTemperature chart:\n");

    for (int i = 0; i < size; i++) {
        printf("*");
    }

    printf("\n");

    // Print average, variance, and standard deviation
    printf("\nAverage temperature: %lf\n", average);
    printf("Variance: %lf\n", variance);
    printf("Standard deviation: %lf\n", standardDeviation);

    return 0;
}