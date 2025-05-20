//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 256

char *tokens[MAX_NUM_TOKENS];
char input[MAX_INPUT_SIZE];
char *token;
int status;
int num_tokens;

void parse_input(char *line) {
    num_tokens = 0;
    token = strtok(line, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
}

void execute_command(char **args) {
    pid_t pid;
    int wstatus;

    pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        printf("Error: %s: command not found\n", args[0]);
        exit(1);
    } else if (pid < 0) {
        // Error forking
        printf("Error forking process: %d\n", pid);
    } else {
        // Parent process
        waitpid(pid, &wstatus, 0);
        WIFEXITED(wstatus) ? (status = WEXITSTATUS(wstatus)) : (status = 1);
    }
}

int main() {
    char *args[MAX_NUM_TOKENS];
    int i;

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0';

        parse_input(input);
        for (i = 0; i < num_tokens; i++) {
            args[i] = tokens[i];
        }
        args[num_tokens] = NULL;

        execute_command(args);

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }
    }

    return 0;
}