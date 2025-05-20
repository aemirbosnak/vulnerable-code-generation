//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split(char *str, char delimiter);
pid_t fork();
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split(input, DELIM);

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

char **split(char *str, char delimiter) {
    char **tokens;
    int count = 0;
    char *token;

    tokens = malloc(sizeof(char *));

    token = strtok(str, delimiter);
    while (token!= NULL) {
        tokens = realloc(tokens, sizeof(char *) * ++count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    return fork();
}

int execute_command(char **args) {
    int status;
    pid_t pid;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    printf("\nInterrupted by signal %d\n", signum);
}