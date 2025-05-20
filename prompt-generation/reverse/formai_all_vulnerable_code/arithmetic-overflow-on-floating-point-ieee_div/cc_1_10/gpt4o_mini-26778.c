//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>

#define LENGTH_CONVERSIONS 3
#define WEIGHT_CONVERSIONS 3
#define TEMPERATURE_CONVERSIONS 2

typedef enum {
    METER,
    KILOMETER,
    MILES
} LengthUnit;

typedef enum {
    GRAM,
    KILOGRAM,
    POUND
} WeightUnit;

typedef enum {
    CELSIUS,
    FAHRENHEIT
} TemperatureUnit;

void convertLength(double value, LengthUnit fromUnit, LengthUnit toUnit) {
    double result;
    switch (fromUnit) {
        case METER:
            if (toUnit == KILOMETER) result = value / 1000;
            else if (toUnit == MILES) result = value * 0.000621371;
            else result = value;
            break;
        case KILOMETER:
            if (toUnit == METER) result = value * 1000;
            else if (toUnit == MILES) result = value * 0.621371;
            else result = value;
            break;
        case MILES:
            if (toUnit == METER) result = value / 0.000621371;
            else if (toUnit == KILOMETER) result = value / 0.621371;
            else result = value;
            break;
    }
    printf("Converted Length: %.6f\n", result);
}

void convertWeight(double value, WeightUnit fromUnit, WeightUnit toUnit) {
    double result;
    switch (fromUnit) {
        case GRAM:
            if (toUnit == KILOGRAM) result = value / 1000;
            else if (toUnit == POUND) result = value * 0.00220462;
            else result = value;
            break;
        case KILOGRAM:
            if (toUnit == GRAM) result = value * 1000;
            else if (toUnit == POUND) result = value * 2.20462;
            else result = value;
            break;
        case POUND:
            if (toUnit == GRAM) result = value / 0.00220462;
            else if (toUnit == KILOGRAM) result = value / 2.20462;
            else result = value;
            break;
    }
    printf("Converted Weight: %.6f\n", result);
}

void convertTemperature(double value, TemperatureUnit fromUnit, TemperatureUnit toUnit) {
    double result;
    if (fromUnit == CELSIUS) {
        if (toUnit == FAHRENHEIT) {
            result = (value * 9 / 5) + 32;
        } else {
            result = value;
        }
    } else {
        if (toUnit == CELSIUS) {
            result = (value - 32) * 5 / 9;
        } else {
            result = value;
        }
    }
    printf("Converted Temperature: %.6f\n", result);
}

void displayMenu() {
    printf("Unit Converter\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        if (choice == 1) {
            double value;
            LengthUnit fromUnit, toUnit;
            printf("Enter length value: ");
            scanf("%lf", &value);
            printf("Select from unit (0: Meter, 1: Kilometer, 2: Miles): ");
            scanf("%d", &fromUnit);
            printf("Select to unit (0: Meter, 1: Kilometer, 2: Miles): ");
            scanf("%d", &toUnit);
            convertLength(value, fromUnit, toUnit);
        } else if (choice == 2) {
            double value;
            WeightUnit fromUnit, toUnit;
            printf("Enter weight value: ");
            scanf("%lf", &value);
            printf("Select from unit (0: Gram, 1: Kilogram, 2: Pound): ");
            scanf("%d", &fromUnit);
            printf("Select to unit (0: Gram, 1: Kilogram, 2: Pound): ");
            scanf("%d", &toUnit);
            convertWeight(value, fromUnit, toUnit);
        } else if (choice == 3) {
            double value;
            TemperatureUnit fromUnit, toUnit;
            printf("Enter temperature value: ");
            scanf("%lf", &value);
            printf("Select from unit (0: Celsius, 1: Fahrenheit): ");
            scanf("%d", &fromUnit);
            printf("Select to unit (0: Celsius, 1: Fahrenheit): ");
            scanf("%d", &toUnit);
            convertTemperature(value, fromUnit, toUnit);
        } else if (choice != 4) {
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    printf("Goodbye!\n");
    return 0;
}