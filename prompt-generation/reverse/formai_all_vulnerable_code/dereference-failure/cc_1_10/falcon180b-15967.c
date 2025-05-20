//Falcon-180B DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **build_argv(char *command) {
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

int launch_shell(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "execvp failed: %s\n", strerror(errno));
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    argv = build_argv(input);

    if (launch_shell(argv)!= 0) {
        fprintf(stderr, "Failed to launch shell\n");
        return 1;
    }

    return 0;
}