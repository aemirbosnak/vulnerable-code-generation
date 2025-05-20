//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");
    int choice, decimal_places;
    char unit[10];
    float temperature, converted_temperature;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert:\n");
    fflush(stdin);
    scanf("%f", &temperature);

    printf("Please enter the unit of the temperature (C or F):\n");
    fflush(stdin);
    scanf(" %s", unit);

    tolower(unit[0]);

    if (unit[0] == 'c') {
        converted_temperature = (temperature * 9/5) + 32;
        printf("The converted temperature in Fahrenheit is: %.2f\n", converted_temperature);
    } else if (unit[0] == 'f') {
        converted_temperature = (temperature - 32) * 5/9;
        printf("The converted temperature in Celsius is: %.2f\n", converted_temperature);
    } else {
        printf("Invalid unit. Please enter either C or F.\n");
        return 1;
    }

    printf("Would you like to convert another temperature? (Y/N):\n");
    fflush(stdin);
    scanf(" %c", &choice);

    while (tolower(choice) == 'y') {
        printf("Please enter the temperature you want to convert:\n");
        fflush(stdin);
        scanf("%f", &temperature);

        printf("Please enter the unit of the temperature (C or F):\n");
        fflush(stdin);
        scanf(" %s", unit);

        tolower(unit[0]);

        if (unit[0] == 'c') {
            converted_temperature = (temperature * 9/5) + 32;
            printf("The converted temperature in Fahrenheit is: %.2f\n", converted_temperature);
        } else if (unit[0] == 'f') {
            converted_temperature = (temperature - 32) * 5/9;
            printf("The converted temperature in Celsius is: %.2f\n", converted_temperature);
        } else {
            printf("Invalid unit. Please enter either C or F.\n");
            return 1;
        }

        printf("Would you like to convert another temperature? (Y/N):\n");
        fflush(stdin);
        scanf(" %c", &choice);
    }

    return 0;
}