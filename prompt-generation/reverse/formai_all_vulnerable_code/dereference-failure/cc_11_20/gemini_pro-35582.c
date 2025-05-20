//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Usage: %s <temperature> <from-unit> <to-unit>\n", argv[0]);
        return 1;
    }

    double temperature = atof(argv[1]);
    char* from_unit = argv[2];
    char* to_unit = argv[3];

    double converted_temperature;

    if (strcmp(from_unit, "C") == 0) {
        if (strcmp(to_unit, "F") == 0) {
            converted_temperature = temperature * 9 / 5 + 32;
        } else if (strcmp(to_unit, "K") == 0) {
            converted_temperature = temperature + 273.15;
        } else {
            printf("Invalid unit: %s\n", to_unit);
            return 1;
        }
    } else if (strcmp(from_unit, "F") == 0) {
        if (strcmp(to_unit, "C") == 0) {
            converted_temperature = (temperature - 32) * 5 / 9;
        } else if (strcmp(to_unit, "K") == 0) {
            converted_temperature = (temperature - 32) * 5 / 9 + 273.15;
        } else {
            printf("Invalid unit: %s\n", to_unit);
            return 1;
        }
    } else if (strcmp(from_unit, "K") == 0) {
        if (strcmp(to_unit, "C") == 0) {
            converted_temperature = temperature - 273.15;
        } else if (strcmp(to_unit, "F") == 0) {
            converted_temperature = (temperature - 273.15) * 9 / 5 + 32;
        } else {
            printf("Invalid unit: %s\n", to_unit);
            return 1;
        }
    } else {
        printf("Invalid unit: %s\n", from_unit);
        return 1;
    }

    printf("%.2f %s = %.2f %s\n", temperature, from_unit, converted_temperature, to_unit);

    return 0;
}