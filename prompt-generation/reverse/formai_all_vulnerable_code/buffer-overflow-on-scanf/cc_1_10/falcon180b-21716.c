//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to validate user input
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
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to display menu and get user input
void display_menu() {
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    char choice;
    float temperature;
    char input[10];
    int valid_input = 0;

    do {
        display_menu();
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%s", input);
                valid_input = validate_input(input);
                if (valid_input == 1) {
                    temperature = atof(input);
                    printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%s", input);
                valid_input = validate_input(input);
                if (valid_input == 1) {
                    temperature = atof(input);
                    printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}