//Falcon-180B DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024

void error_handler(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int fd[2];
    pid_t child_pid;
    char buffer[MAX_LINE_SIZE];
    ssize_t bytes_read;
    char *command = "ls";
    char *args[3] = {command, NULL};

    if (pipe(fd) == -1) {
        error_handler("Failed to create pipe");
    }

    child_pid = fork();
    if (child_pid == -1) {
        error_handler("Failed to fork");
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execvp(command, args);
        error_handler("Failed to execute command");
    } else {
        // Parent process
        close(fd[1]);
        bytes_read = read(fd[0], buffer, MAX_LINE_SIZE);
        if (bytes_read == -1) {
            error_handler("Failed to read from pipe");
        } else {
            buffer[bytes_read] = '\0';
            printf("Output from command: %s\n", buffer);
        }
        close(fd[0]);
        waitpid(child_pid, NULL, 0);
    }

    return 0;
}