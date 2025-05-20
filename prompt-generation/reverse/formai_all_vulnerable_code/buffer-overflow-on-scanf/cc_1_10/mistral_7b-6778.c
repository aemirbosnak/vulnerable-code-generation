//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -50.0
#define MAX_TEMP 500.0

void fahrenheit_to_celsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
}

void celsius_to_fahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    double fahrenheit, celsius;
    int choice;

    printf("Welcome to the Temperature Unit Converter!\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &fahrenheit);
                if (fahrenheit < MIN_TEMP || fahrenheit > MAX_TEMP) {
                    printf("Invalid temperature! Temperature must be between -50 and 500 degrees Fahrenheit.\n");
                    break;
                }
                fahrenheit_to_celsius(fahrenheit);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &celsius);
                if (celsius < -273.15) {
                    printf("Invalid temperature! Temperature cannot be less than absolute zero.\n");
                    break;
                }
                celsius_to_fahrenheit(celsius);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}