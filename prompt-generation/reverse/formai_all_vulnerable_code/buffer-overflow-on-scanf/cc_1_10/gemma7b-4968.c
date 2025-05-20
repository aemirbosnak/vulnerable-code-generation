//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUM 10

typedef struct UnitConverter {
    char unit_from[MAX_CONVERT_NUM];
    char unit_to[MAX_CONVERT_NUM];
    double conversion_factor;
} UnitConverter;

UnitConverter converters[] = {
    {"kg", "g", 1000},
    {"L", "ml", 1000},
    {"km", "m", 1000},
    {"kmh", "mph", 1.613},
    {"€", "USD", 0.984},
    {"£", "USD", 0.842},
    {"€", "CHF", 1.222},
    {"CHF", "USD", 0.986}
};

int main() {
    char unit_from[MAX_CONVERT_NUM];
    char unit_to[MAX_CONVERT_NUM];
    double value;
    double converted_value;

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    for (int i = 0; i < MAX_CONVERT_NUM; i++) {
        if (strcmp(converters[i].unit_from, unit_from) == 0 && strcmp(converters[i].unit_to, unit_to) == 0) {
            converted_value = value * converters[i].conversion_factor;
            break;
        }
    }

    if (converted_value != 0) {
        printf("The converted value is: %.2lf %s\n", converted_value, unit_to);
    } else {
        printf("Error: Conversion not found.\n");
    }

    return 0;
}