//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **arguments;
int argument_count;
pid_t pid;
int status;

void sigchld_handler(int signum) {
    while (waitpid(0, &status, WNOHANG) > 0) {
        printf("\nChild process terminated with status %d\n", WEXITSTATUS(status));
    }
}

int launch_shell() {
    char input[MAX_COMMAND_LENGTH];
    printf("\n");
    printf("Retro Shell > ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    arguments = NULL;
    argument_count = 0;

    char *token = strtok(input, DELIM);
    while (token!= NULL) {
        arguments[argument_count] = token;
        argument_count++;
        if (argument_count >= MAX_ARGUMENTS) {
            printf("\nToo many arguments. Ignoring remaining arguments.\n");
            break;
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argument_count] = NULL;

    pid = fork();

    if (pid == 0) {
        execvp(arguments[0], arguments);
        printf("\nCommand not found.\n");
        exit(1);
    } else if (pid < 0) {
        printf("\nFork failed.\n");
    } else {
        signal(SIGCHLD, sigchld_handler);
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    while (1) {
        launch_shell();
    }

    return 0;
}