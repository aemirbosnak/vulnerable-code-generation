//Falcon-180B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 512

typedef struct {
    char *command;
    int (*handler)(char *args);
} Command;

int execute_command(char *args) {
    printf("Executing command: %s\n", args);
    return 0;
}

int help_command(char *args) {
    printf("Available commands:\n");
    printf("  help\n");
    printf("  exit\n");
    return 0;
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    Command commands[] = {
        {"help", help_command},
        {"exit", NULL}
    };

    int num_commands = sizeof(commands) / sizeof(Command);

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);

        char *command = strtok(input_buffer, " ");
        if (command == NULL) {
            continue;
        }

        int i;
        for (i = 0; i < num_commands; i++) {
            if (strcmp(command, commands[i].command) == 0) {
                char *args = strtok(NULL, " ");
                if (args == NULL) {
                    args = "";
                }
                int result = commands[i].handler(args);
                if (result!= 0) {
                    exit(result);
                }
                break;
            }
        }

        if (i == num_commands) {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}