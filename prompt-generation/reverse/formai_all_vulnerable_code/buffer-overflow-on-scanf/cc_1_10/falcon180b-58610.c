//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    float temperature;

    // Post-apocalyptic style introduction
    printf("In the desolate wasteland of what was once a thriving civilization,\n"
           "survival is the only thing that matters. Temperature control systems\n"
           "are a thing of the past, and knowing how to convert between Celsius\n"
           "and Fahrenheit could mean the difference between life and death.\n\n");

    // Menu
    printf("1. Convert Celsius to Fahrenheit\n"
           "2. Convert Fahrenheit to Celsius\n"
           "3. Exit\n\n");
    scanf("%d", &choice);

    // Error handling for invalid choice
    if (choice < 1 || choice > 3) {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    // Input temperature
    printf("Enter temperature: ");
    scanf("%f", &temperature);

    // Convert temperature
    switch (choice) {
        case 1:
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        default:
            printf("Exiting...\n");
            break;
    }

    return 0;
}