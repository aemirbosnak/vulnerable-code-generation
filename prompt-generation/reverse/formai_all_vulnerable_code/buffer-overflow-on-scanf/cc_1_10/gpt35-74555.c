//FormAI DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to get temperature by user input
float get_temperature() {
    float temperature;
    printf("Please enter the temperature: ");
    scanf("%f", &temperature);
    return temperature;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float temperature) {
    float fahrenheit = (temperature * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float temperature) {
    float celsius = (temperature - 32) / 1.8;
    return celsius;
}

int main() {
    float temperature, converted_temperature;
    int choice;

    printf("Welcome to the temperature monitoring system\n");

    while (true) {
        printf("\nSelect an option:\n");
        printf("1. Enter temperature in Celsius\n");
        printf("2. Enter temperature in Fahrenheit\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperature = get_temperature();
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, converted_temperature);
                break;

            case 2:
                temperature = get_temperature();
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, converted_temperature);
                break;

            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}