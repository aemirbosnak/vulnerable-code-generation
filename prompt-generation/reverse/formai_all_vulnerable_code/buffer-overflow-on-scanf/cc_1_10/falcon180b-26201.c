//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    float temperature, converted;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please enter your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    scanf("%d", &choice);

    printf("Enter the temperature to convert: ");
    scanf("%f", &temperature);

    switch (choice) {
        case 1:
            converted = (temperature * 9/5) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, converted);
            break;
        case 2:
            converted = (temperature - 32) * 5/9;
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, converted);
            break;
        case 3:
            converted = temperature + 273.15;
            printf("%.2f Celsius is equal to %.2f Kelvin.\n", temperature, converted);
            break;
        case 4:
            converted = temperature - 273.15;
            printf("%.2f Kelvin is equal to %.2f Celsius.\n", temperature, converted);
            break;
        case 5:
            converted = (temperature + 459.67) * 5/9;
            printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", temperature, converted);
            break;
        case 6:
            converted = (temperature - 273.15) * 9/5 + 32;
            printf("%.2f Kelvin is equal to %.2f Fahrenheit.\n", temperature, converted);
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
    }

    return 0;
}