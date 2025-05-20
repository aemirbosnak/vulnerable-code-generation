//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

int main() {
    int choice, input;
    double conversionValue;

    // Welcome message and menu
    printf("Welcome to the Temperature Converter!\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &input);
                conversionValue = fahrenheitToCelsius(input);
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", input, conversionValue);
                break;

            case 2:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &input);
                conversionValue = celsiusToFahrenheit(input);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", input, conversionValue);
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}