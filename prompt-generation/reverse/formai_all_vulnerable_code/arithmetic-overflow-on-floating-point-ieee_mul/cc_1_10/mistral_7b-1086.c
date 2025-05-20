//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

// Menu function to display conversion options
void temperature_conversion_menu() {
    printf("\nTemperature Conversion Menu\n");
    printf("----------------------------\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

int main() {
    double temperature, conversion_factor;
    int choice;

    while (1) {
        temperature_conversion_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);

            conversion_factor = fahrenheit_to_celsius(temperature);
            printf("The temperature in Celsius is: %.2f\n", conversion_factor);
        } else if (choice == 2) {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);

            conversion_factor = celsius_to_fahrenheit(temperature);
            printf("The temperature in Fahrenheit is: %.2f\n", conversion_factor);
        } else if (choice == 3) {
            printf("Exiting temperature conversion program...\n");
            exit(0);
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}