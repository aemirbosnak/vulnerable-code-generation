//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    int choice;
    char input[100];
    char unit[10];
    double value;
    do {
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
                scanf("%lf", &value);
                value = value * 1.8 + 32;
                printf("%lf Celsius is equal to %lf Fahrenheit\n", value, value);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &value);
                value = (value - 32) / 1.8;
                printf("%lf Fahrenheit is equal to %lf Celsius\n", value, value);
                break;
            case 3:
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &value);
                value = value - 273.15;
                printf("%lf Kelvin is equal to %lf Celsius\n", value, value);
                break;
            case 4:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &value);
                value = value + 273.15;
                printf("%lf Celsius is equal to %lf Kelvin\n", value, value);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &unit);
    } while (tolower(unit) == 'y');
    return 0;
}