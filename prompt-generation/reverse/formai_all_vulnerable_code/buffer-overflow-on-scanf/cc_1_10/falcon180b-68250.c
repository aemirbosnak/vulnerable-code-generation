//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the average temperature
double calculate_average(double temperatures[], int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += temperatures[i];
    }
    return sum / n;
}

// Function to calculate the standard deviation of temperatures
double calculate_standard_deviation(double temperatures[], int n) {
    double mean = calculate_average(temperatures, n);
    double sum_squared_differences = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum_squared_differences += pow((temperatures[i] - mean), 2);
    }
    return sqrt(sum_squared_differences / n);
}

int main() {
    int n;
    double temperatures[100];
    double average_temperature, standard_deviation;

    // Get the number of temperatures from the user
    printf("Enter the number of temperatures: ");
    scanf("%d", &n);

    // Get the temperatures from the user
    printf("Enter the temperatures:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temperatures[i]);
    }

    // Calculate the average temperature
    average_temperature = calculate_average(temperatures, n);

    // Calculate the standard deviation of temperatures
    standard_deviation = calculate_standard_deviation(temperatures, n);

    // Print the results
    printf("Average temperature: %.2lf\n", average_temperature);
    printf("Standard deviation: %.2lf\n", standard_deviation);

    return 0;
}