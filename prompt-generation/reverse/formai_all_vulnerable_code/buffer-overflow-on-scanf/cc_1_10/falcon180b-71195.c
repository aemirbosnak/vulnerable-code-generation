//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char input[100];
    double temperature, converted;
    char unit[10];
    int valid = 0;

    while (valid == 0) {
        printf("Enter temperature and unit (e.g. 25C): ");
        scanf("%s", input);

        // Check if input is in correct format
        if (strlen(input)!= 3) {
            printf("Invalid input. Please enter temperature and unit in the format XXC.\n");
        } else {
            strcpy(unit, input + strlen(input) - 1);
            temperature = atof(input);

            // Check if unit is valid
            if (unit[0]!= 'C' && unit[0]!= 'c' && unit[0]!= 'K' && unit[0]!= 'k') {
                printf("Invalid unit. Please enter temperature and unit in the format XXC or XXK.\n");
            } else {
                valid = 1;
            }
        }
    }

    // Convert Celsius to Fahrenheit
    converted = (temperature * 9.0 / 5.0) + 32;
    printf("%.2fC is %.2fF\n", temperature, converted);

    // Convert Celsius to Kelvin
    converted = temperature + 273.15;
    printf("%.2fC is %.2fK\n", temperature, converted);

    // Convert Fahrenheit to Celsius
    converted = (temperature - 32) * 5.0 / 9.0;
    printf("%.2fF is %.2fC\n", temperature, converted);

    // Convert Fahrenheit to Kelvin
    converted = (temperature + 459.67) * 5.0 / 9.0;
    printf("%.2fF is %.2fK\n", temperature, converted);

    // Convert Kelvin to Celsius
    converted = temperature - 273.15;
    printf("%.2fK is %.2fC\n", temperature, converted);

    // Convert Kelvin to Fahrenheit
    converted = (temperature * 9.0 / 5.0) - 459.67;
    printf("%.2fK is %.2fF\n", temperature, converted);

    return 0;
}