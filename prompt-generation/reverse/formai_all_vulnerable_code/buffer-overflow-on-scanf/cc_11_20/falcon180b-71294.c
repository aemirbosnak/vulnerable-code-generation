//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    float temperature, converted;

    // Display menu
    printf("Welcome to the Temperature Converter!\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");

    // Get user choice
    scanf("%d", &choice);

    // Get temperature input
    switch (choice) {
        case 1:
        case 4:
        case 5:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            break;
        case 2:
        case 3:
        case 6:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    // Convert temperature
    switch (choice) {
        case 1:
            converted = (temperature * 9.0 / 5.0) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, converted);
            break;
        case 2:
            converted = (temperature - 32) * 5.0 / 9.0;
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, converted);
            break;
        case 3:
            converted = temperature + 273.15;
            printf("%.2f Celsius = %.2f Kelvin\n", temperature, converted);
            break;
        case 4:
            converted = temperature - 273.15;
            printf("%.2f Kelvin = %.2f Celsius\n", temperature, converted);
            break;
        case 5:
            converted = (temperature * 9.0 / 5.0) + 459.67;
            printf("%.2f Celsius = %.2f Kelvin\n", temperature, converted);
            break;
        case 6:
            converted = (temperature + 459.67) * 5.0 / 9.0;
            printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, converted);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}