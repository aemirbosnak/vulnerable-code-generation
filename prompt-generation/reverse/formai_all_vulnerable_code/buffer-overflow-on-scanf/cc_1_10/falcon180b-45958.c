//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERTIBLE_UNITS 10
#define MAX_CONVERSION_FACTORS 3

typedef struct {
    char name[50];
    double factor;
} unit_t;

unit_t units[MAX_CONVERTIBLE_UNITS] = {{"meters", 1.0},
                                        {"centimeters", 0.01},
                                        {"millimeters", 0.001},
                                        {"kilometers", 1000.0},
                                        {"inches", 0.0254},
                                        {"feet", 0.3048},
                                        {"yards", 0.9144},
                                        {"miles", 160934.4},
                                        {"acres", 40468564.0},
                                        {"hectares", 10000.0}};

int main() {
    char input_unit[50];
    char output_unit[50];
    double input_value, output_value;
    int num_conversions;

    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    printf("Enter the value to convert: ");
    scanf("%lf", &input_value);

    num_conversions = 0;
    for (int i = 0; i < MAX_CONVERTIBLE_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            for (int j = 0; j < MAX_CONVERSION_FACTORS; j++) {
                if (strcmp(output_unit, units[j].name) == 0) {
                    output_value = input_value * units[i].factor / units[j].factor;
                    printf("The converted value is %.2lf %s\n", output_value, output_unit);
                    num_conversions++;
                    break;
                }
            }
            if (num_conversions == 0) {
                printf("Invalid output unit\n");
            }
            break;
        }
    }

    return 0;
}