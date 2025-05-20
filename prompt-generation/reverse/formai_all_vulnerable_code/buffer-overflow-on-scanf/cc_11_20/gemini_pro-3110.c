//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

unit units[UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {"inch", 2.54},
    {"foot", 30.48},
    {"yard", 91.44},
    {"mile", 1609.34},
    {"nautical mile", 1852.0},
    {"light year", 9.461e12},
    {"parsec", 3.086e16}
};

int main() {
    printf("Welcome to the Cyberpunk Unit Converter v1.0\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        char input[100];
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  help - display this help message\n");
            printf("  list - list all available units\n");
            printf("  convert - convert a value from one unit to another\n");
            printf("  quit - exit the program\n");
        } else if (strcmp(input, "list") == 0) {
            printf("Available units:\n");
            for (int i = 0; i < UNITS; i++) {
                printf("  %s\n", units[i].name);
            }
        } else if (strcmp(input, "convert") == 0) {
            double value;
            char from[100];
            char to[100];
            printf("Enter the value to convert: ");
            scanf("%lf", &value);
            printf("Enter the unit to convert from: ");
            scanf("%s", from);
            printf("Enter the unit to convert to: ");
            scanf("%s", to);

            int fromIndex = -1;
            int toIndex = -1;
            for (int i = 0; i < UNITS; i++) {
                if (strcmp(units[i].name, from) == 0) {
                    fromIndex = i;
                }
                if (strcmp(units[i].name, to) == 0) {
                    toIndex = i;
                }
            }

            if (fromIndex == -1) {
                printf("Invalid unit: %s\n", from);
            } else if (toIndex == -1) {
                printf("Invalid unit: %s\n", to);
            } else {
                double convertedValue = value * units[fromIndex].factor / units[toIndex].factor;
                printf("%lf %s = %lf %s\n", value, from, convertedValue, to);
            }
        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}