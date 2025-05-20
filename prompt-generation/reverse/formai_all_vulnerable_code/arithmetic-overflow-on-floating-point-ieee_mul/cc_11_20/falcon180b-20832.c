//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Declare variables
    double value, converted_value;
    char unit_from, unit_to;

    // Prompt user for input
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Prompt user for units
    printf("Enter the unit of the value (e.g. meters, seconds, grams, etc.): ");
    scanf(" %c", &unit_from);

    // Prompt user for desired unit
    printf("Enter the unit you want to convert to (e.g. feet, minutes, pounds, etc.): ");
    scanf(" %c", &unit_to);

    // Convert the value
    switch(unit_from) {
        case'm': // Meters
            switch(unit_to) {
                case 'f': // Feet
                    converted_value = value * 3.28084;
                    printf("%.2lf meters is equal to %.2lf feet.\n", value, converted_value);
                    break;
                case 'y': // Yards
                    converted_value = value * 1.09361;
                    printf("%.2lf meters is equal to %.2lf yards.\n", value, converted_value);
                    break;
                case 'k': // Kilometers
                    converted_value = value * 0.001;
                    printf("%.2lf meters is equal to %.2lf kilometers.\n", value, converted_value);
                    break;
                default:
                    printf("Invalid unit of measurement.\n");
            }
            break;
        case's': // Seconds
            switch(unit_to) {
                case'm': // Minutes
                    converted_value = value * 60;
                    printf("%.2lf seconds is equal to %.2lf minutes.\n", value, converted_value);
                    break;
                case 'h': // Hours
                    converted_value = value * 3600;
                    printf("%.2lf seconds is equal to %.2lf hours.\n", value, converted_value);
                    break;
                default:
                    printf("Invalid unit of measurement.\n");
            }
            break;
        case 'g': // Grams
            switch(unit_to) {
                case 'kg': // Kilograms
                    converted_value = value * 0.001;
                    printf("%.2lf grams is equal to %.2lf kilograms.\n", value, converted_value);
                    break;
                case 'lb': // Pounds
                    converted_value = value * 0.00220462;
                    printf("%.2lf grams is equal to %.2lf pounds.\n", value, converted_value);
                    break;
                default:
                    printf("Invalid unit of measurement.\n");
            }
            break;
        default:
            printf("Invalid unit of measurement.\n");
    }

    return 0;
}