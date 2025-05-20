//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

typedef enum {
    C,
    F
} temperature_unit;

typedef struct {
    char *name;
    temperature_unit unit;
} temperature_converter;

temperature_converter converters[] = {
    {"celsius", C},
    {"fahrenheit", F}
};

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <temperature> <unit>\n", argv[0]);
        return 1;
    }

    char *temperature_str = argv[1];
    temperature_unit unit = C;

    for (int i = 0; i < MAX_ARGUMENTS; i++) {
        if (strcmp(argv[i + 2], "-c") == 0 || strcmp(argv[i + 2], "--celsius") == 0) {
            unit = C;
        } else if (strcmp(argv[i + 2], "-f") == 0 || strcmp(argv[i + 2], "--fahrenheit") == 0) {
            unit = F;
        } else if (i + 2 == argc) {
            break;
        } else {
            printf("Invalid argument: %s\n", argv[i + 2]);
            return 1;
        }
    }

    double temperature = strtod(temperature_str, NULL);

    for (int i = 0; i < MAX_COMMAND_LENGTH; i++) {
        if (converters[i].unit == unit) {
            printf("%s: %.2f\n", converters[i].name, temperature);
            break;
        }
    }

    return 0;
}