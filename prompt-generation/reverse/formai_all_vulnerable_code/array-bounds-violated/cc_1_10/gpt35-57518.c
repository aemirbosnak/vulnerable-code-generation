//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process

        // Close the write end of the pipe
        close(fd[1]);

        // Read data from the pipe
        char buffer[32];
        int n = read(fd[0], buffer, sizeof(buffer));

        // Null-terminate the string
        buffer[n] = '\0';

        // Print the received message
        printf("Child received message: %s\n", buffer);

        // Close the read end of the pipe
        close(fd[0]);
    } else {
        // Parent process

        // Close the read end of the pipe
        close(fd[0]);

        // Write data to the pipe
        char *message = "Hello, child process!";
        write(fd[1], message, strlen(message));

        // Close the write end of the pipe
        close(fd[1]);

        // Wait for the child process to finish
        wait(NULL);
    }

    return 0;
}