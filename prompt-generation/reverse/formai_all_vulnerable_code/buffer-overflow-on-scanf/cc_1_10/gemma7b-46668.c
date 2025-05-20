//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct Conversion {
    float value;
    char unit;
    char target_unit;
} Conversion;

Conversion convert_temperature(float value, char unit, char target_unit) {
    Conversion conversion;
    conversion.value = value;
    conversion.unit = unit;
    conversion.target_unit = target_unit;

    switch (unit) {
        case 'C':
            switch (target_unit) {
                case 'F':
                    conversion.value = (value * 1.8) + 32;
                    break;
                case 'K':
                    conversion.value = value + 273.15;
                    break;
            }
            break;
        case 'F':
            switch (target_unit) {
                case 'C':
                    conversion.value = (value - 32) * 5 / 9;
                    break;
                case 'K':
                    conversion.value = (value - 32) * 5 / 9 + 273.15;
                    break;
            }
            break;
        case 'K':
            switch (target_unit) {
                case 'C':
                    conversion.value = value - 273.15;
                    break;
                case 'F':
                    conversion.value = (value - 273.15) * 9 / 5 + 32;
                    break;
            }
            break;
    }

    return conversion;
}

int main() {
    float value;
    char unit, target_unit;

    printf("Enter the value:");
    scanf("%f", &value);

    printf("Enter the unit:");
    scanf(" %c", &unit);

    printf("Enter the target unit:");
    scanf(" %c", &target_unit);

    Conversion conversion = convert_temperature(value, unit, target_unit);

    printf("The converted value is: %.2f %s", conversion.value, conversion.target_unit);

    return 0;
}