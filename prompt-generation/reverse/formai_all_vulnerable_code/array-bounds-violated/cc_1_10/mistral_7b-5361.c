//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_TOKENS 64

char *tokens[MAX_NUM_TOKENS];

void parse_command(char *line) {
    char *token;
    int token_count = 0;

    token = strtok(line, " ");
    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }
    tokens[token_count] = NULL;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error: Fork failed\n");
        exit(1);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (execvp(args[0], args) < 0) {
            perror("Error: Execution failed");
            exit(1);
        }
        exit(0);
    }
}

int main() {
    char line[MAX_INPUT_SIZE];
    int i;

    printf("\nWelcome to my humble shell! I'm here to make your life easier.\n");
    printf("Feel free to enter a command, I'll be more than happy to help you out.\n");

    while (1) {
        printf("\n$ ");
        fgets(line, MAX_INPUT_SIZE, stdin);
        line[strlen(line) - 1] = '\0';
        parse_command(line);

        printf("\nYou've entered: ");
        for (i = 0; tokens[i] != NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\nExecuting command now...\n");
        execute_command(tokens);
        bzero(line, MAX_INPUT_SIZE);
    }

    return 0;
}