//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hey there, conversion enthusiast! Let's embark on an exciting journey through the world of units!\n\n");

    // Declare some variables to hold the user's input and conversion results
    float input_amount, converted_amount;
    char input_unit, output_unit;

    // Get the user's input
    printf("Enter the amount you want to convert: ");
    scanf("%f", &input_amount);

    printf("Enter the unit you're converting from (e.g., km, m, lb, oz): ");
    scanf(" %c", &input_unit);

    printf("Enter the unit you want to convert to (e.g., mi, ft, kg, g): ");
    scanf(" %c", &output_unit);

    // Convert the input amount to the desired unit
    switch (input_unit) {
        case 'k':
            if (output_unit == 'm') {
                converted_amount = input_amount * 1000;
            } else if (output_unit == 'i') {
                converted_amount = input_amount * 0.621371;
            } else if (output_unit == 'f') {
                converted_amount = input_amount * 3280.84;
            }
            break;

        case 'm':
            if (output_unit == 'k') {
                converted_amount = input_amount / 1000;
            } else if (output_unit == 'i') {
                converted_amount = input_amount * 0.000621371;
            } else if (output_unit == 'f') {
                converted_amount = input_amount * 3.28084;
            }
            break;

        case 'i':
            if (output_unit == 'k') {
                converted_amount = input_amount * 1.60934;
            } else if (output_unit == 'm') {
                converted_amount = input_amount * 1609.34;
            } else if (output_unit == 'f') {
                converted_amount = input_amount * 5280;
            }
            break;

        case 'f':
            if (output_unit == 'k') {
                converted_amount = input_amount / 3280.84;
            } else if (output_unit == 'm') {
                converted_amount = input_amount / 3.28084;
            } else if (output_unit == 'i') {
                converted_amount = input_amount / 5280;
            }
            break;

        case 'l':
            if (output_unit == 'k') {
                converted_amount = input_amount * 0.453592;
            } else if (output_unit == 'g') {
                converted_amount = input_amount * 453.592;
            } else if (output_unit == 'o') {
                converted_amount = input_amount * 16;
            }
            break;

        case 'g':
            if (output_unit == 'l') {
                converted_amount = input_amount * 0.00220462;
            } else if (output_unit == 'k') {
                converted_amount = input_amount / 1000;
            } else if (output_unit == 'o') {
                converted_amount = input_amount / 28.3495;
            }
            break;

        case 'o':
            if (output_unit == 'l') {
                converted_amount = input_amount * 0.0625;
            } else if (output_unit == 'g') {
                converted_amount = input_amount * 28.3495;
            } else if (output_unit == 'k') {
                converted_amount = input_amount / 16;
            }
            break;

        default:
            printf("Sorry, that unit is not supported yet. Please try again with a supported unit.\n");
            return 1;
    }

    // Print the result
    printf("Ta-da! Your converted amount is: %.2f %c\n", converted_amount, output_unit);

    // Congratulate the user and say goodbye
    printf("Congratulations on your successful conversion! See you next time for more unit adventures!\n");

    return 0;
}