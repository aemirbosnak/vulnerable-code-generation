//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 32
#define MAX_NUM_TOKENS 100
#define MAX_COMMAND_LENGTH 64

typedef struct {
    char *name;
    char *description;
    int (*function)(int argc, char **argv);
    int min_args;
    int max_args;
} Command;

int temperature_converter(int argc, char **argv);

Command commands[] = {
    {"temperature_converter", "Convert between Celsius and Fahrenheit.", temperature_converter, 2, 2},
    {NULL, NULL, NULL, 0, 0}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    Command *c = commands;

    while (c->name!= NULL) {
        if (strcmp(command, c->name) == 0) {
            if (argc - 2 < c->min_args || argc - 2 > c->max_args) {
                printf("Invalid number of arguments for '%s'\n", command);
                return 1;
            }

            return c->function(argc - 2, argv + 2);
        }

        c++;
    }

    printf("Unknown command '%s'\n", command);
    return 1;
}

int temperature_converter(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s temperature_converter <celsius/fahrenheit> <value>\n", argv[0]);
        return 1;
    }

    char *unit = argv[1];
    double value = strtod(argv[2], NULL);

    if (strcmp(unit, "celsius") == 0) {
        double fahrenheit = (value * 9.0 / 5.0) + 32.0;
        printf("%.2f Celsius is %.2f Fahrenheit\n", value, fahrenheit);
    } else if (strcmp(unit, "fahrenheit") == 0) {
        double celsius = (value - 32.0) * 5.0 / 9.0;
        printf("%.2f Fahrenheit is %.2f Celsius\n", value, celsius);
    } else {
        printf("Invalid unit '%s'\n", unit);
        return 1;
    }

    return 0;
}