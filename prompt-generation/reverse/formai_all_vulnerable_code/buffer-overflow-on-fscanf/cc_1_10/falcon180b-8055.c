//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

typedef struct {
    char name[MAX_LINE_SIZE];
    float celsius;
    float fahrenheit;
} temperature_t;

temperature_t read_temperature(FILE *file) {
    temperature_t temp;
    fscanf(file, "%s %f %f", temp.name, &temp.celsius, &temp.fahrenheit);
    return temp;
}

void write_temperature(FILE *file, temperature_t temp) {
    fprintf(file, "%s %f %f\n", temp.name, temp.celsius, temp.fahrenheit);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    temperature_t temp;
    while (fscanf(input_file, "%s %f %f", temp.name, &temp.celsius, &temp.fahrenheit) == 3) {
        temp.celsius -= 273.15;
        temp.fahrenheit = (temp.celsius * 9.0 / 5.0) + 32;
        write_temperature(output_file, temp);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}