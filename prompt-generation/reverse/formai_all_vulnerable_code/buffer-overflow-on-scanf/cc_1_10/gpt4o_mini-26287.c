//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 256
#define WARNING_MSG "Warning! A message is about to be sent."
#define CONFIRM_MSG "Are you sure you want to proceed? (y/n): "

void parent_process() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the FIFO for writing
    if ((fd = open(FIFO_NAME, O_WRONLY)) < 0) {
        perror("open fifo");
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "[PARENT] Monitoring for issues...\n");
    sleep(1); // Simulate monitoring delay
    
    // Send messages in a paranoid fashion
    while (1) {
        fprintf(stderr, "[PARENT] %s\n", WARNING_MSG);
        fprintf(stderr, "[PARENT] Please be advised: %s", CONFIRM_MSG);

        // Read user confirmation
        char confirmation;
        scanf(" %c", &confirmation);
        
        if (confirmation == 'y') {
            strcpy(buffer, "Message from parent: All systems are functioning properly.");
            write(fd, buffer, strlen(buffer) + 1);
            fprintf(stderr, "[PARENT] Sent message: %s\n", buffer);
        } else {
            fprintf(stderr, "[PARENT] Abort! User declined message sending.\n");
        }

        sleep(2); // Wait before sending another message
    }

    close(fd);
}

void child_process() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the FIFO for reading
    if ((fd = open(FIFO_NAME, O_RDONLY)) < 0) {
        perror("open fifo");
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "[CHILD] Awaiting messages...\n");
    while (1) {
        // Read message from the FIFO
        if (read(fd, buffer, BUFFER_SIZE) > 0) {
            fprintf(stderr, "[CHILD] Received: %s\n", buffer);
            fprintf(stderr, "[CHILD] Processing message...\n");
            // Simulating processing delay
            sleep(2); 
            fprintf(stderr, "[CHILD] Done processing the message.\n");
        }
    }

    close(fd);
}

int main() {
    // Create FIFO (named pipe)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // This is the child process
        child_process();
    } else {
        // This is the parent process
        parent_process();
    }

    // Cleanup (will never reach here in this example, but just to be safe)
    unlink(FIFO_NAME);
    return 0;
}