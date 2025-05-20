//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void display_menu();
void celsius_to_fahrenheit(double celsius);
void fahrenheit_to_celsius(double fahrenheit);

int main() {
    char choice;
    double temperature;

    do {
        display_menu();
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                celsius_to_fahrenheit(temperature);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                fahrenheit_to_celsius(temperature);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '3');

    return 0;
}

void display_menu() {
    printf("\n");
    printf("Temperature Converter\n");
    printf("----------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("\n");
}

void celsius_to_fahrenheit(double celsius) {
    double fahrenheit;

    fahrenheit = (celsius * 9.0) / 5.0 + 32.0;

    printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
}

void fahrenheit_to_celsius(double fahrenheit) {
    double celsius;

    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

    printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
}