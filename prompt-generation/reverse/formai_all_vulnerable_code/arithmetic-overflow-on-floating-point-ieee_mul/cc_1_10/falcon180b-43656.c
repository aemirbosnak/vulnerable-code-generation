//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);

int main() {
    double temperature, convertedTemperature;
    char choice;

    do {
        printf("Enter temperature: ");
        scanf("%lf", &temperature);

        printf("Choose conversion type:\n");
        printf("C) Celsius to Fahrenheit\n");
        printf("F) Fahrenheit to Celsius\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'C':
            case 'c':
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2lf Celsius is %.2lf Fahrenheit.\n", temperature, convertedTemperature);
                break;

            case 'F':
            case 'f':
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2lf Fahrenheit is %.2lf Celsius.\n", temperature, convertedTemperature);
                break;

            default:
                printf("Invalid choice.\n");
        }

        printf("\nDo you want to convert another temperature? (Y/N): ");
        scanf(" %c", &choice);
    } while(choice == 'Y' || choice == 'y');

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}