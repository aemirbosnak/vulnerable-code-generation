//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double temperature;

    printf("Welcome to the Temperature Converter!\n");
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
            temperature = (temperature * 9/5) + 32;
            printf("Temperature in Fahrenheit: %.2lf\n", temperature);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            temperature = (temperature - 32) * 5/9;
            printf("Temperature in Celsius: %.2lf\n", temperature);
            break;
        case 3:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &temperature);
            temperature = temperature - 273.15;
            printf("Temperature in Celsius: %.2lf\n", temperature);
            break;
        case 4:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            temperature = temperature + 273.15;
            printf("Temperature in Kelvin: %.2lf\n", temperature);
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}