//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Unit conversion functions
double cm_to_inch(double cm) { return cm / 2.54; }
double inch_to_cm(double inch) { return inch * 2.54; }
double kg_to_lb(double kg) { return kg * 2.205; }
double lb_to_kg(double lb) { return lb / 2.205; }
double cel_to_fahr(double cel) { return cel * 9.0 / 5.0 + 32.0; }
double fahr_to_cel(double fahr) { return (fahr - 32.0) * 5.0 / 9.0; }

int main() {
    // Print a happy message
    printf("Welcome to the Unit Converter! :D\n\n");

    // Get user input
    char from_unit, to_unit;
    double value;
    printf("Enter the unit you want to convert from (cm/kg/cel): ");
    scanf(" %c", &from_unit);
    printf("Enter the unit you want to convert to (inch/lb/fahr): ");
    scanf(" %c", &to_unit);
    printf("Enter the value you want to convert: ");
    scanf(" %lf", &value);

    // Perform the conversion
    double result;
    switch (from_unit) {
        case 'c':
            switch (to_unit) {
                case 'i':
                    result = cm_to_inch(value);
                    break;
                case 'l':
                    result = kg_to_lb(value);
                    break;
                case 'f':
                    result = cel_to_fahr(value);
                    break;
            }
            break;
        case 'k':
            switch (to_unit) {
                case 'i':
                    result = inch_to_cm(value);
                    break;
                case 'l':
                    result = lb_to_kg(value);
                    break;
                case 'f':
                    result = cel_to_fahr(value);
                    break;
            }
            break;
        case 'f':
            switch (to_unit) {
                case 'i':
                    result = inch_to_cm(value);
                    break;
                case 'l':
                    result = lb_to_kg(value);
                    break;
                case 'c':
                    result = fahr_to_cel(value);
                    break;
            }
            break;
    }

    // Print the result
    printf("\nThe converted value is: %.2f\n", result);

    // Print a happy message
    printf("Yay! You did it! :D\n");

    return 0;
}