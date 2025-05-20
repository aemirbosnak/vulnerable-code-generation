//Falcon-180B DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Initialize variables
    char *command;
    pid_t pid;
    int status;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    // Copy the command string to a new buffer
    command = strdup(argv[1]);

    // Fork a new process
    pid = fork();

    // Check for errors
    if (pid == -1) {
        printf("Fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // Child process
        execlp(command, command, NULL);

        // If execlp fails, print an error message and exit
        if (errno == ENOENT) {
            printf("Command not found: %s\n", command);
        } else {
            printf("Error executing command: %s\n", strerror(errno));
        }
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);

        // Check the exit status of the child process
        if (WIFEXITED(status)) {
            printf("Command completed with exit status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Unknown exit status\n");
        }
    }

    return 0;
}