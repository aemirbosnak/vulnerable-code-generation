//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>

// Function prototype
double convert(double num, char from_unit, char to_unit);

int main() {
    char from_unit, to_unit;
    double num;

    // Get user input
    printf("Enter a number to convert: ");
    scanf("%lf", &num);

    // Get from and to units
    printf("Enter the unit to convert from (e.g. meters, seconds): ");
    scanf(" %c", &from_unit);
    printf("Enter the unit to convert to (e.g. feet, minutes): ");
    scanf(" %c", &to_unit);

    // Convert and display result
    double result = convert(num, from_unit, to_unit);
    printf("%.2lf %c = %.2lf %c\n", num, from_unit, result, to_unit);

    return 0;
}

// Function to convert units
double convert(double num, char from_unit, char to_unit) {
    double result;

    // Check from and to units and perform conversion
    switch(from_unit) {
        case'm': // meters
            switch(to_unit) {
                case 'f': // feet
                    result = num * 3.28084;
                    break;
                case's': // seconds
                    result = num;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return -1;
            }
            break;
        case's': // seconds
            switch(to_unit) {
                case'm': // minutes
                    result = num / 60;
                    break;
                case 'h': // hours
                    result = num / 3600;
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return -1;
            }
            break;
        default:
            printf("Invalid conversion.\n");
            return -1;
    }

    return result;
}