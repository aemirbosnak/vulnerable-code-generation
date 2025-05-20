//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 512
#define DELIM " "
#define PATH "/bin:/sbin:/usr/bin:/usr/sbin"
#define SHELL "/bin/sh"

char *command;
char **arguments;
int num_arguments;
int num_pipes;
int *pipe_fds;

void execute_command(int argc, char **argv) {
    pid_t pid;
    int status;
    for (int i = 0; i < num_arguments; i++) {
        if (strcmp(arguments[i], ">") == 0) {
            close(1);
            open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }
        else if (strcmp(arguments[i], ">>") == 0) {
            close(1);
            open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
        }
        else if (strcmp(arguments[i], "<") == 0) {
            close(0);
            open("input.txt", O_RDONLY, 0644);
        }
        else if (strcmp(arguments[i], "|") == 0) {
            pipe_fds[num_pipes++] = dup(1);
            dup2(pipe_fds[num_pipes - 1], 1);
        }
    }
    if (num_arguments == 0) {
        execlp(SHELL, SHELL, NULL);
    }
    else {
        execvp(arguments[0], arguments);
    }
    perror("Error executing command");
    exit(1);
}

int main(int argc, char **argv) {
    command = argv[1];
    num_arguments = argc - 2;
    arguments = malloc(num_arguments * sizeof(char *));
    for (int i = 0; i < num_arguments; i++) {
        arguments[i] = argv[i + 2];
    }
    num_pipes = 0;
    pipe_fds = malloc(num_arguments * sizeof(int));
    for (int i = 0; i < num_arguments; i++) {
        if (strchr(arguments[i], '|')!= NULL) {
            num_pipes++;
        }
    }
    if (num_pipes > 0) {
        pipe(pipe_fds);
    }
    execute_command(argc, argv);
    return 0;
}