//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    int fd[2];
    pid_t child_pid;
    char message[BUFFER_SIZE];
    ssize_t bytes_read;

    // Create a pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Error: Pipe creation failed\n");
        return 1;
    }

    child_pid = fork();

    // Check if fork was successful
    if (child_pid == -1) {
        fprintf(stderr, "Error: Fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process

        // Close reading end of pipe
        close(fd[0]);

        // Write message to pipe
        strcpy(message, "Hello, World!");
        write(fd[1], message, strlen(message));

        // Close writing end of pipe
        close(fd[1]);

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Close writing end of pipe
        close(fd[1]);

        // Read message from pipe
        bytes_read = read(fd[0], message, BUFFER_SIZE);

        // Check if there was an error while reading
        if (bytes_read == -1) {
            fprintf(stderr, "Error: Reading from pipe failed\n");
            return 1;
        }

        // Print received message
        message[bytes_read] = '\0';
        printf("Received message: %s\n", message);

        // Close reading end of pipe
        close(fd[0]);

        // Wait for child process to exit
        wait(NULL);
    }

    return 0;
}