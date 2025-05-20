//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: synchronous
// Synchronous interprocess communication example program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    // Child process
    if (pid == 0) {
        // Close the write end of the pipe
        close(pipefd[1]);

        // Read from the pipe
        char buffer[100];
        int n = read(pipefd[0], buffer, 100);
        if (n == -1) {
            perror("read");
            return 1;
        }
        buffer[n] = '\0';

        // Print the message
        printf("Received message: %s\n", buffer);

        // Close the read end of the pipe
        close(pipefd[0]);
    }

    // Parent process
    else {
        // Close the read end of the pipe
        close(pipefd[0]);

        // Write to the pipe
        char message[] = "Hello, world!";
        int n = write(pipefd[1], message, strlen(message));
        if (n == -1) {
            perror("write");
            return 1;
        }

        // Close the write end of the pipe
        close(pipefd[1]);

        // Wait for the child process to terminate
        wait(NULL);
    }

    return 0;
}