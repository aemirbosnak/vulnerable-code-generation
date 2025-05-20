//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LEN 50
#define MAX_PARAMS 10
#define MAX_PARAM_LEN 20

typedef struct {
    char *command;
    void (*func)(char **params);
} command_t;

int num_commands = 0;
command_t commands[MAX_COMMANDS];

void add_command(char *cmd, void (*func)(char **params)) {
    commands[num_commands].command = cmd;
    commands[num_commands].func = func;
    num_commands++;
}

void execute_command(char *input) {
    char *cmd = strtok(input, " ");
    int i;

    for (i = 0; i < num_commands; i++) {
        if (strcmp(cmd, commands[i].command) == 0) {
            char **params = malloc(MAX_PARAMS * sizeof(char *));
            int j = 0;

            while ((params[j] = strtok(NULL, " "))!= NULL) {
                j++;
            }

            commands[i].func(params);
            free(params);
            return;
        }
    }

    printf("Invalid command.\n");
}

void turn_on_light(char **params) {
    printf("Turning on the light.\n");
}

void turn_off_light(char **params) {
    printf("Turning off the light.\n");
}

void set_brightness(char **params) {
    int brightness = atoi(params[0]);
    printf("Setting brightness to %d.\n", brightness);
}

int main() {
    add_command("on", turn_on_light);
    add_command("off", turn_off_light);
    add_command("set", set_brightness);

    char input[100];

    while (1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);
        execute_command(input);
    }

    return 0;
}