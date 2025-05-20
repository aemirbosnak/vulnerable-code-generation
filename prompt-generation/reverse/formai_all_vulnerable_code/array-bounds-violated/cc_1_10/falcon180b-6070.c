//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if input is a valid number
int isNumber(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Main function
int main() {
    char input[100];
    double temperature;
    char unit[10];
    int choice;

    // Loop until user chooses to quit
    while (1) {
        printf("Enter temperature (e.g. 25C or 77F): ");
        scanf("%s", input);

        // Check if input is valid
        if (!isNumber(input)) {
            printf("Invalid input. Please enter a valid temperature.\n");
            continue;
        }

        // Extract temperature and unit from input
        temperature = atof(input);
        unit[0] = input[strlen(input)-1];
        input[strlen(input)-1] = '\0';

        // Convert temperature based on unit
        if (unit[0] == 'C' || unit[0] == 'c') {
            temperature = celsiusToFahrenheit(temperature);
            unit[0] = 'F';
            unit[1] = '\0';
        } else if (unit[0] == 'F' || unit[0] == 'f') {
            temperature = fahrenheitToCelsius(temperature);
            unit[0] = 'C';
            unit[1] = '\0';
        } else {
            printf("Invalid unit. Please enter a valid temperature.\n");
            continue;
        }

        // Display result
        printf("%.2f%s = %.2f%s\n", temperature, unit, temperature, unit);

        // Ask user if they want to continue
        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}