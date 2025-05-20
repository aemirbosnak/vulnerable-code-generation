//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
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
    // Initialize unit array
    struct unit units[MAX_UNITS] = {
        {"second", 1},
        {"minute", 60},
        {"hour", 3600},
        {"day", 86400},
        {"week", 604800},
        {"month", 2419200},
        {"year", 31536000}
    };

    // Initialize conversion array
    struct conversion conversions[MAX_CONVERTIONS] = {
        {"second", "minute", 1},
        {"minute", "hour", 60},
        {"hour", "day", 3600},
        {"day", "week", 86400},
        {"week", "month", 604800},
        {"month", "year", 2419200}
    };

    // Get input from user
    char input_unit[20];
    char output_unit[20];
    double input_value;

    printf("Enter a value and the unit you want to convert it to: ");
    scanf("%lf %s %s", &input_value, input_unit, output_unit);

    // Find the correct conversion factors
    struct conversion *conversion = NULL;
    for (int i = 0; i < MAX_CONVERTIONS; i++) {
        if (strcmp(input_unit, conversions[i].from_unit) == 0) {
            conversion = &conversions[i];
            break;
        }
    }

    if (conversion == NULL) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Calculate the result
    double result = input_value * conversion->factor;

    // Print the result in the desired unit
    printf("The value of %lf %s is %lf %s\n", input_value, input_unit, result, output_unit);

    return 0;
}