//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

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

// Function to convert Kilometers to Miles
double kilometersToMiles(double kilometers) {
    double miles = kilometers / 1.609;
    return miles;
}

// Function to convert Miles to Kilometers
double milesToKilometers(double miles) {
    double kilometers = miles * 1.609;
    return kilometers;
}

int main() {
    int choice;
    double value;
    printf("Please select an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kilometers to Miles\n");
    printf("4. Convert Miles to Kilometers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &value);
            printf("%.2lf Celsius = %.2lf Fahrenheit", value, celsiusToFahrenheit(value));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &value);
            printf("%.2lf Fahrenheit = %.2lf Celsius", value, fahrenheitToCelsius(value));
            break;
        case 3:
            printf("Enter distance in Kilometers: ");
            scanf("%lf", &value);
            printf("%.2lf Kilometers = %.2lf Miles", value, kilometersToMiles(value));
            break;
        case 4:
            printf("Enter distance in Miles: ");
            scanf("%lf", &value);
            printf("%.2lf Miles = %.2lf Kilometers", value, milesToKilometers(value));
            break;
        default:
            printf("Invalid choice. Please enter a valid option.");
    }

    return 0;
}