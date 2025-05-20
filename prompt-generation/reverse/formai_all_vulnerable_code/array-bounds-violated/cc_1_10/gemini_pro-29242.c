//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

typedef struct {
    char *args[MAX_ARGS];
    int num_args;
    int bg;
} command;

command parse_command(char *line) {
    command cmd;
    cmd.num_args = 0;
    cmd.bg = 0;

    char *token = strtok(line, " ");
    while (token != NULL) {
        if (strcmp(token, "&") == 0) {
            cmd.bg = 1;
            break;
        }
        cmd.args[cmd.num_args++] = token;
        token = strtok(NULL, " ");
    }
    cmd.args[cmd.num_args] = NULL;

    return cmd;
}

int execute_command(command cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(cmd.args[0], cmd.args);
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        if (!cmd.bg) {
            int status;
            waitpid(pid, &status, 0);
        }
    } else {
        perror("fork");
        return -1;
    }

    return 0;
}

int main() {
    char line[1024];
    while (1) {
        printf("osh> ");
        fflush(stdout);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\n");
            exit(0);
        }
        line[strlen(line) - 1] = '\0';
        command cmd = parse_command(line);
        if (strcmp(cmd.args[0], "exit") == 0) {
            exit(0);
        }
        execute_command(cmd);
    }

    return 0;
}