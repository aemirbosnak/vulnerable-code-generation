//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int choice;
    double temperature;
    char unit[10];

    // Display menu
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get temperature and unit
    switch(choice) {
        case 1:
        case 4:
        case 7:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("Enter unit (C/K): ");
            scanf("%s", unit);
            break;
        case 2:
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("Enter unit (F/K): ");
            scanf("%s", unit);
            break;
        case 3:
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%lf", &temperature);
            printf("Enter unit (K/C/F): ");
            scanf("%s", unit);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Convert temperature
    switch(choice) {
        case 1:
            printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n",
                temperature, (temperature * 9/5) + 32);
            break;
        case 2:
            printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n",
                temperature, (temperature - 32) * 5/9);
            break;
        case 3:
            printf("%.2lf degrees Celsius is %.2lf Kelvin.\n",
                temperature, temperature + 273.15);
            break;
        case 4:
            printf("%.2lf Kelvin is %.2lf degrees Celsius.\n",
                temperature, temperature - 273.15);
            break;
        case 5:
            printf("%.2lf degrees Fahrenheit is %.2lf Kelvin.\n",
                temperature, (temperature + 459.67) * 5/9);
            break;
        case 6:
            printf("%.2lf Kelvin is %.2lf degrees Fahrenheit.\n",
                temperature, (temperature * 9/5) - 459.67);
            break;
        case 7:
            printf("Exiting...\n");
            break;
    }

    return 0;
}