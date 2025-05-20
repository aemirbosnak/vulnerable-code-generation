//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold unit information
typedef struct {
    char *name;
    double factor;
} unit_t;

// Array to hold all available units
unit_t units[] = {
    {"inch", 1.0},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"inch", 1.0},
    {"pound", 1.0},
    {"ounce", 0.0625},
    {"ton", 2000.0},
    {"gram", 0.001},
    {"kilogram", 1000.0},
    {"mile", 1.60934},
    {"meter", 1000.0},
    {"centimeter", 0.01},
    {" millimeter", 0.001}
};

// Function to convert between units
void convert(unit_t from, unit_t to, double value) {
    double factor = from.factor / to.factor;
    value *= factor;
    printf("Converted value: %f %s\n", value, to.name);
}

int main() {
    int choice;
    double value;

    do {
        printf("Welcome to the Unit Converter!\n");
        printf("Choose a unit to convert from: \n");
        printf("  1. Length\n");
        printf("  2. Weight\n");
        printf("  3. Time\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Choose a length unit to convert from: \n");
                printf("  1. Inch\n");
                printf("  2. Foot\n");
                printf("  3. Yard\n");
                printf("  4. Mile\n");
                scanf("%d", &choice);
                convert(units[choice - 1], units[3], value);
                break;

            case 2:
                printf("Choose a weight unit to convert from: \n");
                printf("  1. Pound\n");
                printf("  2. Ounce\n");
                printf("  3. Ton\n");
                scanf("%d", &choice);
                convert(units[choice - 1], units[2], value);
                break;

            case 3:
                printf("Choose a time unit to convert from: \n");
                printf("  1. Second\n");
                printf("  2. Minute\n");
                printf("  3. Hour\n");
                scanf("%d", &choice);
                convert(units[choice - 1], units[0], value);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}