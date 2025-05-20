//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -50.0
#define MAX_TEMP 500.0
#define F_TO_C_FACTOR 1.8
#define C_TO_F_FACTOR 1.8
#define C_TO_F_OFFSET 32.0

void print_menu() {
    printf("---- Temperature Converter ----\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

void fahrenheit_to_celsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32.0) * F_TO_C_FACTOR;
    printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", fahrenheit, celsius);
}

void celsius_to_fahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = (celsius * C_TO_F_FACTOR) + C_TO_F_OFFSET;
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", celsius, fahrenheit);
}

int main() {
    double temperature, input;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                    printf("Invalid temperature. Please try again.\n");
                    continue;
                }
                fahrenheit_to_celsius(temperature);
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                    printf("Invalid temperature. Please try again.\n");
                    continue;
                }
                celsius_to_fahrenheit(temperature);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}