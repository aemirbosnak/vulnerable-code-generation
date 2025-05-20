//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000

enum {
    CELSIUS,
    FAHRENHEIT
} temperature_scale;

void print_usage(char *program_name) {
    printf("Usage: %s [-c|-f] temperature\n", program_name);
    printf("  -c: Celsius\n");
    printf("  -f: Fahrenheit\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    double temperature = 0;
    int scale = CELSIUS;
    char *endptr = NULL;

    if (argc < 3) {
        print_usage(argv[0]);
    }

    if (strcasecmp(argv[1], "-c") == 0) {
        scale = CELSIUS;
    } else if (strcasecmp(argv[1], "-f") == 0) {
        scale = FAHRENHEIT;
    } else {
        print_usage(argv[0]);
    }

    if (sscanf(argv[2], "%lf", &temperature)!= 1) {
        print_usage(argv[0]);
    }

    double result = 0;

    if (scale == CELSIUS) {
        result = (temperature * 9.0 / 5.0) + 32.0;
    } else if (scale == FAHRENHEIT) {
        result = (temperature - 32.0) * 5.0 / 9.0;
    }

    printf("%.2lf %s = %.2lf %s\n", temperature, argv[1], result, argv[1]);

    return 0;
}