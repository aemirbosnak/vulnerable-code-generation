//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -50.0
#define MAX_TEMP 500.0

void fahrenheit_to_celsius(double fahrenheit);
void celsius_to_fahrenheit(double celsius);
void print_menu();

int main() {
    double temperature;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                fahrenheit_to_celsius(temperature);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                celsius_to_fahrenheit(temperature);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;

    if (celsius < MIN_TEMP || celsius > MAX_TEMP) {
        printf("Invalid temperature! Temperature should be between -50 and 500 degrees Celsius.\n");
        return;
    }

    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
}

void celsius_to_fahrenheit(double celsius) {
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    if (fahrenheit < MIN_TEMP || fahrenheit > MAX_TEMP) {
        printf("Invalid temperature! Temperature should be between -50 and 500 degrees Fahrenheit.\n");
        return;
    }

    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
}

void print_menu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}