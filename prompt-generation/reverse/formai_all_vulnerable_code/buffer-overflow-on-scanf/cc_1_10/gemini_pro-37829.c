//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Forward declarations
void print_menu();
void convert_length();
void convert_weight();
void convert_temperature();
void convert_currency();

int main() {
    // Print a cheerful welcome message
    printf("Welcome to the Unit Converter! I'm here to make your life easier and happier.\n");

    // Print the menu of options
    print_menu();

    // Get the user's choice
    int choice;
    printf("What do you want to do? (Enter a number): ");
    scanf("%d", &choice);

    // Call the appropriate conversion function based on the user's choice
    switch (choice) {
        case 1:
            convert_length();
            break;
        case 2:
            convert_weight();
            break;
        case 3:
            convert_temperature();
            break;
        case 4:
            convert_currency();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    // Print a cheerful goodbye message
    printf("Thank you for using the Unit Converter! Have a happy day!\n");

    return 0;
}

void print_menu() {
    printf("\nHere's a list of conversions I can do for you:\n");
    printf("1. Convert length\n");
    printf("2. Convert weight\n");
    printf("3. Convert temperature\n");
    printf("4. Convert currency\n");
}

void convert_length() {
    // Get the user's input
    float value;
    char unit1, unit2;
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    printf("Enter the original unit (e.g. cm, m, km): ");
    scanf(" %c", &unit1);
    printf("Enter the desired unit (e.g. cm, m, km): ");
    scanf(" %c", &unit2);

    // Convert the value to the desired unit
    float converted_value;
    switch (unit1) {
        case 'c':
            switch (unit2) {
                case 'c':
                    converted_value = value;
                    break;
                case 'm':
                    converted_value = value / 100;
                    break;
                case 'k':
                    converted_value = value / 100000;
                    break;
            }
            break;
        case 'm':
            switch (unit2) {
                case 'c':
                    converted_value = value * 100;
                    break;
                case 'm':
                    converted_value = value;
                    break;
                case 'k':
                    converted_value = value / 1000;
                    break;
            }
            break;
        case 'k':
            switch (unit2) {
                case 'c':
                    converted_value = value * 100000;
                    break;
                case 'm':
                    converted_value = value * 1000;
                    break;
                case 'k':
                    converted_value = value;
                    break;
            }
            break;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, unit2);
}

void convert_weight() {
    // Get the user's input
    float value;
    char unit1, unit2;
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    printf("Enter the original unit (e.g. g, kg, lb): ");
    scanf(" %c", &unit1);
    printf("Enter the desired unit (e.g. g, kg, lb): ");
    scanf(" %c", &unit2);

    // Convert the value to the desired unit
    float converted_value;
    switch (unit1) {
        case 'g':
            switch (unit2) {
                case 'g':
                    converted_value = value;
                    break;
                case 'k':
                    converted_value = value / 1000;
                    break;
                case 'l':
                    converted_value = value / 453.592;
                    break;
            }
            break;
        case 'k':
            switch (unit2) {
                case 'g':
                    converted_value = value * 1000;
                    break;
                case 'k':
                    converted_value = value;
                    break;
                case 'l':
                    converted_value = value * 2.20462;
                    break;
            }
            break;
        case 'l':
            switch (unit2) {
                case 'g':
                    converted_value = value * 453.592;
                    break;
                case 'k':
                    converted_value = value / 2.20462;
                    break;
                case 'l':
                    converted_value = value;
                    break;
            }
            break;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, unit2);
}

void convert_temperature() {
    // Get the user's input
    float value;
    char unit1, unit2;
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    printf("Enter the original unit (e.g. C, F): ");
    scanf(" %c", &unit1);
    printf("Enter the desired unit (e.g. C, F): ");
    scanf(" %c", &unit2);

    // Convert the value to the desired unit
    float converted_value;
    if (unit1 == 'C' && unit2 == 'F') {
        converted_value = (value * 9 / 5) + 32;
    } else if (unit1 == 'F' && unit2 == 'C') {
        converted_value = (value - 32) * 5 / 9;
    } else {
        printf("Invalid conversion. Please try again.\n");
        return;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, unit2);
}

void convert_currency() {
    // Get the user's input
    float value;
    char currency1, currency2;
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    printf("Enter the original currency (e.g. USD, EUR): ");
    scanf(" %c", &currency1);
    printf("Enter the desired currency (e.g. USD, EUR): ");
    scanf(" %c", &currency2);

    // Convert the value to the desired currency
    float converted_value;
    if (currency1 == 'U' && currency2 == 'E') {
        converted_value = value * 0.85;
    } else if (currency1 == 'E' && currency2 == 'U') {
        converted_value = value * 1.18;
    } else {
        printf("Invalid conversion. Please try again.\n");
        return;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, currency2);
}