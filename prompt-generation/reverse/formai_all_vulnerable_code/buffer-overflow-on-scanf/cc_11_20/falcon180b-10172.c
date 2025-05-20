//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} unit;

#define MAX_UNITS 10

unit units[MAX_UNITS] = {
    {"km", 1000},
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"mi", 160934.4},
    {"yd", 1093.61},
    {"ft", 3.28084},
    {"in", 0.083333},
    {"l", 1000},
    {"ml", 1}
};

int main() {
    int choice, i;
    double value, result;
    char unit_name[10];

    printf("Welcome to the Unit Converter!\n");
    printf("Enter 1 to convert length units.\n");
    printf("Enter 2 to convert volume units.\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the value to convert: ");
        scanf("%lf", &value);
        printf("Enter the input unit: ");
        scanf("%s", unit_name);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(unit_name, units[i].name) == 0) {
                break;
            }
        }

        printf("Enter the output unit: ");
        scanf("%s", unit_name);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(unit_name, units[i].name) == 0) {
                result = value * units[i].factor;
                printf("%lf %s is equal to %lf %s.\n", value, unit_name, result, units[i].name);
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter the value to convert: ");
        scanf("%lf", &value);
        printf("Enter the input unit: ");
        scanf("%s", unit_name);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(unit_name, units[i].name) == 0) {
                break;
            }
        }

        printf("Enter the output unit: ");
        scanf("%s", unit_name);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(unit_name, units[i].name) == 0) {
                result = value * units[i].factor;
                printf("%lf %s is equal to %lf %s.\n", value, unit_name, result, units[i].name);
                break;
            }
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}