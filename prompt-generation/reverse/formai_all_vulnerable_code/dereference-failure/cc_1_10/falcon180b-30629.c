//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

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
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: Empty command\n");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Error: Fork failed\n");
        return -1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: %s not found\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            fprintf(stdout, "\nInterrupted\n");
            break;
        case SIGQUIT:
            fprintf(stdout, "\nQuit\n");
            exit(EXIT_SUCCESS);
        case SIGTSTP:
            fprintf(stdout, "\nStopped\n");
            break;
        default:
            fprintf(stdout, "\nSignal %d received\n", signum);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTSTP, handle_signal);

    fprintf(stdout, "Ken Thompson Shell\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        argv = split_command(input);
        pid = launch_shell(argv);

        if (pid == -1) {
            continue;
        }

        fprintf(stdout, "Launched process with PID %d\n", pid);

        waitpid(pid, NULL, WNOHANG);
    }

    return 0;
}