//FormAI DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Kilometers to Miles
double kmToMiles(double km) {
    return km * 0.621371;
}

// Function to convert Miles to Kilometers
double milesToKm(double miles) {
    return miles / 0.621371;
}

int main() {
    int choice;
    double value;

    printf("Welcome to Unit Converter\n");
    printf("-------------------------\n");
    printf("Choose an option to convert:\n");
    printf("1) Celsius to Fahrenheit\n");
    printf("2) Fahrenheit to Celsius\n");
    printf("3) Kilometers to Miles\n");
    printf("4) Miles to Kilometers\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a temperature in Celsius: ");
            scanf("%lf", &value);
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, celsiusToFahrenheit(value));
            break;
        case 2:
            printf("Enter a temperature in Fahrenheit: ");
            scanf("%lf", &value);
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, fahrenheitToCelsius(value));
            break;
        case 3:
            printf("Enter a distance in Kilometers: ");
            scanf("%lf", &value);
            printf("%.2f Kilometers = %.2f Miles\n", value, kmToMiles(value));
            break;
        case 4:
            printf("Enter a distance in Miles: ");
            scanf("%lf", &value);
            printf("%.2f Miles = %.2f Kilometers\n", value, milesToKm(value));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}