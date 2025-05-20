//FormAI DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>

//Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit;
    fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

//Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius;
    celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

//Function to convert Centimeters to Inches
float centimetersToInches(float centimeters) {
    float inches;
    inches = centimeters / 2.54;
    return inches;
}

//Function to convert Inches to Centimeters
float inchesToCentimeters(float inches) {
    float centimeters;
    centimeters = inches * 2.54;
    return centimeters;
}

int main() {
    int choice;
    float input;

    printf("Welcome to the Unit Converter program!\n");
    printf("Please select the conversion you would like to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Centimeters to Inches\n");
    printf("4. Inches to Centimeters\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Please enter the temperature in Celsius: ");
            scanf("%f", &input);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input, celsiusToFahrenheit(input));
            break;
        case 2:
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%f", &input);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input, fahrenheitToCelsius(input));
            break;
        case 3:
            printf("Please enter the length in Centimeters: ");
            scanf("%f", &input);
            printf("%.2f Centimeters is equal to %.2f Inches.\n", input, centimetersToInches(input));
            break;
        case 4:
            printf("Please enter the length in Inches: ");
            scanf("%f", &input);
            printf("%.2f Inches is equal to %.2f Centimeters.\n", input, inchesToCentimeters(input));
            break;
        default:
            printf("Invalid choice.");
            break;
    }

    return 0;
}