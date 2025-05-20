//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char *name;
    void (*func)(void);
} command_t;

command_t commands[MAX_COMMANDS];
int num_commands = 0;

void add_command(char *name, void (*func)(void)) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands.\n");
        exit(1);
    }
    commands[num_commands].name = name;
    commands[num_commands].func = func;
    num_commands++;
}

void run_command(char *cmd) {
    char *token = strtok(cmd, " ");
    if (token == NULL) {
        printf("Error: Invalid command.\n");
        return;
    }
    for (int i = 0; i < num_commands; i++) {
        if (strcmp(token, commands[i].name) == 0) {
            commands[i].func();
            return;
        }
    }
    printf("Error: Unknown command.\n");
}

void help_command(void) {
    printf("Available commands:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%s\n", commands[i].name);
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    add_command("help", help_command);
    add_command("quit", NULL);
    while (true) {
        printf("> ");
        char cmd[MAX_COMMAND_LENGTH];
        fgets(cmd, sizeof(cmd), stdin);
        run_command(cmd);
    }
    return 0;
}