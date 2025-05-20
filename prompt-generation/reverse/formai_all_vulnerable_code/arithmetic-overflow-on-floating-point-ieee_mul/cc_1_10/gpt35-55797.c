//FormAI DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Miles to Kilometers
float milesToKilometers(float miles) {
    return miles * 1.60934;
}

// Function to convert Kilometers to Miles
float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

int main() {
    int choice = 0;
    float input = 0.0, output = 0.0;

    printf("Welcome to Unit Converter\n\n");

    while (choice != 5) {
        printf("Choose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Exit\n");

        // Read choice from user input
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Read Celsius input
                printf("Enter Celsius value: ");
                scanf("%f", &input);

                // Convert Celsius to Fahrenheit
                output = celsiusToFahrenheit(input);

                // Print output
                printf("%.2f Celsius = %.2f Fahrenheit\n\n", input, output);
                break;

            case 2:
                // Read Fahrenheit input
                printf("Enter Fahrenheit value: ");
                scanf("%f", &input);

                // Convert Fahrenheit to Celsius
                output = fahrenheitToCelsius(input);

                // Print output
                printf("%.2f Fahrenheit = %.2f Celsius\n\n", input, output);
                break;

            case 3:
                // Read Miles input
                printf("Enter Miles value: ");
                scanf("%f", &input);

                // Convert Miles to Kilometers
                output = milesToKilometers(input);

                // Print output
                printf("%.2f Miles = %.2f Kilometers\n\n", input, output);
                break;

            case 4:
                // Read Kilometers input
                printf("Enter Kilometers value: ");
                scanf("%f", &input);

                // Convert Kilometers to Miles
                output = kilometersToMiles(input);

                // Print output
                printf("%.2f Kilometers = %.2f Miles\n\n", input, output);
                break;

            case 5:
                // Exit the program
                printf("Exiting Unit Converter. Bye !");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please choose a valid option.\n\n");
                break;
        }
    }

    return 0;
}