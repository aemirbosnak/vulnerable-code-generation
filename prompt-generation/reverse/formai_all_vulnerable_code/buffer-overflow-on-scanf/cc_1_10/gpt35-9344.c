//FormAI DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>

// Function prototypes
double convert_to_celsius(double fahrenheit);
double convert_to_fahrenheit(double celsius);

int main() {
    int option;
    double temperature;

    do {
        // User menu
        printf("\n1. Convert Fahrenheit to Celsius\n");
        printf("2. Convert Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                // Fahrenheit to Celsius conversion
                printf("Enter a temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lf°F is equivalent to %.2lf°C\n", temperature, convert_to_celsius(temperature));
                break;

            case 2:
                // Celsius to Fahrenheit conversion
                printf("Enter a temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf°C is equivalent to %.2lf°F\n", temperature, convert_to_fahrenheit(temperature));
                break;

            case 3:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid option. Please enter a valid option (1, 2 or 3)\n");
        }
    } while(option != 3);

    return 0;
}

// Convert Fahrenheit to Celsius
double convert_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Convert Celsius to Fahrenheit
double convert_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}