//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define NUM_UNITS 8

typedef struct {
    char name[20];
    double conversion_factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"Centimeters", 0.01},
    {"Meters", 1},
    {"Kilometers", 1000},
    {"Milliliters", 0.001},
    {"Liters", 1},
    {"Gallons", 3.78541},
    {"Pounds", 0.453592},
    {"Stones", 6.35029}
};

void print_units() {
    printf("\nChoose the unit you want to convert FROM:\n");
    for (int i = 0; i < NUM_UNITS; ++i) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
}

void print_conversion(Unit *from, Unit *to, double value) {
    double result = value * (from->conversion_factor / to->conversion_factor);

    printf("\nYou asked the oracle to convert %s %s into %s.\n",
           from->name, value > 0 ? "of" : "for", to->name);
    printf("The answer, revealed by the mystic forces, is %s %s.\n",
           to->name, result > 0 ? "" : "-", result);
}

int main() {
    char input[MAX_INPUT];
    int from_index, to_index;
    double value;

    while (1) {
        print_units();
        scanf("%d%s%s", &from_index, input, input);

        if (from_index > NUM_UNITS || from_index < 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        from_index--;

        Unit *from = units + from_index;

        printf("Now, choose the unit you want to convert TO:\n");
        print_units();
        scanf("%d%s%s", &to_index, input, input);

        if (to_index > NUM_UNITS || to_index < 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        to_index--;

        Unit *to = units + to_index;

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        print_conversion(from, to, value);
    }

    return 0;
}