//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to validate input
int validate_input(char *input) {
    int i = 0;
    while (input[i]!= '\0') {
        if (!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to print menu
void print_menu() {
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    char input[100];
    int choice;
    float temperature;

    do {
        printf("Enter your choice: ");
        scanf("%s", input);
        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                if (validate_input(input)) {
                    temperature = atof(input);
                    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                if (validate_input(input)) {
                    temperature = atof(input);
                    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, fahrenheit_to_celsius(temperature));
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}