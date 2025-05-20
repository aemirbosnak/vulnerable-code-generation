//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <signal.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);
void handle_signal(int sig);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);
    while (true) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument for \"cd\"\n");
            return 1;
        }
        if (chdir(args[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
    } else {
        pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("\n");
    }
}