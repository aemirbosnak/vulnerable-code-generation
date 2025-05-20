//FormAI DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius temperature to Fahrenheit
double celsiusToFahrenheit(double c) {
    return (c * 1.8) + 32;
}

// Function to convert Fahrenheit temperature to Celsius
double fahrenheitToCelsius(double f) {
    return (f - 32) / 1.8;
}

// Function to convert Kilometers to Miles
double kmToMiles(double km) {
    return km * 0.621371;
}

// Function to convert Miles to Kilometers
double milesToKm(double miles) {
    return miles / 0.621371;
}

// Main function to perform unit conversions
int main() {
    int choice = 0;
    double input, output;

    // Loop until user chooses to exit
    while (1) {
        // Display menu
        printf("\nMENU\n\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Exit\n");

        // Prompt user for choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Exit if user chooses option 5
        if (choice == 5) {
            break;
        }

        // Prompt user for input value
        printf("Enter the input value: ");
        scanf("%lf", &input);

        // Perform selected conversion and display result
        switch (choice) {
            case 1:
                output = celsiusToFahrenheit(input);
                printf("%.2f Celsius = %.2f Fahrenheit\n", input, output);
                break;
            case 2:
                output = fahrenheitToCelsius(input);
                printf("%.2f Fahrenheit = %.2f Celsius\n", input, output);
                break;
            case 3:
                output = kmToMiles(input);
                printf("%.2f Kilometers = %.2f Miles\n", input, output);
                break;
            case 4:
                output = milesToKm(input);
                printf("%.2f Miles = %.2f Kilometers\n", input, output);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    // Exit program
    printf("Goodbye!\n");
    return 0;
}