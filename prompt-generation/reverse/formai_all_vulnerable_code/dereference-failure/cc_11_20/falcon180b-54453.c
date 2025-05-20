//Falcon-180B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
} Command;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        exit(1);
    }

    FILE *config_file = fopen(argv[1], "r");
    if (config_file == NULL) {
        printf("Error opening config file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    Command commands[MAX_ARGUMENTS];
    int num_commands = 0;

    while (fgets(line, MAX_LINE_LENGTH, config_file)!= NULL) {
        if (num_commands >= MAX_ARGUMENTS) {
            printf("Error: too many commands in config file.\n");
            exit(1);
        }

        char *command_line = strtok(line, " ");
        if (command_line == NULL) {
            continue;
        }

        commands[num_commands].command = command_line;
        commands[num_commands].num_arguments = 0;

        char *argument = strtok(NULL, " ");
        while (argument!= NULL) {
            if (commands[num_commands].num_arguments >= MAX_ARGUMENTS) {
                printf("Error: too many arguments for command.\n");
                exit(1);
            }

            commands[num_commands].arguments[commands[num_commands].num_arguments] = argument;
            commands[num_commands].num_arguments++;

            argument = strtok(NULL, " ");
        }

        num_commands++;
    }

    fclose(config_file);

    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            printf("Error forking process.\n");
            exit(1);
        } else if (pid == 0) {
            char **args = malloc(sizeof(char *) * (commands[i].num_arguments + 2));
            args[0] = commands[i].command;
            for (int j = 0; j < commands[i].num_arguments; j++) {
                args[j + 1] = commands[i].arguments[j];
            }
            args[commands[i].num_arguments + 1] = NULL;

            execvp(commands[i].command, args);
            printf("Error executing command '%s'.\n", commands[i].command);
            exit(1);
        }
    }

    wait(NULL);

    return 0;
}