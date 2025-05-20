//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the unit conversion factors
#define LENGTH_FACTOR 0.3048
#define WEIGHT_FACTOR 0.453592
#define VOLUME_FACTOR 35.3147
#define TEMPERATURE_FACTOR 5.0/9.0

int main() {
    char input[50];
    char unit[10];
    char output_unit[10];
    double value, result;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select the category of conversion:\n");
    printf("1. Length\n2. Weight\n3. Volume\n4. Temperature\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Please enter the value to convert:\n");
            scanf("%lf", &value);
            printf("Please enter the unit of the value (e.g. meters, inches):\n");
            scanf("%s", unit);
            printf("Please enter the output unit (e.g. feet, centimeters):\n");
            scanf("%s", output_unit);
            result = value * LENGTH_FACTOR;
            printf("%.2lf %s = %.2lf %s\n", value, unit, result, output_unit);
            break;
        case 2:
            printf("Please enter the value to convert:\n");
            scanf("%lf", &value);
            printf("Please enter the unit of the value (e.g. kilograms, pounds):\n");
            scanf("%s", unit);
            printf("Please enter the output unit (e.g. ounces, grams):\n");
            scanf("%s", output_unit);
            result = value * WEIGHT_FACTOR;
            printf("%.2lf %s = %.2lf %s\n", value, unit, result, output_unit);
            break;
        case 3:
            printf("Please enter the value to convert:\n");
            scanf("%lf", &value);
            printf("Please enter the unit of the value (e.g. liters, gallons):\n");
            scanf("%s", unit);
            printf("Please enter the output unit (e.g. fluid ounces, milliliters):\n");
            scanf("%s", output_unit);
            result = value * VOLUME_FACTOR;
            printf("%.2lf %s = %.2lf %s\n", value, unit, result, output_unit);
            break;
        case 4:
            printf("Please enter the value to convert:\n");
            scanf("%lf", &value);
            printf("Please enter the unit of the value (e.g. Celsius, Fahrenheit):\n");
            scanf("%s", unit);
            printf("Please enter the output unit (e.g. Fahrenheit, Celsius):\n");
            scanf("%s", output_unit);
            result = (value * TEMPERATURE_FACTOR) + 32;
            printf("%.2lf %s = %.2lf %s\n", value, unit, result, output_unit);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}