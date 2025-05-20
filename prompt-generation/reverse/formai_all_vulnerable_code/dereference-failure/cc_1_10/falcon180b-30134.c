//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMANDS 10

typedef struct {
    char *command;
    void (*func)(void);
} command_t;

void help(void) {
    printf("Available commands:\n");
    printf("  help\n");
    printf("  celsius\n");
    printf("  fahrenheit\n");
    printf("  kelvin\n");
}

void celsius(void) {
    printf("Celsius\n");
}

void fahrenheit(void) {
    printf("Fahrenheit\n");
}

void kelvin(void) {
    printf("Kelvin\n");
}

int main(int argc, char **argv) {
    char input[MAX_LINE_LENGTH];
    command_t commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands++] = (command_t) {"help", help};
    commands[num_commands++] = (command_t) {"celsius", celsius};
    commands[num_commands++] = (command_t) {"fahrenheit", fahrenheit};
    commands[num_commands++] = (command_t) {"kelvin", kelvin};

    printf("Cyberpunk Temperature Converter\n");
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *command = strtok(input, " ");
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(command, commands[i].command) == 0) {
                (*commands[i].func)();
                break;
            }
        }
    }

    return 0;
}