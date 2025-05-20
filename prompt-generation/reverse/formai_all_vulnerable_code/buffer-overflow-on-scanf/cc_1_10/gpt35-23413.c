//FormAI DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>

float convert_length(float value, char* from_unit, char* to_unit);
float convert_mass(float value, char* from_unit, char* to_unit);
float convert_temperature(float value, char* from_unit, char* to_unit);
float convert_volume(float value, char* from_unit, char* to_unit);

int main() {
    float value;
    char from_unit[20], to_unit[20], unit_type;

    printf("Enter the value to be converted: ");
    scanf("%f", &value);

    printf("Enter the unit type (L - Length, M - Mass, T - Temperature, V - Volume): ");
    scanf(" %c", &unit_type);

    printf("Enter the unit to be converted from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to be converted to: ");
    scanf("%s", to_unit);

    float result;
    switch (unit_type) {
        case 'L':
            result = convert_length(value, from_unit, to_unit);
            break;
        case 'M':
            result = convert_mass(value, from_unit, to_unit);
            break;
        case 'T':
            result = convert_temperature(value, from_unit, to_unit);
            break;
        case 'V':
            result = convert_volume(value, from_unit, to_unit);
            break;
        default:
            printf("Invalid unit type\n");
            return 1;
    }

    printf("%f %s = %f %s\n", value, from_unit, result, to_unit);

    return 0;
}

float convert_length(float value, char* from_unit, char* to_unit) {
    if (strcmp(from_unit, "in") == 0 && strcmp(to_unit, "ft") == 0) {
        return value / 12;
    } else if (strcmp(from_unit, "ft") == 0 && strcmp(to_unit, "in") == 0) {
        return value * 12;
    } else if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "km") == 0) {
        return value / 1000;
    } else if (strcmp(from_unit, "km") == 0 && strcmp(to_unit, "m") == 0) {
        return value * 1000;
    } else if (strcmp(from_unit, "cm") == 0 && strcmp(to_unit, "in") == 0) {
        return value / 2.54;
    } else if (strcmp(from_unit, "in") == 0 && strcmp(to_unit, "cm") == 0) {
        return value * 2.54;
    } else {
        printf("Invalid unit\n");
        return 0;
    }
}

float convert_mass(float value, char* from_unit, char* to_unit) {
    if (strcmp(from_unit, "lb") == 0 && strcmp(to_unit, "kg") == 0) {
        return value * 0.453592;
    } else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "lb") == 0) {
        return value / 0.453592;
    } else if (strcmp(from_unit, "oz") == 0 && strcmp(to_unit, "g") == 0) {
        return value * 28.3495;
    } else if (strcmp(from_unit, "g") == 0 && strcmp(to_unit, "oz") == 0) {
        return value / 28.3495;
    } else if (strcmp(from_unit, "ton") == 0 && strcmp(to_unit, "lb") == 0) {
        return value * 2000;
    } else if (strcmp(from_unit, "lb") == 0 && strcmp(to_unit, "ton") == 0) {
        return value / 2000;
    } else {
        printf("Invalid unit\n");
        return 0;
    }
}

float convert_temperature(float value, char* from_unit, char* to_unit) {
    if (strcmp(from_unit, "C") == 0 && strcmp(to_unit, "F") == 0) {
        return (value * 9/5) + 32;
    } else if (strcmp(from_unit, "F") == 0 && strcmp(to_unit, "C") == 0) {
        return (value - 32) * 5/9;
    } else {
        printf("Invalid unit\n");
        return 0;
    }
}

float convert_volume(float value, char* from_unit, char* to_unit) {
    if (strcmp(from_unit, "gal") == 0 && strcmp(to_unit, "L") == 0) {
        return value * 3.78541;
    } else if (strcmp(from_unit, "L") == 0 && strcmp(to_unit, "gal") == 0) {
        return value / 3.78541;
    } else if (strcmp(from_unit, "in^3") == 0 && strcmp(to_unit, "mL") == 0) {
        return value * 16.3871;
    } else if (strcmp(from_unit, "mL") == 0 && strcmp(to_unit, "in^3") == 0) {
        return value / 16.3871;
    } else {
        printf("Invalid unit\n");
        return 0;
    }
}