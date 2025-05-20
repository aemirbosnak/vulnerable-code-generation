//FormAI DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Unit {
    METER,
    KILOMETER,
    FOOT,
    MILE,
    KILOGRAM,
    GRAM,
    POUND,
    OUNCE,
    CELSIUS,
    FAHRENHEIT
};

struct Conversion {
    enum Unit from;
    enum Unit to;
    double multiplier;
};

void initializeConversions(struct Conversion *conversions) {
    conversions[0] = (struct Conversion) {METER, KILOMETER, 0.001};
    conversions[1] = (struct Conversion) {KILOMETER, METER, 1000};
    conversions[2] = (struct Conversion) {FOOT, METER, 0.3048};
    conversions[3] = (struct Conversion) {METER, FOOT, 3.28084};
    conversions[4] = (struct Conversion) {MILE, KILOMETER, 1.60934};
    conversions[5] = (struct Conversion) {KILOMETER, MILE, 0.621371};
    conversions[6] = (struct Conversion) {KILOGRAM, POUND, 2.20462};
    conversions[7] = (struct Conversion) {POUND, KILOGRAM, 0.453592};
    conversions[8] = (struct Conversion) {GRAM, OUNCE, 0.035274};
    conversions[9] = (struct Conversion) {OUNCE, GRAM, 28.3495};
    conversions[10] = (struct Conversion) {CELSIUS, FAHRENHEIT, 9.0 / 5.0};
    conversions[11] = (struct Conversion) {FAHRENHEIT, CELSIUS, 5.0 / 9.0};
}

void printUnits() {
    printf("Available Units:\n");
    printf("1. Meter\n");
    printf("2. Kilometer\n");
    printf("3. Foot\n");
    printf("4. Mile\n");
    printf("5. Kilogram\n");
    printf("6. Gram\n");
    printf("7. Pound\n");
    printf("8. Ounce\n");
    printf("9. Celsius\n");
    printf("10. Fahrenheit\n");
}

enum Unit selectUnit() {
    int option;
    printf("Please select a unit: ");
    scanf("%d", &option);
    while (option < 1 || option > 10) {
        printf("Invalid option. Please select a unit from 1 to 10.\n");
        printf("Please select a unit: ");
        scanf("%d", &option);
    }
    return option - 1;
}

double convert(double value, struct Conversion conversion) {
    return value * conversion.multiplier;
}

void printValue(double value, enum Unit unit) {
    switch (unit) {
        case METER:
            printf("%.2f meters\n", value);
            break;
        case KILOMETER:
            printf("%.2f kilometers\n", value);
            break;
        case FOOT:
            printf("%.2f feet\n", value);
            break;
        case MILE:
            printf("%.2f miles\n", value);
            break;
        case KILOGRAM:
            printf("%.2f kilograms\n", value);
            break;
        case GRAM:
            printf("%.2f grams\n", value);
            break;
        case POUND:
            printf("%.2f pounds\n", value);
            break;
        case OUNCE:
            printf("%.2f ounces\n", value);
            break;
        case CELSIUS:
            printf("%.2f Celsius\n", value);
            break;
        case FAHRENHEIT:
            printf("%.2f Fahrenheit\n", value);
            break;
        default:
            printf("Invalid unit\n");
            break;
    }
}

int main() {
    struct Conversion conversions[12];
    initializeConversions(conversions);

    printf("Welcome to the Unit Converter!\n");
    printf("-----------------------------------------\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Convert a value\n");
        printf("2. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            printf("Please select the unit to convert from:\n");
            printUnits();
            enum Unit fromUnit = selectUnit();

            printf("Please select the unit to convert to:\n");
            printUnits();
            enum Unit toUnit = selectUnit();

            printf("Please enter the value to convert: ");
            double value;
            scanf("%lf", &value);

            double intermediateValue;
            if (fromUnit == toUnit) {
                printf("Conversion not needed. The value in the selected unit is: ");
                printValue(value, fromUnit);
            } else {
                for (int i = 0; i < 12; i++) {
                    if (conversions[i].from == fromUnit && conversions[i].to == toUnit) {
                        intermediateValue = convert(value, conversions[i]);
                        break;
                    } else if (conversions[i].from == toUnit && conversions[i].to == fromUnit) {
                        intermediateValue = convert(value, conversions[i]);
                        intermediateValue = 1.0 / intermediateValue;
                        break;
                    }
                }
                printf("The converted value is: ");
                printValue(intermediateValue, toUnit);
            }

        } else if (option == 2) {
            printf("Goodbye!\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Invalid option\n");
        }
        printf("-----------------------------------------\n");
    }
    return 0;
}