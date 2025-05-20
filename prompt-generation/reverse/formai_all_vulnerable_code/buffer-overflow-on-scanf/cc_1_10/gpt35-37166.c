//FormAI DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Function to convert Kilometers per Hour to Miles per Hour
double kphToMph(double kph) {
    double mph = kph / 1.609;
    return mph;
}

// Function to convert Miles per Hour to Kilometers per Hour
double mphToKph(double mph) {
    double kph = mph * 1.609;
    return kph;
}

// Function to convert Kilograms to Pounds
double kgToLbs(double kg) {
    double lbs = kg * 2.205;
    return lbs;
}

// Function to convert Pounds to Kilograms
double lbsToKg(double lbs) {
    double kg = lbs / 2.205;
    return kg;
}

int main() {
    int choice;
    double input, output;

    printf("Welcome to the Statistical Unit Converter!\n");
    printf("-------------------------------------------\n");

    while (1) {
        printf("\nChoose an option below:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers per Hour to Miles per Hour\n");
        printf("4. Miles per Hour to Kilometers per Hour\n");
        printf("5. Kilograms to Pounds\n");
        printf("6. Pounds to Kilograms\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("\nThank you for using the Statistical Unit Converter!\n");
            exit(0);
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &input);

        switch (choice) {
            case 1:
                output = celsiusToFahrenheit(input);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", input, output);
                break;
            case 2:
                output = fahrenheitToCelsius(input);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", input, output);
                break;
            case 3:
                output = kphToMph(input);
                printf("%.2lf KPH = %.2lf MPH\n", input, output);
                break;
            case 4:
                output = mphToKph(input);
                printf("%.2lf MPH = %.2lf KPH\n", input, output);
                break;
            case 5:
                output = kgToLbs(input);
                printf("%.2lf Kilograms = %.2lf Pounds\n", input, output);
                break;
            case 6:
                output = lbsToKg(input);
                printf("%.2lf Pounds = %.2lf Kilograms\n", input, output);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}