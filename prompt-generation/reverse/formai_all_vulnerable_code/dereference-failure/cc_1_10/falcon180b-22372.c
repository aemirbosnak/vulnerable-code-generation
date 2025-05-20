//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

char **split_string(char *str);
pid_t fork();
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (TRUE) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input_buffer);

        if (args[0] == NULL) {
            continue;
        }

        switch (fork()) {
            case -1:
                fprintf(stderr, "Error: fork() failed\n");
                exit(EXIT_FAILURE);
            case 0:
                status = execute_command(args);
                exit(status);
            default:
                waitpid(0, &status, 0);
        }
    }

    return EXIT_SUCCESS;
}

char **split_string(char *str) {
    int count = 0;
    char **tokens = NULL;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    tokens[count - 1] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

void handle_signal(int signum) {
    pid_t pid;
    int status;

    switch (signum) {
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
            printf("\nExiting...\n");
            break;
        default:
            break;
    }

    pid = getpid();
    kill(pid, signum);

    exit(EXIT_SUCCESS);
}