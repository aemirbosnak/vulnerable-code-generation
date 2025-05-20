//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define NUM_UNITS 7

struct unit_conversion {
    char *name;
    double factor;
};

struct unit_conversion units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"milliliters", 0.001},
    {"seconds", 1.0}
};

int main() {
    int choice;
    double value, result;

    printf("Welcome to the unit converter!\n");
    printf("Please select a unit:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter a value to convert:\n");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = value * units[0].factor;
            printf("%lf meters is %lf kilometers.\n", value, result);
            break;
        case 2:
            result = value / units[0].factor;
            printf("%lf kilometers is %lf meters.\n", value, result);
            break;
        case 3:
            result = value * units[1].factor;
            printf("%lf grams is %lf kilograms.\n", value, result);
            break;
        case 4:
            result = value / units[1].factor;
            printf("%lf kilograms is %lf grams.\n", value, result);
            break;
        case 5:
            result = value * units[2].factor;
            printf("%lf liters is %lf milliliters.\n", value, result);
            break;
        case 6:
            result = value / units[2].factor;
            printf("%lf milliliters is %lf liters.\n", value, result);
            break;
        case 7:
            result = value;
            printf("%lf seconds is %lf seconds.\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}