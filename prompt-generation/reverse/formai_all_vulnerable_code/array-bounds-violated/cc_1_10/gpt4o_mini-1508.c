//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define FIFO_PATH "/tmp/my_fifo"
#define BUFFER_SIZE 256

void cleanup() {
    unlink(FIFO_PATH);
}

void signal_handler(int signum) {
    printf("Signal %d received. Cleaning up FIFO and exiting...\n", signum);
    cleanup();
    exit(0);
}

int main() {
    pid_t pid;
    char buffer[BUFFER_SIZE];
    int fd;

    // Setting up signal handler for cleanup
    signal(SIGINT, signal_handler);
    
    // Creating the FIFO (named pipe)
    if (mkfifo(FIFO_PATH, 0666) < 0) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Forking to create a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // Child process: Reader
    if (pid == 0) {
        // Open FIFO for reading
        fd = open(FIFO_PATH, O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        while (1) {
            // Read messages from FIFO
            ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
            if (bytesRead > 0) {
                buffer[bytesRead] = '\0'; // Null-terminate the string
                printf("Reader received: %s\n", buffer);
            } else if (bytesRead == 0) {
                break; // FIFO closed
            } else {
                perror("read");
                break;
            }
        }

        close(fd);
        exit(EXIT_SUCCESS);
    }

    // Parent process: Writer
    else {
        // Open FIFO for writing
        fd = open(FIFO_PATH, O_WRONLY);
        if (fd < 0) {
            perror("open");
            cleanup();
            exit(EXIT_FAILURE);
        }

        // Send messages to the reader
        const char *messages[] = {
            "Hello, World!",
            "This is a message from the writer.",
            "Interprocess Communication via FIFO.",
            "Goodbye!"
        };

        for (int i = 0; i < 4; i++) {
            if (write(fd, messages[i], strlen(messages[i])) < 0) {
                perror("write");
                break;
            }
            sleep(1); // Simulate some delay between messages
        }

        // Close FIFO for writing
        close(fd);
        
        // Wait for the reader to finish
        wait(NULL);
    }

    // Clean up the FIFO
    cleanup();
    return EXIT_SUCCESS;
}