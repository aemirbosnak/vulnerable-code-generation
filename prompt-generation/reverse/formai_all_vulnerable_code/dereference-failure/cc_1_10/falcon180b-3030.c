//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    signal(SIGINT, handle_signal);

    printf("Enter commands, type 'exit' to quit.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        arguments = split_string(input);
        pid = fork();

        if (pid == -1) {
            perror("Fork Failed");
        } else if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);

        if (argc >= MAX_ARGUMENTS) {
            break;
        }
    }

    arguments[argc] = NULL;

    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork Failed");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Exec Failed");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        fprintf(stderr, "Interrupted by user.\n");
    }
}