//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

// Parent process writes to pipe
void parent_write(int fd) {
    char buffer[MAX_SIZE];
    int bytes_read;
    while (1) {
        printf("Enter message: ");
        fgets(buffer, MAX_SIZE, stdin);
        bytes_read = strlen(buffer);
        // Remove newline character
        buffer[bytes_read - 1] = '\0';
        write(fd, buffer, bytes_read);
    }
}

// Child process reads from pipe
void child_read(int fd) {
    char buffer[MAX_SIZE];
    int bytes_read;
    while (1) {
        bytes_read = read(fd, buffer, MAX_SIZE);
        if (bytes_read == 0) {
            printf("Parent process has exited\n");
            exit(0);
        }
        buffer[bytes_read - 1] = '\0';
        printf("Message from parent: %s\n", buffer);
    }
}

int main() {
    int fd[2];
    pid_t pid;

    // Create pipe
    if (pipe(fd) == -1) {
        printf("Pipe creation failed: %s\n", strerror(errno));
        exit(1);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        printf("Fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]);
        child_read(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        parent_write(fd[0]);
        wait(NULL);
    }

    return 0;
}