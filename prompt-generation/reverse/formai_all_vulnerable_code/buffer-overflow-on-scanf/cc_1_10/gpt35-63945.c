//FormAI DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>

double celsius_to_fahrenheit(double celsius) {
    return 9.0 / 5.0 * celsius + 32;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32) + 273.15;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvin_to_fahrenheit(double kelvin) {
    return 9.0 / 5.0 * (kelvin - 273.15) + 32;
}

int main() {
    double val;
    int choice;

    printf("\nChoose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter option number: ");
    scanf("%d", &choice);

    printf("\nEnter value to convert: ");
    scanf("%lf", &val);

    double result;

    switch (choice) {
        case 1:
            result = celsius_to_fahrenheit(val);
            printf("\n%.2lf Celsius = %.2lf Fahrenheit\n", val, result);
            break;
        case 2:
            result = celsius_to_kelvin(val);
            printf("\n%.2lf Celsius = %.2lf Kelvin\n", val, result);
            break;
        case 3:
            result = fahrenheit_to_celsius(val);
            printf("\n%.2lf Fahrenheit = %.2lf Celsius\n", val, result);
            break;
        case 4:
            result = fahrenheit_to_kelvin(val);
            printf("\n%.2lf Fahrenheit = %.2lf Kelvin\n", val, result);
            break;
        case 5:
            result = kelvin_to_celsius(val);
            printf("\n%.2lf Kelvin = %.2lf Celsius\n", val, result);
            break;
        case 6:
            result = kelvin_to_fahrenheit(val);
            printf("\n%.2lf Kelvin = %.2lf Fahrenheit\n", val, result);
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }

    return 0;
}