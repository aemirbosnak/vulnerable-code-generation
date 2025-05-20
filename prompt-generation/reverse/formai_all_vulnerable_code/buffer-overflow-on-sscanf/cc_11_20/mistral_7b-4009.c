//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL -270
#define MAX_VAL 999
#define F_TO_C_OFFSET 32.0
#define C_TO_F_MULTIPLIER 1.8
#define C_TO_K_OFFSET 273.15
#define K_TO_C_MULTIPLIER 1.0
#define K_TO_F_MULTIPLIER 1.8

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    double input;
    double result;
    char unit_in, unit_out;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_value> <input_unit> <output_unit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (sscanf(argv[2], "%c", &unit_in) != 1) {
        fprintf(stderr, "Invalid input unit: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    if (sscanf(argv[3], "%c", &unit_out) != 1) {
        fprintf(stderr, "Invalid output unit: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    if ((unit_in != 'F' && unit_in != 'C' && unit_in != 'K') ||
        (unit_out != 'F' && unit_out != 'C' && unit_out != 'K')) {
        fprintf(stderr, "Invalid temperature units\n");
        return EXIT_FAILURE;
    }

    input = atof(argv[1]);

    if (unit_in == 'F') {
        if (input < MIN_VAL || input > MAX_VAL) {
            fprintf(stderr, "Invalid temperature value: %s°F\n", argv[1]);
            return EXIT_FAILURE;
        }
        result = C_TO_F_MULTIPLIER * (input - F_TO_C_OFFSET);
    } else if (unit_in == 'C') {
        if (input < MIN_VAL || input > MAX_VAL) {
            fprintf(stderr, "Invalid temperature value: %s°C\n", argv[1]);
            return EXIT_FAILURE;
        }
        result = input;
    } else if (unit_in == 'K') {
        if (input < MIN_VAL || input > MAX_VAL) {
            fprintf(stderr, "Invalid temperature value: %sK\n", argv[1]);
            return EXIT_FAILURE;
        }
        if (unit_out == 'F') {
            result = K_TO_F_MULTIPLIER * (input - C_TO_K_OFFSET);
        } else {
            result = input;
        }
    }

    switch (unit_out) {
        case 'F':
            printf("%.2f°F\n", result);
            break;
        case 'C':
            printf("%.2f°C\n", result);
            break;
        case 'K':
            printf("%.2fK\n", result);
            break;
    }

    return EXIT_SUCCESS;
}