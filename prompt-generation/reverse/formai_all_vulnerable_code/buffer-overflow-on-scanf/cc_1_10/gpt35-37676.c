//FormAI DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert Miles to Kilometers
double milesToKilometers(double miles){
    return miles * 1.60934;
}

// Function to convert Inches to Centimeters
double inchesToCentimeters(double inches){
    return inches * 2.54;
}

// Function to convert Pounds to Kilograms
double poundsToKilograms(double pounds){
    return pounds * 0.453592;
}

int main() {
    char choice[10];
    double value, convertedValue;

    printf("Welcome to the Mind-Bending Converter!\n");
    printf("What would you like to convert?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Pounds to Kilograms\n");

    // Loop to handle user input and perform conversions
    while (1) {
        printf("\nEnter your choice (1-4): ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printf("Please enter the temperature in Celsius: ");
            scanf("%lf", &value);
            convertedValue = celsiusToFahrenheit(value);
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", value, convertedValue);
        } else if (strcmp(choice, "2") == 0) {
            printf("Please enter the distance in miles: ");
            scanf("%lf", &value);
            convertedValue = milesToKilometers(value);
            printf("%.2lf miles is equal to %.2lf kilometers\n", value, convertedValue);
        } else if (strcmp(choice, "3") == 0) {
            printf("Please enter the length in inches: ");
            scanf("%lf", &value);
            convertedValue = inchesToCentimeters(value);
            printf("%.2lf inches is equal to %.2lf centimeters\n", value, convertedValue);
        } else if (strcmp(choice, "4") == 0) {
            printf("Please enter the weight in pounds: ");
            scanf("%lf", &value);
            convertedValue = poundsToKilograms(value);
            printf("%.2lf pounds is equal to %.2lf kilograms\n", value, convertedValue);
        } else { // Handle invalid input
            printf("Invalid input. Please try again.\n");
        }

        // Check if user wants to continue or exit
        char cont[5];
        printf("Would you like to convert something else? (yes/no): ");
        scanf("%s", cont);

        if (strcmp(cont, "no") == 0) {
            break;
        }
    }

    printf("\nThank you for using the Mind-Bending Converter! Goodbye.\n");

    return 0;
}