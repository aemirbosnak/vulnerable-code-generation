//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void convert_length();
void convert_weight();
void convert_temperature();
void display_menu();
double length_conversion(double value, int from_unit, int to_unit);
double weight_conversion(double value, int from_unit, int to_unit);
double temperature_conversion(double value, int from_unit, int to_unit);
void flush_stdin();

#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define KILOGRAMS_TO_POUNDS 2.20462
#define POUNDS_TO_KILOGRAMS 0.453592
#define CELSIUS_TO_FAHRENHEIT(value) ((value) * 9.0 / 5.0 + 32.0)
#define FAHRENHEIT_TO_CELSIUS(value) ((value) - 32.0) * 5.0 / 9.0

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        flush_stdin();

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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void display_menu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
}

void convert_length() {
    double value;
    int from_unit, to_unit;

    printf("\n--- Length Conversion ---\n");
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    flush_stdin();
    
    printf("Select from unit: 1. Meters, 2. Feet\n");
    scanf("%d", &from_unit);
    flush_stdin();
    
    printf("Select to unit: 1. Meters, 2. Feet\n");
    scanf("%d", &to_unit);
    flush_stdin();

    double result = length_conversion(value, from_unit - 1, to_unit - 1);
    printf("Converted value: %.2lf\n", result);
}

void convert_weight() {
    double value;
    int from_unit, to_unit;

    printf("\n--- Weight Conversion ---\n");
    printf("Enter weight to convert: ");
    scanf("%lf", &value);
    flush_stdin();
    
    printf("Select from unit: 1. Kilograms, 2. Pounds\n");
    scanf("%d", &from_unit);
    flush_stdin();
    
    printf("Select to unit: 1. Kilograms, 2. Pounds\n");
    scanf("%d", &to_unit);
    flush_stdin();

    double result = weight_conversion(value, from_unit - 1, to_unit - 1);
    printf("Converted weight: %.2lf\n", result);
}

void convert_temperature() {
    double value;
    int from_unit, to_unit;

    printf("\n--- Temperature Conversion ---\n");
    printf("Enter temperature to convert: ");
    scanf("%lf", &value);
    flush_stdin();
    
    printf("Select from unit: 1. Celsius, 2. Fahrenheit\n");
    scanf("%d", &from_unit);
    flush_stdin();
    
    printf("Select to unit: 1. Celsius, 2. Fahrenheit\n");
    scanf("%d", &to_unit);
    flush_stdin();

    double result = temperature_conversion(value, from_unit - 1, to_unit - 1);
    printf("Converted temperature: %.2lf\n", result);
}

double length_conversion(double value, int from_unit, int to_unit) {
    if (from_unit == 0) { // Meters to Feet
        return value * METERS_TO_FEET;
    } else { // Feet to Meters
        return value * FEET_TO_METERS;
    }
}

double weight_conversion(double value, int from_unit, int to_unit) {
    if (from_unit == 0) { // Kilograms to Pounds
        return value * KILOGRAMS_TO_POUNDS;
    } else { // Pounds to Kilograms
        return value * POUNDS_TO_KILOGRAMS;
    }
}

double temperature_conversion(double value, int from_unit, int to_unit) {
    if (from_unit == 0) { // Celsius to Fahrenheit
        return CELSIUS_TO_FAHRENHEIT(value);
    } else { // Fahrenheit to Celsius
        return FAHRENHEIT_TO_CELSIUS(value);
    }
}

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}