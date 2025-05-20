//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

// This function prints an error message and exits the program
void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    // Create a pipe for IPC
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        handleError("Failed to create pipe");
    }

    // Fork a new process
    pid_t pid = fork();
    if (pid < 0) {
        handleError("Fork failed");
    }

    // Child process
    if (pid == 0) {
        // Close write end of pipe as we only read
        close(pipe_fd[1]);

        char buffer[BUFFER_SIZE];
        // Read message from parent process
        ssize_t num_bytes = read(pipe_fd[0], buffer, sizeof(buffer));
        if (num_bytes < 0) {
            handleError("Failed to read from pipe");
        }
        
        // Null terminate the string
        buffer[num_bytes] = '\0';

        printf("Child process received: %s\n", buffer);

        // Close read end before exiting
        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);
    } 

    // Parent process
    // Close read end of pipe as we only write
    close(pipe_fd[0]);

    // Prepare a message to send to the child
    const char *message = "Hello from parent process!";
    
    // Write message to the pipe
    if (write(pipe_fd[1], message, strlen(message)) < 0) {
        handleError("Failed to write to pipe");
    }

    // Close write end of pipe after sending the message
    close(pipe_fd[1]);

    // Wait for the child process to finish
    wait(NULL);

    printf("Parent process finished.\n");
    return 0;
}