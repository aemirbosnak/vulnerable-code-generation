//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split_command(char *command);
pid_t fork();
int execute_command(char **args);
void sig_handler(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    signal(SIGTERM, sig_handler);

    while (TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);
        if (args[0] == NULL)
            continue;

        pid = fork();
        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void sig_handler(int signum) {
    printf("\nExiting...\n");
    exit(0);
}