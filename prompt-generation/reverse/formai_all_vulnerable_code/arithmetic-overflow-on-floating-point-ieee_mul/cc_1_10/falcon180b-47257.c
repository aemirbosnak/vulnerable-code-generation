//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double temperature;
    char unit;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert: ");
    scanf("%lf", &temperature);

    printf("Please enter the unit of the temperature (C/F/K): ");
    scanf(" %c", &unit);

    switch (unit) {
        case 'C':
            printf("The temperature is %.2lf degrees Celsius.\n", temperature);
            break;
        case 'F':
            temperature = (temperature * 9/5) + 32;
            printf("The temperature is %.2lf degrees Fahrenheit.\n", temperature);
            break;
        case 'K':
            temperature += 273.15;
            printf("The temperature is %.2lf degrees Kelvin.\n", temperature);
            break;
        default:
            printf("Invalid unit entered.\n");
            exit(1);
    }

    printf("Do you want to convert another temperature? (Y/N): ");
    scanf(" %c", &choice);

    while (choice == 'Y' || choice == 'y') {
        printf("Please enter the temperature you want to convert: ");
        scanf("%lf", &temperature);

        printf("Please enter the unit of the temperature (C/F/K): ");
        scanf(" %c", &unit);

        switch (unit) {
            case 'C':
                printf("The temperature is %.2lf degrees Celsius.\n", temperature);
                break;
            case 'F':
                temperature = (temperature * 9/5) + 32;
                printf("The temperature is %.2lf degrees Fahrenheit.\n", temperature);
                break;
            case 'K':
                temperature += 273.15;
                printf("The temperature is %.2lf degrees Kelvin.\n", temperature);
                break;
            default:
                printf("Invalid unit entered.\n");
                exit(1);
        }

        printf("Do you want to convert another temperature? (Y/N): ");
        scanf(" %c", &choice);
    }

    return 0;
}