//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 3
#define MAX_VAL 10

struct unit {
    char name[20];
    double factor;
};

struct unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36}
};

int main() {
    int choice;
    double value;
    char input[20];
    char unit_name[20];

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Choose a unit to convert: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value in inches: ");
                scanf("%lf", &value);
                printf("That's %.*f feet\n", 2, value * units[0].factor);
                break;
            case 2:
                printf("Enter a value in feet: ");
                scanf("%lf", &value);
                printf("That's %.*f inches\n", 2, value / units[0].factor);
                break;
            case 3:
                printf("Enter a value in yards: ");
                scanf("%lf", &value);
                printf("That's %.*f feet\n", 2, value * units[1].factor);
                break;
            default:
                printf("Invalid choice. Try again!\n");
                break;
        }

        printf("Now, choose a unit to convert to: ");
        scanf("%s", unit_name);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(unit_name, units[i].name) == 0) {
                printf("That's %.*f %s\n", 2, value * units[i].factor, units[i].name);
                break;
            }
        }

        printf("Would you like to convert again? (y/n): ");
        scanf(" %c", &input);

        if (input[0] == 'n') {
            break;
        }
    }

    return 0;
}