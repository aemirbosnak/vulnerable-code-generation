//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units we support
#define UNIT_NONE 0
#define UNIT_METRIC 1
#define UNIT_IMPERIAL 2

// Define the conversion factors
#define METRIC_TO_IMPERIAL_LENGTH(len) \
    (len * 3.28084)
#define IMPERIAL_TO_METRIC_LENGTH(len) \
    (len / 3.28084)

#define METRIC_TO_IMPERICAL_WEIGHT(wt) \
    (wt * 0.453592)
#define IMPERIAL_TO_METRIC_WEIGHT(wt) \
    (wt / 0.453592)

int main() {
    // Initialize the unit and value arrays
    int unit[3] = {UNIT_NONE, UNIT_NONE, UNIT_NONE};
    double value[3] = {0, 0, 0};

    // Get the user input
    printf("Enter the first value: ");
    scanf("%lf", &value[0]);
    printf("Enter the first unit (metric/imperial): ");
    scanf(" %c", &unit[0]);

    printf("Enter the second value: ");
    scanf("%lf", &value[1]);
    printf("Enter the second unit (metric/imperial): ");
    scanf(" %c", &unit[1]);

    // Do the conversions
    if (unit[0] == UNIT_METRIC && unit[1] == UNIT_IMPERIAL) {
        value[1] = METRIC_TO_IMPERIAL_LENGTH(value[0]);
    } else if (unit[0] == UNIT_IMPERIAL && unit[1] == UNIT_METRIC) {
        value[1] = IMPERIAL_TO_METRIC_LENGTH(value[0]);
    }

    if (unit[0] == UNIT_IMPERIAL && unit[1] == UNIT_METRIC) {
        value[0] = IMPERIAL_TO_METRIC_WEIGHT(value[0]);
    } else if (unit[0] == UNIT_METRIC && unit[1] == UNIT_IMPERIAL) {
        value[0] = METRIC_TO_IMPERICAL_WEIGHT(value[0]);
    }

    // Print the results
    printf("Value in first unit: %f %s\n", value[0], unit[0] == UNIT_METRIC ? "meters" : "feet");
    printf("Value in second unit: %f %s\n", value[1], unit[1] == UNIT_METRIC ? "meters" : "feet");

    return 0;
}