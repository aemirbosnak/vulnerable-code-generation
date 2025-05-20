//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to validate input as a number
int is_number(const char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to get user input as a number
double get_number_input(const char *prompt) {
    char input[MAX_LINE_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_LINE_LENGTH, stdin);
    double value = 0;
    if (is_number(input)) {
        value = atof(input);
    } else {
        printf("Invalid input, please enter a number.\n");
        exit(1);
    }
    return value;
}

int main() {
    char choice;
    do {
        printf("Celsius to Fahrenheit Temperature Converter\n");
        printf("Enter 'C' to convert Celsius to Fahrenheit\n");
        printf("Enter 'F' to convert Fahrenheit to Celsius\n");
        printf("Enter 'Q' to quit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'C': {
                double celsius = get_number_input("Enter temperature in Celsius: ");
                double fahrenheit = celsius_to_fahrenheit(celsius);
                printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
                break;
            }
            case 'F': {
                double fahrenheit = get_number_input("Enter temperature in Fahrenheit: ");
                double celsius = fahrenheit_to_celsius(fahrenheit);
                printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
                break;
            }
            case 'Q': {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    } while (choice!= 'Q');
    return 0;
}