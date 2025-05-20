//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void clear_input_buffer(void);
void print_menu(void);
void convert_units(int option);
void check_input(char *input);

typedef enum {
    INVALID=0,
    INCH_TO_CM,
    CM_TO_INCH,
    LB_TO_KG,
    KG_TO_LB,
    G_TO_OZ,
    OZ_TO_G
} ConversionOption;

int main() {
    char input[20];
    int option = INVALID;

    while (option == INVALID) {
        print_menu();
        fgets(input, 20, stdin);
        check_input(input);
        option = atoi(input);
        if (option < 1 || option > 6) {
            option = INVALID;
            printf("Invalid option. Please choose again.\n");
        }
    }

    convert_units(option);

    return 0;
}

void clear_input_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_menu(void) {
    printf("Please choose the conversion option:\n");
    printf("1. Inch to centimeter\n");
    printf("2. Centimeter to inch\n");
    printf("3. Pound to kilogram\n");
    printf("4. Kilogram to pound\n");
    printf("5. Gram to ounce\n");
    printf("6. Ounce to gram\n");
}

void convert_units(int option) {
    char input[20];
    double value;
    double result;
    char *from_unit;
    char *to_unit;

    switch (option) {
        case INCH_TO_CM:
            from_unit = "inch";
            to_unit = "centimeter";
            printf("Enter the value in inches: ");
            fgets(input, 20, stdin);
            check_input(input);
            value = atof(input);
            result = value * 2.54;
            break;
        case CM_TO_INCH:
            from_unit = "centimeter";
            to_unit = "inch";
            printf("Enter the value in centimeters: ");
            fgets(input, 20, stdin);
            check_input(input);
            value = atof(input);
            result = value / 2.54;
            break;
        case LB_TO_KG:
            from_unit = "pound";
            to_unit = "kilogram";
            printf("Enter the value in pounds: ");
            fgets(input, 20, stdin);
            check_input(input);
            value = atof(input);
            result = value * 0.453592;
            break;
        case KG_TO_LB:
            from_unit = "kilogram";
            to_unit = "pound";
            printf("Enter the value in kilograms: ");
            fgets(input, 20, stdin);
            check_input(input);
            value = atof(input);
            result = value / 0.453592;
            break;
        case G_TO_OZ:
            from_unit = "gram";
            to_unit = "ounce";
            printf("Enter the value in grams: ");
            fgets(input, 20, stdin);
            check_input(input);
            value = atof(input);
            result = value * 0.035274;
            break;
        case OZ_TO_G:
            from_unit = "ounce";
            to_unit = "gram";
            printf("Enter the value in ounces: ");
            fgets(input, 20, stdin);
            check_input(input);
            value = atof(input);
            result = value / 0.035274;
            break;
    }

    printf("%g %s is equal to %g %s.\n", value, from_unit, result, to_unit);
}

void check_input(char *input) {
    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Check for non-numeric characters
    for (int i = 0; input[i] != '\0'; i++) {
        if (!(input[i] >= '0' && input[i] <= '9') && input[i] != '.') {
            printf("Invalid input. Please enter a numeric value.\n");
            clear_input_buffer();
            printf("Enter the value again: ");
            fgets(input, 20, stdin);
            i = -1; // Reset loop counter to start from the beginning
        }
    }
}