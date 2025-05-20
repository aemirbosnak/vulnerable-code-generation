//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(1024 * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return 1;

    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(tokens[1])!= 0) {
                perror("chdir");
            }
        }
        return 1;
    } else if (strcmp(tokens[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, &status, 0);
    }

    return 1;
}

void handle_signal(int signum) {
    printf("Interrupted by signal %d\n", signum);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int running = 1;

    signal(SIGINT, handle_signal);

    while (running) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        tokens = split_string(input);
        execute_command(tokens);
    }

    return 0;
}