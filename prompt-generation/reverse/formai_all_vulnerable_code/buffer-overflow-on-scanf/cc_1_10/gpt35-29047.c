//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>

// Function prototypes
double convert_to_celsius(double fahrenheit);
double convert_to_fahrenheit(double celsius);
void print_menu();
void get_unit(char *unit);
double get_value();
void handle_conversion();

int main() {
    handle_conversion();
    return 0;
}

// Converts temperature from Fahrenheit to Celsius
double convert_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Converts temperature from Celsius to Fahrenheit
double convert_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Prints the main menu
void print_menu() {
    printf("Select an option:\n");
    printf("1. Fahrenheit to Celsius conversion\n");
    printf("2. Celsius to Fahrenheit conversion\n");
    printf("3. Exit\n");
}

// Gets the desired unit from the user
void get_unit(char *unit) {
    printf("Enter the unit you would like to convert to: ");
    scanf("%s", unit);
}

// Gets the value to convert from the user
double get_value() {
    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    return value;
}

// Handles the conversion process
void handle_conversion() {
    int option;
    char unit[10];
    double value, result;

    while (1) {
        print_menu();

        printf("Enter an option: ");
        scanf("%d", &option);

        // Perform the selected conversion
        switch (option) {
            case 1:
                get_unit(unit);
                value = get_value();
                result = convert_to_celsius(value);
                printf("%.2f degrees %s equals %.2f degrees Celsius\n", value, unit, result);
                break;
            case 2:
                get_unit(unit);
                value = get_value();
                result = convert_to_fahrenheit(value);
                printf("%.2f degrees %s equals %.2f degrees Fahrenheit\n", value, unit, result);
                break;
            case 3:
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid option\n");
                break;
        }
    }
}