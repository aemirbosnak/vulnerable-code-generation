//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

int main() {
    char choice;
    double temperature, conversion_factor;

    // Welcome message
    printf("--------------------------------------------------\n");
    printf("|             Temperature Converter             |\n");
    printf("|             Made with ❤ by GeekyPanda          |\n");
    printf("--------------------------------------------------\n\n");

    while (1) {
        printf("Enter 'F' to convert from Fahrenheit to Celsius,\n");
        printf("or 'C' to convert from Celsius to Fahrenheit: ");
        scanf(" %c", &choice);

        if (choice == 'F') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            conversion_factor = 1.0;
        } else if (choice == 'C') {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            conversion_factor = -1.0;
        } else {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        if (conversion_factor == -1.0) {
            temperature = fahrenheit_to_celsius(temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, temperature * 1.8 + 32.0);
        } else {
            temperature = celsius_to_fahrenheit(temperature);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, temperature - 32.0 * 0.55556);
        }
    }

    return 0;
}