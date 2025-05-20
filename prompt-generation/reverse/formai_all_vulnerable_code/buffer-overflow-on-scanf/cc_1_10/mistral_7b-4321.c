//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_TEMP (-320.0)
#define MAX_TEMP (320.0)
#define EPSILON (0.001)

void print_title() {
    printf("-----------------------------------------\n");
    printf("|         TEMPERATURE CONVERTER         |\n");
    printf("|                                       |\n");
    printf("|  Donald Knuth Style C Program         |\n");
    printf("|                                       |\n");
    printf("-----------------------------------------\n\n");
}

void print_menu() {
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

void fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", fahrenheit, celsius);
}

void celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

double get_valid_temperature(const char* message) {
    double temperature;
    int is_valid = 0;

    while (!is_valid) {
        printf("%s", message);
        scanf("%lf", &temperature);

        if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
            printf("Invalid temperature! Temperature must be between %-.2f and %-.2f degrees.\n", MIN_TEMP, MAX_TEMP);
            continue;
        }

        is_valid = 1;
    }

    return temperature;
}

int main() {
    double temperature;
    int choice;

    print_title();

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperature = get_valid_temperature("Enter temperature in Fahrenheit: ");
                fahrenheit_to_celsius(temperature);
                break;
            case 2:
                temperature = get_valid_temperature("Enter temperature in Celsius: ");
                celsius_to_fahrenheit(temperature);
                break;
            case 3:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option! Please choose 1, 2, or 3.\n");
        }
    }

    return EXIT_SUCCESS;
}