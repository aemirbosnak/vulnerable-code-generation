//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_MESSAGE_LENGTH 100
#define NUM_MESSAGES 5

void childProcess(int read_fd) {
    char buffer[MAX_MESSAGE_LENGTH];
    for (int i = 0; i < NUM_MESSAGES; i++) {
        ssize_t bytesRead = read(read_fd, buffer, sizeof(buffer));
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate the string
            printf("Child received: %s\n", buffer);
        }
    }
    close(read_fd);
    exit(0);
}

void parentProcess(int write_fd) {
    char messages[NUM_MESSAGES][MAX_MESSAGE_LENGTH] = {
        "Hello from parent 1!",
        "Another message from parent 2!",
        "Parent says hi 3!",
        "Message number 4, coming through!",
        "Final message from parent 5!"
    };

    for (int i = 0; i < NUM_MESSAGES; i++) {
        write(write_fd, messages[i], strlen(messages[i]));
        printf("Parent sent: %s\n", messages[i]);
        sleep(1);  // Sleep to simulate processing time
    }
    close(write_fd);
}

int main() {
    int pipefd[2];  // Array to hold the read and write file descriptors

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close unused write end
        childProcess(pipefd[0]);
    } else {
        // Parent process
        close(pipefd[0]);  // Close unused read end
        parentProcess(pipefd[1]);
        wait(NULL);  // Wait for child process to finish
    }

    return 0;
}