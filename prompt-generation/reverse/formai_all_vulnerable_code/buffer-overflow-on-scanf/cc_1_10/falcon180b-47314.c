//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to display menu
void display_menu() {
    printf("\n");
    printf("********* TEMPERATURE CONVERTER *********\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("\n");
}

// Function to get user input
double get_input(double min, double max, char *message) {
    double input;
    printf("%s: ", message);
    if (scanf("%lf", &input)!= 1 || input < min || input > max) {
        printf("Invalid input. Please try again.\n");
        exit(1);
    }
    return input;
}

int main() {
    double celsius, fahrenheit, input;
    char choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter Celsius temperature: ");
            celsius = get_input(0, 1000, "Celsius temperature");
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("%.2lf Celsius is %.2lf Fahrenheit.\n", celsius, fahrenheit);
            break;

        case '2':
            printf("Enter Fahrenheit temperature: ");
            fahrenheit = get_input(0, 1000, "Fahrenheit temperature");
            celsius = fahrenheit_to_celsius(fahrenheit);
            printf("%.2lf Fahrenheit is %.2lf Celsius.\n", fahrenheit, celsius);
            break;

        case '3':
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice!= '3');

    return 0;
}