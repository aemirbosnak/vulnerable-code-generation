//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: random
// Temperature Converter Bonanza Extravaganza

#include <stdio.h>
#include <stdlib.h>

// Define conversion macros to avoid repetition
#define C_TO_F(c) ((c) * 9 / 5 + 32)
#define F_TO_C(f) ((f) - 32) * 5 / 9

// Function to print a conversion table
void print_conversion_table(const char *unit, double min, double max, double step) {
    for (double temp = min; temp <= max; temp += step) {
        printf("%s %.1f: %.1f\n", unit, temp, unit == "F" ? C_TO_F(temp) : F_TO_C(temp));
    }
}

// Function to get user input for temperature and unit
void get_user_input(double *temp, char *unit) {
    printf("Enter temperature: ");
    scanf("%lf", temp);
    printf("Enter unit (F/C): ");
    scanf(" %c", unit);
}

// Main function
int main(int argc, char **argv) {
    double temp;
    char unit;

    // Get user input
    get_user_input(&temp, &unit);

    // Handle valid inputs
    switch (unit) {
        case 'F':
            printf("%.1f F = %.1f C\n", temp, C_TO_F(temp));
            break;
        case 'C':
            printf("%.1f C = %.1f F\n", temp, F_TO_C(temp));
            break;
        default:
            printf("Invalid unit: %c\n", unit);
            return EXIT_FAILURE;
    }

    // Print conversion table
    printf("Conversion Table:\n");
    printf("F    C\n");
    print_conversion_table("F", 0, 100, 10);
    printf("\nC    F\n");
    print_conversion_table("C", 0, 100, 10);

    return EXIT_SUCCESS;
}