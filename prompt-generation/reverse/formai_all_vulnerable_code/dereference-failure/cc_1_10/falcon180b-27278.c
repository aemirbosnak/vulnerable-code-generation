//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMANDS 100
#define DELIM " "

typedef struct {
    char **args;
    int num_args;
} command_t;

void execute_command(command_t *cmd) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork()\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(cmd->args[0], cmd->args) == -1) {
            fprintf(stderr, "Failed to execvp()\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

command_t *parse_command(char *line) {
    command_t *cmd = malloc(sizeof(command_t));
    char *token;
    int num_args = 0;

    cmd->args = malloc(MAX_COMMANDS * sizeof(char*));
    cmd->num_args = 0;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        cmd->args[num_args] = strdup(token);
        num_args++;
        if (num_args >= MAX_COMMANDS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }

    return cmd;
}

void free_command(command_t *cmd) {
    int i;

    for (i = 0; i < cmd->num_args; i++) {
        free(cmd->args[i]);
    }
    free(cmd->args);
    free(cmd);
}

int main() {
    FILE *fp;
    char line[1024];
    command_t *cmd;

    fp = fopen(".bootrc", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open.bootrc\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        cmd = parse_command(line);
        execute_command(cmd);
        free_command(cmd);
    }

    fclose(fp);
    return 0;
}