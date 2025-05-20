//FormAI DATASET v1.0 Category: Unit converter ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function for converting Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// function for converting Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// function for converting Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// function for converting Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// function for converting Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

// function for converting Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return kelvin * 9 / 5 - 459.67;
}

int main() {
    int choice;
    float temperature;
    char fromUnit[20], toUnit[20];

    printf("Welcome to the C Unit Converter\n");
    printf("********************************\n");

    while(1) {
        // prompt for input
        printf("Please select the unit to convert from:\n");
        printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Please enter a valid choice.\n");
            continue;
        }

        // get the temperature to convert
        printf("Enter the temperature to convert: ");
        scanf("%f", &temperature);

        // get the units to convert from and to
        printf("Enter the unit to convert from: ");
        scanf("%s", fromUnit);
        printf("Enter the unit to convert to: ");
        scanf("%s", toUnit);

        double result;
        if (strcmp(fromUnit, "Celsius") == 0 && strcmp(toUnit, "Fahrenheit") == 0) {
            result = celsiusToFahrenheit(temperature);
            printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, result);
        } else if (strcmp(fromUnit, "Fahrenheit") == 0 && strcmp(toUnit, "Celsius") == 0) {
            result = fahrenheitToCelsius(temperature);
            printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, result);
        } else if (strcmp(fromUnit, "Celsius") == 0 && strcmp(toUnit, "Kelvin") == 0) {
            result = celsiusToKelvin(temperature);
            printf("%.2f Celsius is %.2f Kelvin.\n", temperature, result);
        } else if (strcmp(fromUnit, "Kelvin") == 0 && strcmp(toUnit, "Celsius") == 0) {
            result = kelvinToCelsius(temperature);
            printf("%.2f Kelvin is %.2f Celsius.\n", temperature, result);
        } else if (strcmp(fromUnit, "Fahrenheit") == 0 && strcmp(toUnit, "Kelvin") == 0) {
            result = fahrenheitToKelvin(temperature);
            printf("%.2f Fahrenheit is %.2f Kelvin.\n", temperature, result);
        } else if (strcmp(fromUnit, "Kelvin") == 0 && strcmp(toUnit, "Fahrenheit") == 0) {
            result = kelvinToFahrenheit(temperature);
            printf("%.2f Kelvin is %.2f Fahrenheit.\n", temperature, result);
        } else {
            printf("Please enter a valid unit.\n");
            continue;
        }

        // ask if user wants to convert another temperature
        char answer[20];
        printf("Do you want to convert another temperature? (y/n): ");
        scanf("%s", answer);
        if (strcmp(answer, "y") != 0) {
            break;
        }
    }

    printf("Thank you for using the C Unit Converter.\n");
    return 0;
}