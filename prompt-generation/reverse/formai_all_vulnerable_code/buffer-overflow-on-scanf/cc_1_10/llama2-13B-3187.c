//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 5

struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from[20];
    char to[20];
    double factor;
};

int main() {
    // Define the available units and conversions
    struct unit units[] = {
        {"meter", 1.0},
        {"centimeter", 0.01},
        {"kilometer", 1000.0},
        {" millimeter", 0.001},
        {"foot", 0.3048}
    };

    struct conversion conversions[] = {
        {"meter", "foot", 0.3048},
        {"centimeter", "inch", 0.3937},
        {"kilometer", "mile", 0.621371},
        {" millimeter", "inch", 0.0254},
        {"foot", "meter", 0.3048}
    };

    // Prompt the user for input
    printf("Enter a value in a unit: ");
    double value;
    scanf("%lf", &value);

    // Loop through the available units and conversions
    for (int i = 0; i < MAX_UNITS; i++) {
        for (int j = 0; j < MAX_CONVERTIONS; j++) {
            // Check if the input value is a valid conversion
            if (strcmp(units[i].name, conversions[j].from) == 0 &&
                    strcmp(conversions[j].to, units[i].name) == 0) {
                // Perform the conversion
                value *= conversions[j].factor;
                break;
            }
        }

        // Print the result in the original unit
        printf("Value in %s: %f\n", units[i].name, value);
    }

    return 0;
}