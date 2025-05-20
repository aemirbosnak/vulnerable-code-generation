//FormAI DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void convertToF(float temp_celsius) {
    float temp_fahrenheit = (temp_celsius * 1.8) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", temp_celsius, temp_fahrenheit);
}

void convertToK(float temp_celsius) {
    float temp_kelvin = temp_celsius + 273.15;
    printf("%.2f Celsius = %.2f Kelvin\n", temp_celsius, temp_kelvin);
}

int main() {
    float temp_celsius;
    char choice;
    bool is_valid_input = false;

    while (!is_valid_input) {
        printf("Enter temperature in Celsius: ");
        if (scanf("%f", &temp_celsius) != 1) {
            printf("Invalid input, please try again.\n");
            while (getchar() != '\n'); // clear input buffer
        } else {
            is_valid_input = true;
        }
    }

    is_valid_input = false;

    printf("Choose an option for conversion:\n");
    printf("a) Celsius to Fahrenheit\n");
    printf("b) Celsius to Kelvin\n");

    while (!is_valid_input) {
        printf("Enter your choice (a/b): ");
        if (scanf(" %c", &choice) != 1 || (choice != 'a' && choice != 'b')) {
            printf("Invalid input, please try again.\n");
            while (getchar() != '\n'); // clear input buffer
        } else {
            is_valid_input = true;
        }
    }

    switch (tolower(choice)) {
        case 'a':
            convertToF(temp_celsius);
            break;
        case 'b':
            convertToK(temp_celsius);
            break;
        default:
            printf("Unknown option selected.\n");
            break;
    }

    return 0;
}