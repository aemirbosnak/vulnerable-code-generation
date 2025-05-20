//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_OPERATIONS 5

typedef struct unit_t {
    char name[20];
    double factor;
} unit_t;

unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"cm", 1.0},
    {"m", 100.0},
    {"km", 100000.0},
    {"mm", 0.1},
    {"in", 2.54},
    {"ft", 12.0},
    {"yd", 36.0},
    {"mi", 1609.344},
    {"km", 100000.0},
    {"lb", 0.45359237},
    {"oz", 0.0283495},
    {"kg", 0.001}
};

int main() {
    int i, j, operation;
    double value, result;
    char input[50];

    printf("Welcome to the Unit Converter! Please enter a value to convert:\n");

    // Initialize the input value
    scanf("%49s", input);

    // Initialize the operation
    operation = 0;

    // Loop until the user has entered a valid operation
    while (operation != 1 && operation != 2 && operation != 3) {
        // Display the available operations
        printf("Available operations: \n");
        for (i = 0; i < UNIT_CONVERTER_MAX_OPERATIONS; i++) {
            printf("%d) %s\n", i + 1, units[i].name);
        }

        // Get the user's operation choice
        scanf("%d", &operation);

        // Handle the user's operation choice
        switch (operation) {
            case 1:
                // Convert to the previous unit
                for (i = 0; i < UNIT_CONVERTER_MAX_UNITS - 1; i++) {
                    if (strcmp(units[i].name, input) == 0) {
                        // Calculate the conversion factor
                        result = units[i].factor / units[i + 1].factor;

                        // Convert the value
                        value = result * atof(input);

                        // Print the result
                        printf("Conversion: %s = %f %s\n", units[i].name, value, units[i + 1].name);
                        break;
                    }
                }
                break;

            case 2:
                // Convert to the next unit
                for (i = UNIT_CONVERTER_MAX_UNITS - 1; i > 0; i--) {
                    if (strcmp(units[i].name, input) == 0) {
                        // Calculate the conversion factor
                        result = units[i].factor * units[i - 1].factor;

                        // Convert the value
                        value = result * atof(input);

                        // Print the result
                        printf("Conversion: %s = %f %s\n", units[i].name, value, units[i - 1].name);
                        break;
                    }
                }
                break;

            case 3:
                // Convert to a specific unit
                for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
                    if (strcmp(units[i].name, input) == 0) {
                        // Convert the value
                        value = atof(input);

                        // Print the result
                        printf("Conversion: %s = %f %s\n", units[i].name, value, units[i].name);
                        break;
                    }
                }
                break;

            default:
                printf("Invalid operation. Please try again.\n");
                break;
        }
    }

    return 0;
}