//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define F_TO_C(x) ((x) - 32.0) * 5.0 / 9.0
#define C_TO_F(x) ((x) * 9.0 / 5.0) + 32.0

void print_usage(void) {
    printf("Usage: temp_conv <temperature> <unit> <output_unit>\n");
    printf("       where temperature is a number, unit is either F or C,\n");
    printf("       and output_unit is either F or C.\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    double temperature, result;
    char unit_in, unit_out;

    if (argc != 4) {
        print_usage();
    }

    unit_in = argv[1][0];
    temperature = strtod(argv[1] + 1, NULL);

    if (unit_in != 'F' && unit_in != 'C') {
        print_usage();
    }

    unit_out = argv[3][0];

    if (unit_out != 'F' && unit_out != 'C') {
        print_usage();
    }

    if (unit_in == 'F') {
        result = F_TO_C(temperature);
        if (unit_out == 'F') {
            printf("%.2f F is %.2f C\n", temperature, result);
        } else {
            printf("%.2f F is %.2f C\n", temperature, C_TO_F(result));
        }
    } else {
        result = C_TO_F(temperature);
        if (unit_out == 'F') {
            printf("%.2f C is %.2f F\n", temperature, result);
        } else {
            printf("%.2f C is %.2f C\n", temperature, result);
        }
    }

    return EXIT_SUCCESS;
}