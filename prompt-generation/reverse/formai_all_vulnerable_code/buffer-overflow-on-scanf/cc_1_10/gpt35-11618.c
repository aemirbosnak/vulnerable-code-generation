//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

// Function declarations
float convertLength(float value, char from_unit, char to_unit);
float convertWeight(float value, char from_unit, char to_unit);
float convertTemperature(float value, char from_unit, char to_unit);

// Main function
int main(void) {
    char category;
    float value;
    char from_unit, to_unit;

    printf("Welcome to the Unit Converter!\n\n");
    printf("Which category would you like to convert?\n");
    printf("(L)ength, (W)eight, or (T)emperature? ");
    scanf("%c", &category);

    switch (category) {
        case 'L':
            printf("Enter the length value: ");
            scanf("%f", &value);
            printf("Convert from (F)eet, (I)nches, or (M)eters? ");
            scanf(" %c", &from_unit);
            printf("Convert to (F)eet, (I)nches, or (M)eters? ");
            scanf(" %c", &to_unit);
            printf("%.2f %c = %.2f %c\n", value, from_unit, convertLength(value, from_unit, to_unit), to_unit);
            break;

        case 'W':
            printf("Enter the weight value: ");
            scanf("%f", &value);
            printf("Convert from (P)ounds or (K)ilograms? ");
            scanf(" %c", &from_unit);
            printf("Convert to (P)ounds or (K)ilograms? ");
            scanf(" %c", &to_unit);
            printf("%.2f %c = %.2f %c\n", value, from_unit, convertWeight(value, from_unit, to_unit), to_unit);
            break;

        case 'T':
            printf("Enter the temperature value: ");
            scanf("%f", &value);
            printf("Convert from (C)elsius or (F)ahrenheit? ");
            scanf(" %c", &from_unit);
            printf("Convert to (C)elsius or (F)ahrenheit? ");
            scanf(" %c", &to_unit);
            printf("%.2f%c = %.2f%c\n", value, from_unit, convertTemperature(value, from_unit, to_unit), to_unit);
            break;

        default:
            printf("Invalid category!\n");
            return 1;
    }

    return 0;
}

// Length conversion function
float convertLength(float value, char from_unit, char to_unit) {
    float result;

    if (from_unit == 'F' && to_unit == 'I') {
        result = value * 12;
    } else if (from_unit == 'F' && to_unit == 'M') {
        result = value * 0.3048;
    } else if (from_unit == 'I' && to_unit == 'F') {
        result = value / 12;
    } else if (from_unit == 'I' && to_unit == 'M') {
        result = value * 0.0254;
    } else if (from_unit == 'M' && to_unit == 'F') {
        result = value / 0.3048;
    } else if (from_unit == 'M' && to_unit == 'I') {
        result = value / 0.0254;
    } else {
        result = value;
    }

    return result;
}

// Weight conversion function
float convertWeight(float value, char from_unit, char to_unit) {
    float result;

    if (from_unit == 'P' && to_unit == 'K') {
        result = value / 2.20462;
    } else if (from_unit == 'K' && to_unit == 'P') {
        result = value * 2.20462;
    } else {
        result = value;
    }

    return result;
}

// Temperature conversion function
float convertTemperature(float value, char from_unit, char to_unit) {
    float result;

    if (from_unit == 'C' && to_unit == 'F') {
        result = (value * 1.8) + 32;
    } else if (from_unit == 'F' && to_unit == 'C') {
        result = (value - 32) / 1.8;
    } else {
        result = value;
    }

    return result;
}