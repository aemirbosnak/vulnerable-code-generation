//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
void execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[1024];
    char **args;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        args = split_string(input);
        execute_command(args);
    }

    return 0;
}

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        bufsize++;
        tokens = realloc(tokens, bufsize * sizeof(char *));
        tokens[i] = token;
        i++;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed\n");
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void handle_signal(int signum) {
    printf("\n");
    exit(0);
}