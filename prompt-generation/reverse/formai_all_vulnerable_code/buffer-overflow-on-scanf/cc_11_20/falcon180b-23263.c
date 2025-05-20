//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double value, result;
    int choice;

    printf("Welcome to the Unit Converter!\n\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert from (1. Length, 2. Weight, 3. Temperature): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Length
            printf("Please enter the unit you want to convert from (1. Meter, 2. Centimeter, 3. Millimeter, 4. Kilometer): ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    result = value * 1;
                    printf("The converted value is: %.2lf Meter\n", result);
                    break;
                case 2:
                    result = value / 100;
                    printf("The converted value is: %.2lf Centimeter\n", result);
                    break;
                case 3:
                    result = value / 1000;
                    printf("The converted value is: %.2lf Millimeter\n", result);
                    break;
                case 4:
                    result = value / 1000000;
                    printf("The converted value is: %.2lf Kilometer\n", result);
                    break;
            }
            break;
        case 2: // Weight
            printf("Please enter the unit you want to convert from (1. Kilogram, 2. Gram, 3. Milligram): ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    result = value * 1;
                    printf("The converted value is: %.2lf Kilogram\n", result);
                    break;
                case 2:
                    result = value / 1000;
                    printf("The converted value is: %.2lf Gram\n", result);
                    break;
                case 3:
                    result = value / 1000000;
                    printf("The converted value is: %.2lf Milligram\n", result);
                    break;
            }
            break;
        case 3: // Temperature
            printf("Please enter the unit you want to convert from (1. Celsius, 2. Fahrenheit, 3. Kelvin): ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    result = value + 273.15;
                    printf("The converted value is: %.2lf Kelvin\n", result);
                    break;
                case 2:
                    result = (value - 32) * 5/9;
                    printf("The converted value is: %.2lf Celsius\n", result);
                    break;
                case 3:
                    result = (value + 459.67) * 5/9;
                    printf("The converted value is: %.2lf Fahrenheit\n", result);
                    break;
            }
            break;
    }

    return 0;
}