//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    CM_TO_INCH,
    INCH_TO_CM,
    KG_TO_POUND,
    POUND_TO_KG,
    CELSIUS_TO_FAHRENHEIT,
    FAHRENHEIT_TO_CELSIUS
} conversion_type;

const char *conversion_types[] = {
    "Centimeters to Inches",
    "Inches to Centimeters",
    "Kilograms to Pounds",
    "Pounds to Kilograms",
    "Celsius to Fahrenheit",
    "Fahrenheit to Celsius"
};

double cm_to_inch(double cm) {
    return cm * 0.393701;
}

double inch_to_cm(double inch) {
    return inch * 2.54;
}

double kg_to_pound(double kg) {
    return kg * 2.20462;
}

double pound_to_kg(double pound) {
    return pound * 0.453592;
}

double celsius_to_fahrenheit(double celsius) {
    return celsius * 1.8 + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

void print_conversions() {
    printf("Available conversions:\n");
    for (int i = 0; i < sizeof(conversion_types) / sizeof(char *); i++) {
        printf("%d. %s\n", i + 1, conversion_types[i]);
    }
}

int main() {
    print_conversions();

    int choice;
    printf("Enter the conversion you want to perform: ");
    scanf("%d", &choice);

    double value;
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);

    double result;
    switch (choice) {
        case CM_TO_INCH:
            result = cm_to_inch(value);
            printf("%.2f centimeters is equal to %.2f inches\n", value, result);
            break;
        case INCH_TO_CM:
            result = inch_to_cm(value);
            printf("%.2f inches is equal to %.2f centimeters\n", value, result);
            break;
        case KG_TO_POUND:
            result = kg_to_pound(value);
            printf("%.2f kilograms is equal to %.2f pounds\n", value, result);
            break;
        case POUND_TO_KG:
            result = pound_to_kg(value);
            printf("%.2f pounds is equal to %.2f kilograms\n", value, result);
            break;
        case CELSIUS_TO_FAHRENHEIT:
            result = celsius_to_fahrenheit(value);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", value, result);
            break;
        case FAHRENHEIT_TO_CELSIUS:
            result = fahrenheit_to_celsius(value);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", value, result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}