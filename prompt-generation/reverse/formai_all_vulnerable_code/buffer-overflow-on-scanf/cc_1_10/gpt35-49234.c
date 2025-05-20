//FormAI DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

int main() {
    // ask the user for the input unit
    char input_unit;
    printf("Enter the input unit (d for distance, v for volume, w for weight): ");
    scanf("%c", &input_unit);

    // ask the user for the output unit
    char output_unit;
    printf("Enter the output unit (d for distance, v for volume, w for weight): ");
    scanf(" %c", &output_unit);

    // ask the user for the value to convert
    float value;
    printf("Enter the value to convert: ");
    scanf("%f", &value);

    // convert the input unit to meters, liters, or kilograms
    float input_value;
    switch (input_unit) {
        case 'd':
            input_value = value * 0.3048; // feet to meters
            break;
        case 'v':
            input_value = value * 0.001; // milliliters to liters
            break;
        case 'w':
            input_value = value; // assume input is already in kilograms
            break;
        default:
            printf("Invalid input unit.\n");
            return 1; // exit with error code
    }

    // convert meters, liters, or kilograms to the output unit
    float output_value;
    switch (output_unit) {
        case 'd':
            output_value = input_value / 0.3048; // meters to feet
            break;
        case 'v':
            output_value = input_value / 0.001; // liters to milliliters
            break;
        case 'w':
            output_value = input_value; // output the input value in kilograms
            break;
        default:
            printf("Invalid output unit.\n");
            return 1; // exit with error code
    }

    // output the converted value
    printf("%.2f %c = %.2f %c\n", value, input_unit, output_value, output_unit);

    return 0; // exit with success code
}