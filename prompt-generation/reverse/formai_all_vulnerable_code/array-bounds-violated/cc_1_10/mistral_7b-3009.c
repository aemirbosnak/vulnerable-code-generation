//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void parse_input(char **tokens, char *input) {
    char *token;
    int i = 0;

    tokens[i++] = strtok(input, " ");

    while ((token = strtok(NULL, " ")) != NULL) {
        tokens[i++] = token;
    }

    tokens[i] = NULL;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;
    int i;

    if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1]) != 0) {
            perror("Error changing directory");
        }
        return;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        perror("Error forking process");
        exit(1);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_NUM_TOKENS];

    while (1) {
        printf("Shell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0';

        parse_input(tokens, input);

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        execute_command(tokens);
    }

    return 0;
}