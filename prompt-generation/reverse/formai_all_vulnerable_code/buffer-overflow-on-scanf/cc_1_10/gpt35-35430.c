//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to display the available conversion options
void displayOptions() {
    printf("Choose an option:\n");
    printf(" 1. Celsius to Fahrenheit\n");
    printf(" 2. Fahrenheit to Celsius\n");
    printf(" 3. Exit\n");
}

int main() {
    int option;         // User's choice
    double tempIn, tempOut;

    // Display the available conversion options
    displayOptions();

    // Prompt the user for their choice
    printf("\nEnter your choice (1-3): ");
    scanf("%d", &option);

    // Process the user's choice
    switch(option) {
        case 1:
            // Celsius to Fahrenheit conversion
            printf("\nEnter temperature in Celsius: ");
            scanf("%lf", &tempIn);

            // Convert Celsius to Fahrenheit using the celsiusToFahrenheit() function
            tempOut = celsiusToFahrenheit(tempIn);

            // Display the result
            printf("\n%.2lf Celsius = %.2lf Fahrenheit\n", tempIn, tempOut);
            break;

        case 2:
            // Fahrenheit to Celsius conversion
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%lf", &tempIn);

            // Convert Fahrenheit to Celsius using the fahrenheitToCelsius() function
            tempOut = fahrenheitToCelsius(tempIn);

            // Display the result
            printf("\n%.2lf Fahrenheit = %.2lf Celsius\n", tempIn, tempOut);
            break;

        case 3:
            // Exit the program
            exit(0);
            break;

        default:
            // Invalid choice
            printf("\nInvalid choice. Please choose again.\n");
            break;
    }

    // Exit the program
    return 0;
}