//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float factor;
} Conversion;

int main() {
    int num_conversions;
    char input_unit[MAX_NAME_LENGTH];
    char output_unit[MAX_NAME_LENGTH];
    Conversion conversions[MAX_CONVERSIONS];

    // Read in the number of conversions
    printf("Enter the number of conversions: ");
    scanf("%d", &num_conversions);

    // Read in the conversions
    printf("Enter the conversions (name, factor):\n");
    for (int i = 0; i < num_conversions; i++) {
        scanf("%s %f", conversions[i].name, &conversions[i].factor);
    }

    // Read in the input unit
    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    // Read in the output unit
    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    // Check if the input unit is supported
    int input_unit_index = -1;
    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(conversions[i].name, input_unit) == 0) {
            input_unit_index = i;
            break;
        }
    }

    if (input_unit_index == -1) {
        printf("Input unit not supported.\n");
        return 1;
    }

    // Check if the output unit is supported
    int output_unit_index = -1;
    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(conversions[i].name, output_unit) == 0) {
            output_unit_index = i;
            break;
        }
    }

    if (output_unit_index == -1) {
        printf("Output unit not supported.\n");
        return 1;
    }

    // Convert the value
    float value;
    printf("Enter the value to convert: ");
    scanf("%f", &value);

    float result = value * conversions[input_unit_index].factor / conversions[output_unit_index].factor;

    printf("%.2f %s = %.2f %s\n", value, input_unit, result, output_unit);

    return 0;
}