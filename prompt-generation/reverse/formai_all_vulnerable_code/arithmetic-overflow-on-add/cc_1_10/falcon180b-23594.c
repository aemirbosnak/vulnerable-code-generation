//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

// Function to send message to parent process
void send_message_to_parent(int fd, char* message) {
    int bytes_sent = 0;
    while (bytes_sent < strlen(message)) {
        int result = write(fd, message + bytes_sent, strlen(message) - bytes_sent);
        if (result == -1) {
            printf("Error: Failed to write to pipe\n");
            exit(1);
        }
        bytes_sent += result;
    }
}

// Function to receive message from parent process
void receive_message_from_parent(int fd, char* buffer) {
    int bytes_received = 0;
    while (bytes_received < MAX_BUFFER_SIZE) {
        int result = read(fd, buffer + bytes_received, MAX_BUFFER_SIZE - bytes_received);
        if (result == -1) {
            printf("Error: Failed to read from pipe\n");
            exit(1);
        }
        if (result == 0) {
            printf("Parent process has closed the pipe\n");
            exit(0);
        }
        bytes_received += result;
    }
    buffer[bytes_received] = '\0'; // Add null terminator to the end of the message
}

int main() {
    int fd[2]; // File descriptors for pipe
    pid_t pid; // Process ID of child process

    // Create pipe
    if (pipe(fd) == -1) {
        printf("Error: Failed to create pipe\n");
        exit(1);
    }

    pid = fork(); // Fork a child process

    if (pid == -1) {
        printf("Error: Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]); // Close reading end of pipe
        send_message_to_parent(fd[1], "Hello from child process!");
        close(fd[1]); // Close writing end of pipe
        exit(0);
    } else {
        // Parent process
        close(fd[1]); // Close writing end of pipe
        char buffer[MAX_BUFFER_SIZE];
        receive_message_from_parent(fd[0], buffer);
        printf("Received message from child process: %s\n", buffer);
        close(fd[0]); // Close reading end of pipe
        exit(0);
    }

    return 0;
}