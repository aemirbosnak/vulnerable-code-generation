//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t launch_shell(char **argv) {
    pid_t pid;

    if ((pid = fork()) == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error executing '%s': %s\n", argv[0], strerror(errno));
            exit(1);
        }
    }

    return pid;
}

void handle_sigint(int signum) {
    fprintf(stdout, "\nInterrupted by user\n");
    exit(1);
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_sigint);

    while (1) {
        fprintf(stdout, "> ");
        fflush(stdout);
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);
        if (args[0] == NULL)
            continue;

        pid = launch_shell(args);
        if (pid == -1)
            exit(1);

        waitpid(pid, NULL, 0);
    }

    return 0;
}