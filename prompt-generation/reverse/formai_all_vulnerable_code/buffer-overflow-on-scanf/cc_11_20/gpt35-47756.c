//FormAI DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>

int main() {
    float value;
    char firstUnit, secondUnit;

    printf("Enter the value you wish to convert: ");
    scanf("%f", &value);

    printf("Enter the unit of measure for the value you wish to convert (C, F, K, M, Y, I): ");
    scanf(" %c", &firstUnit);

    printf("Enter the unit of measure you want to convert to (C, F, K, M, Y, I): ");
    scanf(" %c", &secondUnit);

    if (firstUnit == secondUnit) {
        printf("The value is already in the unit of measure you want.\n");
        return 0;
    }

    if (firstUnit == 'C') {
        if (secondUnit == 'F') {
            value = value * 9 / 5 + 32;
        }
        else if (secondUnit == 'K') {
            value += 273.15;
        }
    }
    else if (firstUnit == 'F') {
        if (secondUnit == 'C') {
            value = (value - 32) * 5 / 9;
        }
        else if (secondUnit == 'K') {
            value = (value + 459.67) * 5 / 9;
        }
    }
    else if (firstUnit == 'K') {
        if (secondUnit == 'C') {
            value -= 273.15;
        }
        else if (secondUnit == 'F') {
            value = value * 9 / 5 - 459.67;
        }
    }
    else if (firstUnit == 'M') {
        if (secondUnit == 'Y') {
            value *= 1.09361;
        }
    }
    else if (firstUnit == 'Y') {
        if (secondUnit == 'M') {
            value /= 1.09361;
        }
        else if (secondUnit == 'I') {
            value *= 36;
        }
    }
    else if (firstUnit == 'I') {
        if (secondUnit == 'Y') {
            value /= 36;
        }
    }

    printf("The converted value is: %.2f %c\n", value, secondUnit);

    return 0;
}