//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * (9.0/5.0)) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * (5.0/9.0);
}

// Function to convert Inches to Centimeters
double inchesToCentimeters(double inches) {
    return inches * 2.54;
}

// Function to convert Centimeters to Inches
double centimetersToInches(double centimeters) {
    return centimeters / 2.54;
}

// Function to convert Pounds to Kilograms
double poundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

// Function to convert Kilograms to Pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

int main() {
    int option;
    double input;
    
    printf("Welcome to the Unit Converter program!\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Centimeters to Inches\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &input);
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", input, celsiusToFahrenheit(input));
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &input);
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", input, fahrenheitToCelsius(input));
            break;
        case 3:
            printf("Enter the length in Inches: ");
            scanf("%lf", &input);
            printf("%.2lf Inches is equal to %.2lf Centimeters.\n", input, inchesToCentimeters(input));
            break;
        case 4:
            printf("Enter the length in Centimeters: ");
            scanf("%lf", &input);
            printf("%.2lf Centimeters is equal to %.2lf Inches.\n", input, centimetersToInches(input));
            break;
        case 5:
            printf("Enter the weight in Pounds: ");
            scanf("%lf", &input);
            printf("%.2lf Pounds is equal to %.2lf Kilograms.\n", input, poundsToKilograms(input));
            break;
        case 6:
            printf("Enter the weight in Kilograms: ");
            scanf("%lf", &input);
            printf("%.2lf Kilograms is equal to %.2lf Pounds.\n", input, kilogramsToPounds(input));
            break;
        default:
            printf("Invalid choice. Please enter a number between 1-6.\n");
            break;
    }
    
    return 0;
}