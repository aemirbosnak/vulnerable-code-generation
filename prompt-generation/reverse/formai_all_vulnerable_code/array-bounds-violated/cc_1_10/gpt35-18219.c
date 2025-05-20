//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE 80 /* The maximum length command */

void handle_signal(int signal_number) {
    if (signal_number == SIGINT) {
        printf("\nShell: Received signal %d - User interrupt.\n", signal_number);
    }
}

int split_input(char *input, char **args, char *delim) {
    int i = 0;
    char *token;

    token = strtok(input, delim);
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, delim);
    }
    args[i] = NULL;

    return i;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        printf("Shell: Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) < 0) {
            printf("Shell: Failed to execute command.\n");
        }
        exit(0);
    } else {
        /* Parent process */
        waitpid(pid, &status, 0);
    }
}

int main(void) {
    char *args[MAX_LINE/2 + 1];
    char input[MAX_LINE];
    char *delim = " \t\n"; /* Separate tokens by spaces, tabs, or newline */
    int should_run = 1;
    int num_args;

    /* Set up signal handler */
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Shell: Error setting up signal handler");
        exit(1);
    }

    while (should_run) {
        printf("Shell: ");
        fflush(stdout);

        fgets(input, MAX_LINE, stdin);

        /* Remove trailing newline */
        input[strlen(input) - 1] = '\0';

        num_args = split_input(input, args, delim);

        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
        } else if (num_args > 0) {
            execute_command(args);
        }
    }

    return 0;
}