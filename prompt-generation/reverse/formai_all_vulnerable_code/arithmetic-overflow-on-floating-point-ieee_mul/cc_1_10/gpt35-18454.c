//FormAI DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>

// this program converts units

// function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double degreeCelsius) {
    double degreeFahrenheit = (degreeCelsius * 1.8) + 32;
    return degreeFahrenheit;
}

// function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double degreeFahrenheit) {
    double degreeCelsius = (degreeFahrenheit - 32) / 1.8;
    return degreeCelsius;
}

// function to convert meters to feet
double metersToFeet(double meters) {
    double feet = meters * 3.281;
    return feet;
}

// function to convert feet to meters
double feetToMeters(double feet) {
    double meters = feet / 3.281;
    return meters;
}

int main() {
    int choice;
    double temp;
    double length;
    
    printf("Welcome to the Unit Conversion program!\n");
    printf("Please choose from the following:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temp);
            printf("%.1lf degrees Celsius is equal to %.1lf degrees Fahrenheit.\n", temp, celsiusToFahrenheit(temp));
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temp);
            printf("%.1lf degrees Fahrenheit is equal to %.1lf degrees Celsius.\n", temp, fahrenheitToCelsius(temp));
            break;
        case 3:
            printf("Enter the length in meters: ");
            scanf("%lf", &length);
            printf("%.1lf meters is equal to %.1lf feet.\n", length, metersToFeet(length));
            break;
        case 4:
            printf("Enter the length in feet: ");
            scanf("%lf", &length);
            printf("%.1lf feet is equal to %.1lf meters.\n", length, feetToMeters(length));
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    
    return 0;
}