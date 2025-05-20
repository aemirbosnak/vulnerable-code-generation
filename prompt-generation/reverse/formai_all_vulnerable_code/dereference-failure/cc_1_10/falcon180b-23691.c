//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count - 1] = NULL;
    return tokens;
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("SHELL> ");
    if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
        perror("fgets");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    char **args = split_string(input);
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            return 127;
        }
    } else if (pid < 0) {
        perror("fork");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}

void handle_sigint(int signum) {
    printf("\nExiting shell...\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    while (1) {
        launch_shell();
    }
    return 0;
}