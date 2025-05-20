//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 10
#define MAX_ARGUMENTS 10
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

int parse_command(char *line, Command *cmd);
void execute_command(Command *cmd);
void print_help();

int main() {
    char line[MAX_LINE_LENGTH];
    Command cmd;

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        if (parse_command(line, &cmd) == 0) {
            execute_command(&cmd);
        }
    }

    return 0;
}

int parse_command(char *line, Command *cmd) {
    char *token, *saveptr;
    int i = 0;

    token = strtok_r(line, " ", &saveptr);
    if (token == NULL) {
        return -1;
    }
    cmd->command = strdup(token);

    while ((token = strtok_r(NULL, " ", &saveptr))!= NULL) {
        if (i >= MAX_ARGUMENTS) {
            break;
        }
        cmd->arguments[i] = strdup(token);
        i++;
    }
    cmd->num_arguments = i;

    return 0;
}

void execute_command(Command *cmd) {
    if (strcmp(cmd->command, "help") == 0) {
        print_help();
    } else if (strcmp(cmd->command, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid command: %s\n", cmd->command);
    }
}

void print_help() {
    printf("Available commands:\n");
    printf("  help\n");
    printf("  quit\n");
}