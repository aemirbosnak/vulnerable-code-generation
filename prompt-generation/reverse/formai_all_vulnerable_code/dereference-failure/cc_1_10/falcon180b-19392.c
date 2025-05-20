//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 512
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **arguments);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        arguments = split_command(input);

        if (arguments[0] == NULL)
            continue;

        pid = fork();
        if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++argc);
        arguments[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t fork(void) {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        return pid;
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\n");
    }
}