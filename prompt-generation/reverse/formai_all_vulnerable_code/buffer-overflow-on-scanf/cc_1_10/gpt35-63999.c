//FormAI DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Conversion ratios */
#define KM_PER_MI 1.60934
#define KG_PER_LB 0.453592
#define L_PER_GAL 3.78541

/* Function prototypes */
float get_float_input(char* prompt);
int get_int_input(char* prompt);
bool confirm(char* prompt);
float convert_miles_to_kilometers(float miles);
float convert_pounds_to_kilograms(float pounds);
float convert_gallons_to_liters(float gallons);
float convert_inches_to_centimeters(float inches);
void print_menu();
void handle_conversion(int choice);

/* Main program entry */
int main() {
    printf("\nWelcome to the Unit Converter!\n\n");

    while (true) {
        print_menu();

        int choice = get_int_input("Please enter your choice: ");

        if (choice == 0) {
            break; // Exit program
        }

        handle_conversion(choice);
    }

    printf("\nThank you for using the Unit Converter!\n\n");

    return 0;
}

/* Prompts the user for a float input */
float get_float_input(char* prompt) {
    while (true) {
        printf("%s", prompt);

        float input;

        if (scanf("%f", &input) != 1) {
            printf("Error: Invalid input. Please try again.\n");
            fflush(stdin);
            continue;
        }

        fflush(stdin); // Discard any extra input

        return input;
    }
}

/* Prompts the user for an integer input */
int get_int_input(char* prompt) {
    while (true) {
        printf("%s", prompt);

        int input;

        if (scanf("%d", &input) != 1) {
            printf("Error: Invalid input. Please try again.\n");
            fflush(stdin);
            continue;
        }

        fflush(stdin); // Discard any extra input

        return input;
    }
}

/* Prompts the user for confirmation */
bool confirm(char* prompt) {
    while (true) {
        printf("%s", prompt);

        char response;

        if (scanf(" %c", &response) != 1 || (response != 'y' && response != 'n')) {
            printf("Error: Invalid input. Please try again.\n");
            fflush(stdin);
            continue;
        }

        fflush(stdin); // Discard any extra input

        return (response == 'y');
    }
}

/* Converts miles to kilometers */
float convert_miles_to_kilometers(float miles) {
    return miles * KM_PER_MI;
}

/* Converts pounds to kilograms */
float convert_pounds_to_kilograms(float pounds) {
    return pounds * KG_PER_LB;
}

/* Converts gallons to liters */
float convert_gallons_to_liters(float gallons) {
    return gallons * L_PER_GAL;
}

/* Converts inches to centimeters */
float convert_inches_to_centimeters(float inches) {
    return inches * 2.54;
}

/* Prints the conversion menu */
void print_menu() {
    printf("Please choose a conversion option:\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Gallons to Liters\n");
    printf("4. Inches to Centimeters\n");
    printf("0. Exit\n");
}

/* Handles the user's choice for conversion */
void handle_conversion(int choice) {
    printf("\n");

    float input = 0.0;

    switch (choice) {
        case 1:
            input = get_float_input("Enter miles: ");
            printf("%.2f miles is equivalent to %.2f kilometers\n", input, convert_miles_to_kilometers(input));
            break;
        case 2:
            input = get_float_input("Enter pounds: ");
            printf("%.2f pounds is equivalent to %.2f kilograms\n", input, convert_pounds_to_kilograms(input));
            break;
        case 3:
            input = get_float_input("Enter gallons: ");
            printf("%.2f gallons is equivalent to %.2f liters\n", input, convert_gallons_to_liters(input));
            break;
        case 4:
            input = get_float_input("Enter inches: ");
            printf("%.2f inches is equivalent to %.2f centimeters\n", input, convert_inches_to_centimeters(input));
            break;
        default:
            printf("Error: Invalid choice. Please try again.\n");
            break;
    }

    printf("\n");

    if (input != 0.0 && confirm("Would you like to convert another value? (y/n): ")) {
        handle_conversion(choice);
    }
}