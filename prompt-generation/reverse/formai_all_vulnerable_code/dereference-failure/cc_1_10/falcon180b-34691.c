//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Welcome to the Romantic Shell!\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input_buffer);

        if (args[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            exit(execute_command(args));
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *str) {
    int bufsize = MAX_COMMAND_LENGTH;
    int args_count = 0;
    char *token;
    char **args = malloc(sizeof(char *) * MAX_ARGUMENTS);

    char *input_copy = strdup(str);
    token = strtok(input_copy, DELIM);

    while (token!= NULL) {
        args[args_count] = token;
        args_count++;

        if (args_count >= MAX_ARGUMENTS) {
            bufsize += MAX_ARGUMENTS * sizeof(char *);
            args = realloc(args, bufsize);
        }

        token = strtok(NULL, DELIM);
    }

    args[args_count] = NULL;
    free(input_copy);

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

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

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

void handle_signal(int signum) {
    if (signum == SIGINT || signum == SIGQUIT || signum == SIGTERM) {
        printf("\nGoodbye, my love.\n");
        exit(0);
    }
}