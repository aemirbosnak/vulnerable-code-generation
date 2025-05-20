//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    do {
        printf("Enter a temperature value to convert:\n");
        scanf("%lf", &celsius);

        printf("Select the conversion option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Celsius to Kelvin\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Fahrenheit to Kelvin\n");
        printf("5. Kelvin to Celsius\n");
        printf("6. Kelvin to Fahrenheit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                fahrenheit = (celsius * 1.8) + 32;
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
                break;
            case '2':
                kelvin = celsius + 273.15;
                printf("%.2lf degrees Celsius is equal to %.2lf Kelvin.\n", celsius, kelvin);
                break;
            case '3':
                fahrenheit = (celsius * 1.8) - 32;
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
                break;
            case '4':
                kelvin = (celsius + 273.15) * 1.8 - 459.67;
                printf("%.2lf degrees Fahrenheit is equal to %.2lf Kelvin.\n", fahrenheit, kelvin);
                break;
            case '5':
                celsius = kelvin - 273.15;
                printf("%.2lf Kelvin is equal to %.2lf degrees Celsius.\n", kelvin, celsius);
                break;
            case '6':
                celsius = (fahrenheit - 32) / 1.8;
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Do you want to convert another temperature? (y/n)\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}