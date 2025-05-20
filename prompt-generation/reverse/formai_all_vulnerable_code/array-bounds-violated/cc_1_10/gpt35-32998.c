//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARG_LEN 50
#define MAX_ARGS 20
#define MAX_CMD_LEN 100

char* args[MAX_ARGS];

void parse_cmd(char* cmd) {
    char* token = strtok(cmd, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGS) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

void execute_cmd() {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Command not found: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        printf("Error forking process\n");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char cmd[MAX_CMD_LEN];
    while (1) {
        printf(">> ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        cmd[strlen(cmd)-1] = '\0'; // remove trailing newline
        parse_cmd(cmd);
        execute_cmd();
    }
    return 0;
}