//Falcon-180B DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(command, " ");
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork_and_exec(char **argv) {
    pid_t pid = fork();

    if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    }

    return pid;
}

void handle_child(int status) {
    if (WIFEXITED(status)) {
        printf("Child exited with status %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Child was terminated by signal %d\n", WTERMSIG(status));
    } else {
        printf("Child exited abnormally\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments...]\n", argv[0]);
        exit(1);
    }

    char **command_argv = split_command(argv[1]);
    pid_t child_pid = fork_and_exec(command_argv);

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    int status;
    waitpid(child_pid, &status, 0);
    handle_child(status);

    return 0;
}