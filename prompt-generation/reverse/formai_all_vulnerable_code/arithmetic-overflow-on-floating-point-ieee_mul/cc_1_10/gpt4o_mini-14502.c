//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 100

typedef enum {
    LENGTH,
    WEIGHT,
    TEMPERATURE,
    VOLUME
} UnitType;

typedef struct {
    char name[20];
    double to_meter;
    double to_kg;
    double to_celsius;
    double to_liter;
} Unit;

Unit units[] = {
    {"meter", 1.0, 0.0, 0.0, 0.0},
    {"kilometer", 1000.0, 0.0, 0.0, 0.0},
    {"centimeter", 0.01, 0.0, 0.0, 0.0},
    {"millimeter", 0.001, 0.0, 0.0, 0.0},
    {"gram", 0.0, 0.001, 0.0, 0.0},
    {"kilogram", 0.0, 1.0, 0.0, 0.0},
    {"pound", 0.0, 0.453592, 0.0, 0.0},
    {"celsius", 0.0, 0.0, 1.0, 0.0},
    {"fahrenheit", 0.0, 0.0, 0.0, 0.0},
    {"liter", 0.0, 0.0, 0.0, 1.0},
    {"milliliter", 0.0, 0.0, 0.0, 0.001}
};

int num_units = sizeof(units) / sizeof(Unit);

double convert_length(double value, int from_unit, int to_unit) {
    return value * (units[from_unit].to_meter / units[to_unit].to_meter);
}

double convert_weight(double value, int from_unit, int to_unit) {
    return value * (units[from_unit].to_kg / units[to_unit].to_kg);
}

double convert_temperature(double value, char from_unit, char to_unit) {
    if (from_unit == 'C' && to_unit == 'F') {
        return value * 9.0 / 5.0 + 32;
    } else if (from_unit == 'F' && to_unit == 'C') {
        return (value - 32) * 5.0 / 9.0;
    } else {
        return value; // No conversion needed for Celsius to Celsius or Fahrenheit to Fahrenheit
    }
}

double convert_volume(double value, int from_unit, int to_unit) {
    return value * (units[from_unit].to_liter / units[to_unit].to_liter);
}

void display_menu() {
    printf("Welcome to the Magical Unit Converter!\n");
    printf("Choose the type of conversion:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    printf("5. Exit\n");
    printf("Please enter your choice (1-5): ");
}

void convert_units() {
    int choice;
    double value;
    int from_unit, to_unit;
    char temp_from_unit, temp_to_unit;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thank you for using the Magical Unit Converter! Farewell!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &value);
        
        if (choice == 1 || choice == 2 || choice == 4) {
            printf("Choose from the following units:\n");
            for (int i = 0; i < num_units; i++) {
                if (choice == 1 && (i < 4)) // Length
                    printf("%d. %s\n", i + 1, units[i].name);
                else if (choice == 2 && (i >= 4 && i < 7)) // Weight
                    printf("%d. %s\n", i - 3, units[i].name);
                else if (choice == 4 && (i == 9 || i == 10)) // Volume
                    printf("%d. %s\n", i - 8, units[i].name);
            }

            printf("Enter from unit (number): ");
            scanf("%d", &from_unit);
            printf("Enter to unit (number): ");
            scanf("%d", &to_unit);

            if (choice == 1) {
                printf("Converted value: %.2f %s\n", convert_length(value, from_unit - 1, to_unit - 1), units[to_unit - 1].name);
            } else if (choice == 2) {
                printf("Converted value: %.2f %s\n", convert_weight(value, from_unit + 3, to_unit + 3), units[to_unit + 3].name);
            } else if (choice == 4) {
                printf("Converted value: %.2f %s\n", convert_volume(value, from_unit + 8, to_unit + 8), units[to_unit + 8].name);
            }
        } else if (choice == 3) {
            printf("Enter from unit (C for Celsius / F for Fahrenheit): ");
            scanf(" %c", &temp_from_unit);
            printf("Enter to unit (C for Celsius / F for Fahrenheit): ");
            scanf(" %c", &temp_to_unit);

            printf("Converted value: %.2f %c\n", convert_temperature(value, temp_from_unit, temp_to_unit), temp_to_unit);
        }
    }
}

int main() {
    convert_units();
    return 0;
}