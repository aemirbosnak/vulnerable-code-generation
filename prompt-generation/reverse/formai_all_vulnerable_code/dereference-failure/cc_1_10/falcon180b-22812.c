//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100

char **arguments;
int argument_count;
char input_buffer[MAX_COMMAND_LENGTH];

void execute_command(char **command_arguments) {
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == 0) {
        if (execvp(command_arguments[0], command_arguments) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (child_pid == -1) {
        fprintf(stderr, "Error: fork failed\n");
        exit(1);
    } else {
        waitpid(child_pid, &status, 0);
    }
}

void handle_signal(int signal_number) {
    pid_t child_pid;
    int status;

    child_pid = waitpid(-1, &status, WNOHANG);
    if (child_pid > 0) {
        fprintf(stdout, "Command %d completed with status %d\n", child_pid, WEXITSTATUS(status));
    }
}

int main() {
    char *line;
    size_t buffer_size = 0;
    ssize_t read_count;

    signal(SIGCHLD, handle_signal);

    while (1) {
        fprintf(stdout, "> ");
        read_count = getline(&line, &buffer_size, stdin);
        if (read_count == -1) {
            fprintf(stderr, "Error: getline failed\n");
            exit(1);
        }
        strcpy(input_buffer, line);
        arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
        argument_count = 0;
        char *token = strtok(input_buffer, " ");
        while (token!= NULL) {
            arguments[argument_count] = token;
            argument_count++;
            token = strtok(NULL, " ");
        }
        execute_command(arguments);
    }

    return 0;
}