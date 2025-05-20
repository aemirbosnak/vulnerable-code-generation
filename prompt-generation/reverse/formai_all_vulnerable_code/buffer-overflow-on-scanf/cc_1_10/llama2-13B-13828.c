//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// HappyUnit struct to store the unit information
typedef struct {
    char name[20]; // unit name (e.g. "centimeters")
    double conversion[MAX_CONVERTIONS]; // conversion factors for each unit
} HappyUnit;

// Function to get the user input and perform the conversion
void happy_convert(HappyUnit units[], int num_units, int conversion_index) {
    // Get the user input
    double user_input;
    printf("Enter a value for unit %d (%s): ", conversion_index + 1, units[conversion_index].name);
    scanf("%lf", &user_input);

    // Perform the conversion
    for (int i = 0; i < num_units; i++) {
        if (units[i].name == units[conversion_index].name) {
            user_input *= units[i].conversion[conversion_index];
            break;
        }
    }

    // Print the result
    printf("The value of %s is %lf %s\n", units[conversion_index].name, user_input, units[conversion_index].name);
}

int main() {
    // Initialize the HappyUnit array
    HappyUnit units[MAX_UNITS] = {
        {"centimeters", {1, 100, 1000, 10000, 100000}},
        {"meters", {1, 100, 1000, 10000, 100000}},
        {"kilometers", {1, 100, 1000, 10000, 100000}},
        {"inches", {1, 10, 100, 1000, 10000}},
        {"feet", {1, 12, 36, 60, 100}},
        {"yards", {1, 3, 9, 18, 36}}
    };

    // Prompt the user to select a unit and perform the conversion
    int num_units = sizeof(units) / sizeof(HappyUnit);
    int conversion_index = 0;
    while (conversion_index < num_units) {
        printf("Select a unit: ");
        scanf("%d", &conversion_index);
        happy_convert(units, num_units, conversion_index);
    }

    return 0;
}