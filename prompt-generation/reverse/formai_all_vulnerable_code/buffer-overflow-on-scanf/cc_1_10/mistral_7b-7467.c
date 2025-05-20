//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -320.0
#define MAX_TEMP 1250.0
#define INVALID_INPUT -1

void convert_fahrenheit_to_celsius(double fahrenheit);
void convert_celsius_to_fahrenheit(double celsius);

int main() {
    double temperature, input;
    char choice;

    printf("Welcome to Temperature Converter!\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        if (choice == '1') {
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temperature);

            if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                printf("Invalid temperature input!\n");
                continue;
            }

            convert_fahrenheit_to_celsius(temperature);
            continue;
        } else if (choice == '2') {
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temperature);

            if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                printf("Invalid temperature input!\n");
                continue;
            }

            convert_celsius_to_fahrenheit(temperature);
            continue;
        } else if (choice == '3') {
            printf("Exiting the program...\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("\nPress any key to continue...");
        getchar();
    }

    return 0;
}

void convert_fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
}

void convert_celsius_to_fahrenheit(double celsius) {
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
}