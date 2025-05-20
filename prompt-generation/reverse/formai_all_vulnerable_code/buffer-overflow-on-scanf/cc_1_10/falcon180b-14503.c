//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;
    int validInput = 0;

    do {
        printf("Enter temperature value to convert: ");
        scanf("%lf", &celsius);

        if (celsius < -273.15) {
            printf("Invalid input. Temperature cannot be below absolute zero (-273.15°C).\n");
        } else {
            validInput = 1;
        }
    } while (!validInput);

    printf("Select conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");

    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            fahrenheit = (celsius * 9.0 / 5.0) + 32;
            printf("%.2lf°C is equal to %.2lf°F.\n", celsius, fahrenheit);
            break;
        case '2':
            kelvin = celsius + 273.15;
            printf("%.2lf°C is equal to %.2lfK.\n", celsius, kelvin);
            break;
        case '3':
            fahrenheit = (celsius * 9.0 / 5.0) + 32;
            printf("%.2lf°F is equal to %.2lf°C.\n", fahrenheit, celsius);
            break;
        case '4':
            celsius = (fahrenheit - 32) * 5.0 / 9.0;
            printf("%.2lf°F is equal to %.2lf°C.\n", fahrenheit, celsius);
            break;
        case '5':
            celsius = kelvin - 273.15;
            printf("%.2lfK is equal to %.2lf°C.\n", kelvin, celsius);
            break;
        case '6':
            fahrenheit = (kelvin * 9.0 / 5.0) - 459.67;
            printf("%.2lfK is equal to %.2lf°F.\n", kelvin, fahrenheit);
            break;
        default:
            printf("Invalid conversion type selected.\n");
    }

    return 0;
}