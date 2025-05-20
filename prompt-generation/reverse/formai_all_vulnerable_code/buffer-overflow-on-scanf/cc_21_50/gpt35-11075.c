//FormAI DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>

int main() {
    double input, output;
    char unitFrom, unitTo;
    printf("Welcome to the Brave Unit Converter!\n");

    // Ask for initial unit and input value
    printf("Enter an input value and its original unit (i.e. 5e3 km): ");
    scanf("%lf %c%c", &input, &unitFrom, &unitFrom);

    // Ask for target unit to convert to
    printf("Enter target unit for conversion (i.e. mi): ");
    scanf(" %c", &unitTo);

    // Perform conversion
    if (unitFrom == 'm' && unitTo == 'f') {
        output = input * 3.281;
    } else if (unitFrom == 'f' && unitTo == 'm') {
        output = input / 3.281;
    } else if (unitFrom == 'c' && unitTo == 'f') {
        output = (input * 9/5) + 32;
    } else if (unitFrom == 'f' && unitTo == 'c') {
        output = (input - 32) * 5/9;
    } else if (unitFrom == 'k' && unitTo == 'c') {
        output = input - 273.15;
    } else if (unitFrom == 'c' && unitTo == 'k') {
        output = input + 273.15;
    } else if (unitFrom == 'm' && unitTo == 'k') {
        output = input / 1000;
    } else if (unitFrom == 'k' && unitTo == 'm') {
        output = input * 1000;
    } else if (unitFrom == 'g' && unitTo == 'oz') {
        output = input / 28.35;
    } else if (unitFrom == 'oz' && unitTo == 'g') {
        output = input * 28.35;
    } else {
        printf("Conversion not supported yet!\n");
        return 1;
    }

    // Print results
    printf("%.2f %c%c is equal to %.2f %c.\n", input, unitFrom, unitFrom, output, unitTo);

    // Allow for more conversions
    char answer;
    printf("Would you like to convert another value? (y/n): ");
    scanf(" %c", &answer);

    // Loop back to beginning if user wants to convert again
    while (answer == 'y') {
        printf("Enter an input value and its original unit (i.e. 5e3 km): ");
        scanf("%lf %c%c", &input, &unitFrom, &unitFrom);

        printf("Enter target unit for conversion (i.e. mi): ");
        scanf(" %c", &unitTo);

        // Perform conversion
        if (unitFrom == 'm' && unitTo == 'f') {
            output = input * 3.281;
        } else if (unitFrom == 'f' && unitTo == 'm') {
            output = input / 3.281;
        } else if (unitFrom == 'c' && unitTo == 'f') {
            output = (input * 9/5) + 32;
        } else if (unitFrom == 'f' && unitTo == 'c') {
            output = (input - 32) * 5/9;
        } else if (unitFrom == 'k' && unitTo == 'c') {
            output = input - 273.15;
        } else if (unitFrom == 'c' && unitTo == 'k') {
            output = input + 273.15;
        } else if (unitFrom == 'm' && unitTo == 'k') {
            output = input / 1000;
        } else if (unitFrom == 'k' && unitTo == 'm') {
            output = input * 1000;
        } else if (unitFrom == 'g' && unitTo == 'oz') {
            output = input / 28.35;
        } else if (unitFrom == 'oz' && unitTo == 'g') {
            output = input * 28.35;
        } else {
            printf("Conversion not supported yet!\n");
            return 1;
        }

        printf("%.2f %c%c is equal to %.2f %c.\n", input, unitFrom, unitFrom, output, unitTo);
        printf("Would you like to convert another value? (y/n): ");
        scanf(" %c", &answer);
    }

    printf("Thanks for using Brave Unit Converter!\n");

    return 0;
}