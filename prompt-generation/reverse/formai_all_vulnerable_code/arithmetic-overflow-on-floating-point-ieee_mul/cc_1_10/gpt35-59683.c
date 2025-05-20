//FormAI DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert length from meters to feet
float metersToFeet(float meters) {
    return meters * 3.28084;
}

// Function to convert length from feet to meters
float feetToMeters(float feet) {
    return feet * 0.3048;
}

int main() {
    int choice;
    float input, output;

    do {
        printf("What would you like to convert?\n");
        printf("1. Temperature\n");
        printf("2. Length\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                output = celsiusToFahrenheit(input);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", input, output);
                break;
            case 2:
                printf("Enter length in meters: ");
                scanf("%f", &input);
                output = metersToFeet(input);
                printf("%.2f meters is equal to %.2f feet.\n", input, output);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 3);

    return 0;
}