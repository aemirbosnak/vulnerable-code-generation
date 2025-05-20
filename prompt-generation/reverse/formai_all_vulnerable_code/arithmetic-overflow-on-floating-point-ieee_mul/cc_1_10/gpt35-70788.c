//FormAI DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>

// Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Convert Meters to Feet
double metersToFeet(double meters) {
    return meters * 3.281;
}

// Convert Feet to Meters
double feetToMeters(double feet) {
    return feet / 3.281;
}

// Convert Kilometers to Miles
double kilometersToMiles(double kilometers) {
    return kilometers / 1.609;
}

// Convert Miles to Kilometers
double milesToKilometers(double miles) {
    return miles * 1.609;
}

int main() {
    double value;
    int choice = 0;
    while (choice != 6) {
        printf("Choose an option:\n");
        printf("1: Convert Celsius to Fahrenheit\n");
        printf("2: Convert Fahrenheit to Celsius\n");
        printf("3: Convert Meters to Feet\n");
        printf("4: Convert Feet to Meters\n");
        printf("5: Convert Kilometers to Miles\n");
        printf("6: Convert Miles to Kilometers\n");
        printf("7: Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Celsius value: ");
                scanf("%lf", &value);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, celsiusToFahrenheit(value));
                break;
            case 2:
                printf("Enter Fahrenheit value: ");
                scanf("%lf", &value);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, fahrenheitToCelsius(value));
                break;
            case 3:
                printf("Enter Meters value: ");
                scanf("%lf", &value);
                printf("%.2lf Meters = %.2lf Feet\n", value, metersToFeet(value));
                break;
            case 4:
                printf("Enter Feet value: ");
                scanf("%lf", &value);
                printf("%.2lf Feet = %.2lf Meters\n", value, feetToMeters(value));
                break;
            case 5:
                printf("Enter Kilometers value: ");
                scanf("%lf", &value);
                printf("%.2lf Kilometers = %.2lf Miles\n", value, kilometersToMiles(value));
                break;
            case 6:
                printf("Enter Miles value: ");
                scanf("%lf", &value);
                printf("%.2lf Miles = %.2lf Kilometers\n", value, milesToKilometers(value));
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}