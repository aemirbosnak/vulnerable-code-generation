//Falcon-180B DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define MAX_COMMAND_LEN 256
#define MAX_ARG_LEN 64

typedef struct {
    char *command;
    char *args[MAX_ARG_LEN];
    int num_args;
} command_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        exit(1);
    }

    FILE *config_file = fopen(argv[1], "r");
    if (config_file == NULL) {
        printf("Error opening config file: %s\n", strerror(errno));
        exit(1);
    }

    char line[MAX_LINE_LEN];
    command_t commands[MAX_COMMAND_LEN];
    int num_commands = 0;

    while (fgets(line, MAX_LINE_LEN, config_file)!= NULL) {
        char *command = strtok(line, " ");
        if (command == NULL) {
            continue;
        }

        command_t *cmd = &commands[num_commands];
        cmd->command = command;
        cmd->num_args = 0;

        char *arg = strtok(NULL, " ");
        while (arg!= NULL) {
            if (cmd->num_args >= MAX_ARG_LEN) {
                printf("Error: Too many arguments for command '%s'\n", command);
                exit(1);
            }

            cmd->args[cmd->num_args] = arg;
            cmd->num_args++;

            arg = strtok(NULL, " ");
        }

        num_commands++;
    }

    fclose(config_file);

    for (int i = 0; i < num_commands; i++) {
        command_t *cmd = &commands[i];

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error forking: %s\n", strerror(errno));
            exit(1);
        } else if (pid == 0) {
            if (execvp(cmd->command, cmd->args) == -1) {
                printf("Error executing command '%s': %s\n", cmd->command, strerror(errno));
                exit(1);
            }
        }
    }

    return 0;
}