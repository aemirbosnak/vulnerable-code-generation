//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

// Function to send data using pipe
void send_data(int fd, char *data, int size) {
    int sent = 0;
    while (sent < size) {
        int ret = write(fd, data + sent, size - sent);
        if (ret <= 0) {
            if (errno!= EINTR) {
                printf("Error writing to pipe: %s\n", strerror(errno));
                exit(1);
            }
        }
        sent += ret;
    }
}

// Function to receive data using pipe
void receive_data(int fd, char *data, int size) {
    int received = 0;
    while (received < size) {
        int ret = read(fd, data + received, size - received);
        if (ret <= 0) {
            if (errno!= EINTR) {
                printf("Error reading from pipe: %s\n", strerror(errno));
                exit(1);
            }
        }
        received += ret;
    }
}

// Function to spawn a child process and communicate with it using pipes
void communicate_with_child(int *fd, char *data, int size) {
    pid_t child_pid;
    int ret;

    // Create pipes
    ret = pipe(fd);
    if (ret == -1) {
        printf("Error creating pipe: %s\n", strerror(errno));
        exit(1);
    }

    // Spawn child process
    child_pid = fork();
    if (child_pid == -1) {
        printf("Error forking: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]); // Close reading end of pipe
        send_data(fd[1], data, size); // Send data through pipe
        close(fd[1]); // Close writing end of pipe
        exit(0);
    } else {
        // Parent process
        close(fd[1]); // Close writing end of pipe
        receive_data(fd[0], data, size); // Receive data through pipe
        close(fd[0]); // Close reading end of pipe
    }
}

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int fd[2];

    while (1) {
        printf("Enter data to send: ");
        fgets(input, MAX_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        communicate_with_child(fd, input, strlen(input));

        printf("Received data: %s\n", output);
    }

    return 0;
}