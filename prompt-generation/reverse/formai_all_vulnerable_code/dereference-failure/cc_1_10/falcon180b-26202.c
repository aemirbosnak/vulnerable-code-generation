//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LEN 1024

struct command {
    char *name;
    int (*func)(int argc, char **argv);
};

int celsius_to_fahrenheit(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: celsius <temperature>\n");
        return 1;
    }

    double celsius = strtod(argv[1], NULL);
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);

    return 0;
}

int fahrenheit_to_celsius(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: fahrenheit <temperature>\n");
        return 1;
    }

    double fahrenheit = strtod(argv[1], NULL);
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

    printf("%.2f°F = %.2f°C\n", fahrenheit, celsius);

    return 0;
}

struct command commands[] = {
    {"celsius", celsius_to_fahrenheit},
    {"fahrenheit", fahrenheit_to_celsius},
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command> [<temperature>]\n", argv[0]);
        return 1;
    }

    char *command_name = argv[1];
    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        if (strcmp(commands[i].name, command_name) == 0) {
            int rc = commands[i].func(argc - 2, argv + 2);
            return rc;
        }
    }

    printf("Invalid command: %s\n", command_name);
    return 1;
}