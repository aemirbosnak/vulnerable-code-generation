//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double temperature, result;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            result = (temperature * 9/5) + 32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", temperature, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            result = (temperature - 32) * 5/9;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", temperature, result);
            break;
        case 3:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &temperature);
            result = temperature - 273.15;
            printf("%.2lf Kelvin is equal to %.2lf Celsius\n", temperature, result);
            break;
        case 4:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            result = temperature + 273.15;
            printf("%.2lf Celsius is equal to %.2lf Kelvin\n", temperature, result);
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}