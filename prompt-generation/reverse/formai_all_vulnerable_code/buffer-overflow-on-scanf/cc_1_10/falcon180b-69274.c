//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void menu();
double fahrenheit_to_celsius(double fahrenheit);
double celsius_to_fahrenheit(double celsius);

int main() {
    char choice;
    double temperature;

    do {
        // Display menu
        menu();

        // Get user choice
        scanf(" %c", &choice);

        // Convert user input to uppercase
        choice = toupper(choice);

        // Get temperature from user
        if (choice == 'F' || choice == 'C') {
            printf("Enter temperature: ");
            scanf("%lf", &temperature);

            // Convert temperature based on user choice
            if (choice == 'F') {
                printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            } else if (choice == 'C') {
                printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            }
        } else {
            printf("Invalid choice.\n");
        }

    } while (choice!= 'Q');

    return 0;
}

void menu() {
    printf("\n");
    printf("Temperature Converter\n");
    printf("----------------------\n");
    printf("F - Fahrenheit to Celsius\n");
    printf("C - Celsius to Fahrenheit\n");
    printf("Q - Quit\n");
    printf("\n");
}

double fahrenheit_to_celsius(double fahrenheit) {
    double celsius;

    celsius = (fahrenheit - 32) * 5 / 9;

    return celsius;
}

double celsius_to_fahrenheit(double celsius) {
    double fahrenheit;

    fahrenheit = celsius * 9 / 5 + 32;

    return fahrenheit;
}