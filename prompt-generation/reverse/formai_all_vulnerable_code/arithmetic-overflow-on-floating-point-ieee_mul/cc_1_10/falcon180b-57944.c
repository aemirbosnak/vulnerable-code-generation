//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double temperature, converted;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select a conversion method:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            converted = (temperature * 1.8) + 32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", temperature, converted);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            converted = (temperature - 32) / 1.8;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", temperature, converted);
            break;

        case 3:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &temperature);
            converted = temperature - 273.15;
            printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", temperature, converted);
            break;

        case 4:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            converted = temperature + 273.15;
            printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", temperature, converted);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}