//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>

#define MIN_VAL 0          // minimum value allowed by the converter
#define MAX_VAL 1000       // maximum value allowed by the converter

// function prototypes
double convert_celsius_to_fahrenheit(double celsius);
double convert_fahrenheit_to_celsius(double fahrenheit);
double convert_meters_to_feet(double meters);
double convert_feet_to_meters(double feet);

int main() {
    int selection;
    double value, result;

    // loop until the user enters '0' to exit the program
    while (1) {
        printf("\nUNIT CONVERTER\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Meters to Feet\n");
        printf("4. Feet to Meters\n");
        printf("5. Exit\n");
        printf("Enter your selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                printf("Enter Celsius value (%d - %d): ", MIN_VAL, MAX_VAL);
                scanf("%lf", &value);
                if (value < MIN_VAL || value > MAX_VAL) {
                    printf("Invalid input!\n");
                    break;
                }
                result = convert_celsius_to_fahrenheit(value);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, result);
                break;

            case 2:
                printf("Enter Fahrenheit value (%d - %d): ", MIN_VAL, MAX_VAL);
                scanf("%lf", &value);
                if (value < MIN_VAL || value > MAX_VAL) {
                    printf("Invalid input!\n");
                    break;
                }
                result = convert_fahrenheit_to_celsius(value);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, result);
                break;

            case 3:
                printf("Enter meters value (%d - %d): ", MIN_VAL, MAX_VAL);
                scanf("%lf", &value);
                if (value < MIN_VAL || value > MAX_VAL) {
                    printf("Invalid input!\n");
                    break;
                }
                result = convert_meters_to_feet(value);
                printf("%.2lf Meters = %.2lf Feet\n", value, result);
                break;

            case 4:
                printf("Enter feet value (%d - %d): ", MIN_VAL, MAX_VAL);
                scanf("%lf", &value);
                if (value < MIN_VAL || value > MAX_VAL) {
                    printf("Invalid input!\n");
                    break;
                }
                result = convert_feet_to_meters(value);
                printf("%.2lf Feet = %.2lf Meters\n", value, result);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid selection!\n");
                break;
        }
    }
}

// function to convert Celsius to Fahrenheit
double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// function to convert Fahrenheit to Celsius
double convert_fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// function to convert Meters to Feet
double convert_meters_to_feet(double meters) {
    return meters * 3.28084;
}

// function to convert Feet to Meters
double convert_feet_to_meters(double feet) {
    return feet / 3.28084;
}