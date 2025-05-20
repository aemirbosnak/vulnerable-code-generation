//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 100

typedef struct {
    char *cmd;
    char *args[10];
    int num_args;
} command_t;

int parse_command(char *line, command_t *cmd) {
    char *token = strtok(line, " ");
    int i = 0;

    while (token != NULL && i < 10) {
        cmd->args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    cmd->num_args = i;

    return 0;
}

int run_command(command_t *cmd) {
    if (strcmp(cmd->cmd, "echo") == 0) {
        for (int i = 1; i < cmd->num_args; i++) {
            printf("%s ", cmd->args[i]);
        }
        printf("\n");
    } else if (strcmp(cmd->cmd, "exit") == 0) {
        exit(0);
    } else {
        fprintf(stderr, "Command not found: %s\n", cmd->cmd);
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char line[MAX_CMD_LEN];
    command_t cmd;

    while (1) {
        printf("myshell> ");
        fgets(line, MAX_CMD_LEN, stdin);
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "") == 0) {
            continue;
        }

        parse_command(line, &cmd);
        run_command(&cmd);
    }

    return 0;
}