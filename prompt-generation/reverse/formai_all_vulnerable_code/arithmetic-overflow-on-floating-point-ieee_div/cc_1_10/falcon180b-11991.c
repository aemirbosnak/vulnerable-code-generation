//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void print_help();
double convert(char from, char to, double value);

int main(int argc, char **argv) {
    if (argc < 4) {
        print_help();
        exit(1);
    }

    char from = argv[1][0];
    char to = argv[2][0];
    double value = atof(argv[3]);

    double result = convert(from, to, value);
    printf("%.2f %c = %.2f %c\n", value, from, result, to);

    return 0;
}

void print_help() {
    printf("Usage:./unit_converter <from_unit> <to_unit> <value>\n");
    printf("Supported units:\n");
    printf("  L - Length\n");
    printf("  W - Weight\n");
    printf("  T - Temperature\n");
}

double convert(char from, char to, double value) {
    switch (from) {
        case 'L':
            switch (to) {
                case 'L':
                    return value;
                case 'W':
                    return value * 0.453592;
                case 'T':
                    return value * 0.3048;
                default:
                    printf("Invalid conversion from %c to %c\n", from, to);
                    exit(1);
            }
        case 'W':
            switch (to) {
                case 'L':
                    return value / 0.453592;
                case 'W':
                    return value;
                case 'T':
                    return value * 0.555555;
                default:
                    printf("Invalid conversion from %c to %c\n", from, to);
                    exit(1);
            }
        case 'T':
            switch (to) {
                case 'L':
                    return value * 0.555555;
                case 'W':
                    return value / 0.555555;
                case 'T':
                    return value;
                default:
                    printf("Invalid conversion from %c to %c\n", from, to);
                    exit(1);
            }
        default:
            printf("Invalid unit %c\n", from);
            exit(1);
    }
}