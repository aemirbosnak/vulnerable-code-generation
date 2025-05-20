//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the average temperature
double calculate_average_temperature(double temperature[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += temperature[i];
    }
    return sum / size;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to display temperature in different units
void display_temperature(double temperature, int unit) {
    if (unit == 1) {
        printf("%.2f degrees Celsius\n", temperature);
    } else {
        printf("%.2f degrees Fahrenheit\n", celsius_to_fahrenheit(temperature));
    }
}

int main() {
    int size;
    printf("Enter the number of temperatures you want to monitor: ");
    scanf("%d", &size);

    double temperature[size];
    printf("Enter the temperatures (in Celsius):\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &temperature[i]);
    }

    int unit;
    printf("Enter 1 to display temperature in Celsius or 2 to display temperature in Fahrenheit: ");
    scanf("%d", &unit);

    double average_temperature = calculate_average_temperature(temperature, size);
    printf("The average temperature is: ");
    display_temperature(average_temperature, unit);

    return 0;
}