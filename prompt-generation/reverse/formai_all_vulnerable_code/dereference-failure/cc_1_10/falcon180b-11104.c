//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LEN 100

typedef struct {
    char *unit;
    double offset;
    double scale;
} TemperatureUnit;

TemperatureUnit celsius = {"C", 0, 1};
TemperatureUnit fahrenheit = {"F", 32, 1.8};
TemperatureUnit kelvin = {"K", 273.15, 1};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        fclose(in_file);
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, in_file)!= NULL) {
        char *input_unit = strtok(line, " ");
        double input_temp = strtod(strtok(NULL, " "), NULL);

        TemperatureUnit *output_unit = &celsius;
        double output_temp;

        if (strcmp(input_unit, "C") == 0) {
            output_unit = &celsius;
        } else if (strcmp(input_unit, "F") == 0) {
            output_unit = &fahrenheit;
        } else if (strcmp(input_unit, "K") == 0) {
            output_unit = &kelvin;
        } else {
            printf("Invalid input unit: %s\n", input_unit);
            continue;
        }

        output_temp = (input_temp - output_unit->offset) / output_unit->scale;

        fprintf(out_file, "%.2f %c\n", output_temp, output_unit->unit[0]);
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}