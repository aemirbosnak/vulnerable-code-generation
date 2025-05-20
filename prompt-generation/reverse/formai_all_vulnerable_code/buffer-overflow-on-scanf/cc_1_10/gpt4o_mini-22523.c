//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef enum { LENGTH, MASS, TEMPERATURE } UnitType;

typedef struct {
    char* name;
    double conversion_factor;
} Unit;

Unit length_units[] = {
    {"Kilometers", 1000.0},
    {"Meters", 1.0},
    {"Centimeters", 0.01},
    {"Millimeters", 0.001},
    {"Feet", 0.3048},
    {"Inches", 0.0254}
};

Unit mass_units[] = {
    {"Kilograms", 1.0},
    {"Grams", 0.001},
    {"Pounds", 0.453592},
    {"Ounces", 0.0283495}
};

Unit temperature_units[] = {
    {"Celsius", 1.0},
    {"Fahrenheit", 1.0},
    {"Kelvin", 1.0}
};

void display_units(UnitType type) {
    switch (type) {
        case LENGTH:
            printf("\nAvailable Length Units:\n");
            for (int i = 0; i < sizeof(length_units)/sizeof(Unit); i++) {
                printf("%d: %s\n", i + 1, length_units[i].name);
            }
            break;
        case MASS:
            printf("\nAvailable Mass Units:\n");
            for (int i = 0; i < sizeof(mass_units)/sizeof(Unit); i++) {
                printf("%d: %s\n", i + 1, mass_units[i].name);
            }
            break;
        case TEMPERATURE:
            printf("\nAvailable Temperature Units:\n");
            for (int i = 0; i < sizeof(temperature_units)/sizeof(Unit); i++) {
                printf("%d: %s\n", i + 1, temperature_units[i].name);
            }
            break;
    }
}

double convert_length(double value, int from, int to) {
    return value * (length_units[from].conversion_factor / length_units[to].conversion_factor);
}

double convert_mass(double value, int from, int to) {
    return value * (mass_units[from].conversion_factor / mass_units[to].conversion_factor);
}

double convert_temperature(double value, int from, int to) {
    if (from == 0 && to == 1) {  // Celsius to Fahrenheit
        return (value * 9 / 5) + 32;
    } else if (from == 1 && to == 0) {  // Fahrenheit to Celsius
        return (value - 32) * 5 / 9;
    } else if (from == 0 && to == 2) {  // Celsius to Kelvin
        return value + 273.15;
    } else if (from == 2 && to == 0) {  // Kelvin to Celsius
        return value - 273.15;
    } else if (from == 1 && to == 2) {  // Fahrenheit to Kelvin
        return (value - 32) * 5 / 9 + 273.15;
    } else if (from == 2 && to == 1) {  // Kelvin to Fahrenheit
        return (value - 273.15) * 9 / 5 + 32;
    }
    return value; // Same unit case
}

int main() {
    int choice = 0;
    double value;
    int from_unit, to_unit;

    while (1) {
        printf("\nUnit Converter\n");
        printf("1. Length\n2. Mass\n3. Temperature\n4. Exit\n");
        printf("Choose the type of conversion (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) break;

        switch (choice) {
            case 1:
                display_units(LENGTH);
                printf("Enter the number corresponding to the unit you want to convert from: ");
                scanf("%d", &from_unit);
                printf("Enter the number corresponding to the unit you want to convert to: ");
                scanf("%d", &to_unit);
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                printf("Converted value: %.4f %s\n", convert_length(value, from_unit - 1, to_unit - 1), length_units[to_unit - 1].name);
                break;
            case 2:
                display_units(MASS);
                printf("Enter the number corresponding to the unit you want to convert from: ");
                scanf("%d", &from_unit);
                printf("Enter the number corresponding to the unit you want to convert to: ");
                scanf("%d", &to_unit);
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                printf("Converted value: %.4f %s\n", convert_mass(value, from_unit - 1, to_unit - 1), mass_units[to_unit - 1].name);
                break;
            case 3:
                display_units(TEMPERATURE);
                printf("Enter the number corresponding to the unit you want to convert from: ");
                scanf("%d", &from_unit);
                printf("Enter the number corresponding to the unit you want to convert to: ");
                scanf("%d", &to_unit);
                printf("Enter the value to convert: ");
                scanf("%lf", &value);
                printf("Converted value: %.4f %s\n", convert_temperature(value, from_unit - 1, to_unit - 1), temperature_units[to_unit - 1].name);
                break;
            default:
                printf("Invalid choice, try again!\n");
                break;
        }
    }
    return 0;
}