//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Curious Unit Converter!\n");
    printf("========================================\n");

    // Define the conversion factors
    double meters_to_feet = 3.28084;
    double feet_to_meters = 0.3048;
    double kilograms_to_pounds = 2.20462;
    double pounds_to_kilograms = 0.453592;
    double celsius_to_fahrenheit = 1.8;
    double fahrenheit_to_celsius = 0.555556;

    // Get the user's input
    int choice;
    printf("What would you like to convert?\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the conversion
    double value;
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    switch (choice) {
        case 1:
            printf("%lf meters is equal to %lf feet.\n", value, value * meters_to_feet);
            break;
        case 2:
            printf("%lf feet is equal to %lf meters.\n", value, value * feet_to_meters);
            break;
        case 3:
            printf("%lf kilograms is equal to %lf pounds.\n", value, value * kilograms_to_pounds);
            break;
        case 4:
            printf("%lf pounds is equal to %lf kilograms.\n", value, value * pounds_to_kilograms);
            break;
        case 5:
            printf("%lf Celsius is equal to %lf Fahrenheit.\n", value, value * celsius_to_fahrenheit);
            break;
        case 6:
            printf("%lf Fahrenheit is equal to %lf Celsius.\n", value, value * fahrenheit_to_celsius);
            break;
        default:
            printf("Invalid choice.\n");
    }

    // Say goodbye to the user
    printf("Thank you for using the Curious Unit Converter!\n");
    printf("========================================\n");

    return 0;
}