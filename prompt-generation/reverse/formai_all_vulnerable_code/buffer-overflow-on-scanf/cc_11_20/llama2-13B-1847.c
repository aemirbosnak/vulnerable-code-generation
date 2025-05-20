//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 5

struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"m", 1.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"km", 1000.0},
        {"mi", 1609.34}
    };

    struct conversion conversions[MAX_CONVERTIONS] = {
        {"m", "cm", 100.0},
        {"cm", "mm", 10.0},
        {"mm", "m", 0.1},
        {"m", "km", 0.001},
        {"km", "mi", 0.621371}
    };

    int choice;
    double value;
    char unit_from[20];
    char unit_to[20];

    while (1) {
        printf("Unit Converter\n");
        printf("Enter a value: ");
        scanf("%lf", &value);

        printf("Enter the unit from which you want to convert (m, cm, mm, km, mi): ");
        scanf("%19s", unit_from);

        printf("Enter the unit to which you want to convert (m, cm, mm, km, mi): ");
        scanf("%19s", unit_to);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, unit_from) == 0) {
                value *= units[i].factor;
                break;
            }
        }

        for (int i = 0; i < MAX_CONVERTIONS; i++) {
            if (strcmp(conversions[i].from_unit, unit_from) == 0 &&
                    strcmp(conversions[i].to_unit, unit_to) == 0) {
                value *= conversions[i].factor;
                break;
            }
        }

        printf("Value in unit %s is %lf\n", unit_to, value);

        choice = 0;
        while (choice != 4) {
            printf("Enter a choice (1-4): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter another value: ");
                    scanf("%lf", &value);
                    break;
                case 2:
                    printf("Enter another unit from (m, cm, mm, km, mi): ");
                    scanf("%19s", unit_from);
                    break;
                case 3:
                    printf("Enter another unit to (m, cm, mm, km, mi): ");
                    scanf("%19s", unit_to);
                    break;
                case 4:
                    printf("Exit\n");
                    break;
            }
        }
    }

    return 0;
}