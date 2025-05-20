//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_SIZE 1024

// Struct to hold the message to be sent
typedef struct {
    char message[MAX_SIZE];
    int message_len;
} Message;

int main() {
    int fd[2]; // File descriptors for the pipe
    pid_t child_pid; // Process ID of child process
    
    // Create the pipe
    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        exit(1);
    }
    
    // Fork a child process
    child_pid = fork();
    
    if (child_pid == -1) {
        printf("Fork failed\n");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]); // Close the read end of the pipe
        Message msg;
        while (1) {
            // Receive messages from the parent process
            if (read(fd[1], &msg, sizeof(msg)) == -1) {
                printf("Error reading from pipe\n");
                exit(1);
            }
            
            // Print the received message
            printf("Child received message: %s\n", msg.message);
        }
    } else {
        // Parent process
        close(fd[1]); // Close the write end of the pipe
        Message msg;
        
        // Send messages to the child process
        while (1) {
            printf("Enter message to send: ");
            scanf("%s", msg.message);
            msg.message_len = strlen(msg.message);
            
            // Send the message via the pipe
            if (write(fd[1], &msg, sizeof(msg)) == -1) {
                printf("Error writing to pipe\n");
                exit(1);
            }
        }
    }
    
    return 0;
}