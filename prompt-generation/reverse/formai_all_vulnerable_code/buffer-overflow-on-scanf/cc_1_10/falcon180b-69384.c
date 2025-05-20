//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0/9.0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32;
}

int main() {
    char input[20];
    double temperature;
    int choice;

    printf("Enter temperature: ");
    scanf("%s", input);

    // Check if input is a valid number
    for (int i=0; i<strlen(input); i++) {
        if (!isdigit(input[i]) && input[i]!= '.' && input[i]!= '-') {
            printf("Invalid input. Please enter a valid number.\n");
            return 1;
        }
    }

    temperature = atof(input);

    // Ask user to choose conversion type
    printf("Choose conversion type:\n1. Fahrenheit to Celsius\n2. Celsius to Fahrenheit\n");
    scanf("%d", &choice);

    // Convert temperature and display result
    switch (choice) {
        case 1:
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 2:
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}