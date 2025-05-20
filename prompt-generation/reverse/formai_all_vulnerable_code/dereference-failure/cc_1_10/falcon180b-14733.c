//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int num_units, i, choice, base_unit;
    char input[100], *token;
    Unit units[MAX_UNITS];

    // Initialize units
    units[0].name = "meter";
    units[0].factor = 1.0;

    units[1].name = "kilometer";
    units[1].factor = 1000.0;

    units[2].name = "gram";
    units[2].factor = 1.0;

    units[3].name = "kilogram";
    units[3].factor = 1000.0;

    units[4].name = "liter";
    units[4].factor = 1.0;

    units[5].name = "milliliter";
    units[5].factor = 0.001;

    units[6].name = "second";
    units[6].factor = 1.0;

    units[7].name = "minute";
    units[7].factor = 60.0;

    units[8].name = "hour";
    units[8].factor = 3600.0;

    units[9].name = "degree Celsius";
    units[9].factor = 1.0;

    num_units = 10;
    base_unit = 0;

    printf("Enter the base unit (0-9): ");
    scanf("%d", &base_unit);

    while (1) {
        printf("\nEnter the value to convert (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        token = strtok(input, " ");

        if (strcmp(token, "exit") == 0) {
            break;
        }

        choice = 0;
        for (i = 0; i < num_units; i++) {
            if (strcmp(token, units[i].name) == 0) {
                choice = i;
                break;
            }
        }

        if (choice == 0) {
            printf("Invalid unit.\n");
            continue;
        }

        token = strtok(NULL, " ");
        double value = strtod(token, NULL);

        for (i = 0; i < num_units; i++) {
            if (i == base_unit || i == choice) {
                continue;
            }

            double result = value * units[i].factor / units[choice].factor;
            printf("%s = %.2f %s\n", units[i].name, result, units[choice].name);
        }
    }

    return 0;
}