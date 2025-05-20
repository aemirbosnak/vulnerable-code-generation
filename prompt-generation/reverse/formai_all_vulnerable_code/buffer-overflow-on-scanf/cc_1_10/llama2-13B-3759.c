//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a list of unit conversions
typedef struct {
    const char *name;
    double factor;
} conv_t;

static conv_t conversions[] = {
    {"in", 2.54},
    {"cm", 10},
    {"mm", 0.01},
    {"ft", 12},
    {"yd", 36},
    {"mi", 1609.34},
    {"km", 0.001}
};

// Declare a function to perform unit conversions
void convert(double value, conv_t *conversion) {
    double result = value * conversion->factor;
    printf("%.2f %s = %.2f %s\n", value, conversion->name, result, conversion->name);
}

int main() {
    int choice;
    double value, result;
    char input[10];

    // Print a menu of unit conversion options
    printf("Welcome to the Unit Converter!\n");
    printf("Please select a unit to convert from the following options:\n");
    printf("1. Inches\n2. Centimeters\n3. Millimeters\n4. Feet\n5. Yards\n6. Miles\n");
    printf("Please enter your choice: ");

    // Get the user's input
    scanf("%d", &choice);

    // Perform the unit conversion based on the user's input
    switch (choice) {
        case 1:
            printf("Enter a value in inches: ");
            scanf("%lf", &value);
            convert(value, conversions + 0);
            break;
        case 2:
            printf("Enter a value in centimeters: ");
            scanf("%lf", &value);
            convert(value, conversions + 1);
            break;
        case 3:
            printf("Enter a value in millimeters: ");
            scanf("%lf", &value);
            convert(value, conversions + 2);
            break;
        case 4:
            printf("Enter a value in feet: ");
            scanf("%lf", &value);
            convert(value, conversions + 3);
            break;
        case 5:
            printf("Enter a value in yards: ");
            scanf("%lf", &value);
            convert(value, conversions + 4);
            break;
        case 6:
            printf("Enter a value in miles: ");
            scanf("%lf", &value);
            convert(value, conversions + 5);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}