//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double value;
    char unit[10];
} Unit;

void convert(Unit from, Unit to, double *result) {
    double conversionFactor;

    // Predefined conversion factors
    switch (strcmp(from.unit, "m")) {
        case 0:
            switch (strcmp(to.unit, "km")) {
                case 0: conversionFactor = 0.001; break;
                case 1: conversionFactor = 1.60934; break;
                default: printf("Invalid unit conversion: from %s to %s\n", from.unit, to.unit); exit(EXIT_FAILURE);
            }
            break;
        case 1:
            switch (strcmp(to.unit, "m")) {
                case 0: conversionFactor = 1000.0; break;
                case 1: conversionFactor = 2.54; break;
                default: printf("Invalid unit conversion: from %s to %s\n", from.unit, to.unit); exit(EXIT_FAILURE);
            }
            break;
        default:
            switch (strcmp(to.unit, "m")) {
                case 0: conversionFactor = 1.0; break;
                case 1:
                    switch (strcmp(from.unit, "kg")) {
                        case 0: conversionFactor = 2.20462; break;
                        case 1: conversionFactor = 0.035274; break;
                        case 2: conversionFactor = 7.37562; break;
                        default: printf("Invalid unit conversion: from %s to %s\n", from.unit, to.unit); exit(EXIT_FAILURE);
                    }
                    break;
                case 2:
                    switch (strcmp(from.unit, "kg")) {
                        case 0: conversionFactor = 453.592; break;
                        case 1: conversionFactor = 0.453592; break;
                        case 2: conversionFactor = 1.85185; break;
                        default: printf("Invalid unit conversion: from %s to %s\n", from.unit, to.unit); exit(EXIT_FAILURE);
                    }
                    break;
                default: printf("Invalid unit conversion: from %s to %s\n", from.unit, to.unit); exit(EXIT_FAILURE);
            }
            break;
    }

    *result = from.value * conversionFactor;
}

int main(int argc, char *argv[]) {
    Unit input, output;
    double result;

    if (argc != 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sscanf(argv[1], "%lf %s", &input.value, input.unit);

    strcpy(output.unit, argv[3]);
    sscanf(argv[2], "%s", output.unit);

    convert(input, output, &result);

    printf("%.2f %s is equal to %.2f %s\n", input.value, input.unit, result, output.unit);

    return EXIT_SUCCESS;
}