//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_VALUE 100

struct unit {
    char name[20];
    double value;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"inch", 0.01},
        {"foot", 0.03},
        {"yard", 0.1},
        {"mile", 0.00160934},
        {"cm", 0.01},
        {"m", 0.1},
        {"km", 0.001},
        {"gram", 0.001},
        {"kg", 1000},
        {"oz", 0.0283495},
        {"lb", 0.453592}
    };

    double value, converted_value;
    char input_unit[20];
    char output_unit[20];

    while (1) {
        printf("Welcome to the Unit Converter!\n");
        printf("Enter a value: ");
        scanf("%lf", &value);

        printf("Enter the unit you want to convert from: ");
        scanf("%s", input_unit);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input_unit, units[i].name) == 0) {
                converted_value = value * units[i].value;
                printf("The value in %s is %lf\n", units[i].name, converted_value);

                printf("Do you want to convert again? (y/n): ");
                scanf(" %c", &input_unit[0]);

                if (input_unit[0] == 'n') {
                    break;
                }

                printf("Enter the unit you want to convert to: ");
                scanf("%s", output_unit);

                for (int j = 0; j < MAX_UNITS; j++) {
                    if (strcmp(output_unit, units[j].name) == 0) {
                        converted_value = converted_value / units[j].value;
                        printf("The value in %s is %lf\n", units[j].name, converted_value);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}