//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define FIFO_NAME "myfifo"

int main(void) {
    int fd;
    pid_t pid;
    char buf[1024];

    // Create the FIFO
    if (mkfifo(FIFO_NAME, 0666) < 0) {
        if (errno != EEXIST) {
            perror("mkfifo");
            return EXIT_FAILURE;
        }
    }

    // Open the FIFO for reading
    if ((fd = open(FIFO_NAME, O_RDONLY)) < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Fork a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }

    // Child process writes to the FIFO
    if (pid == 0) {
        if ((fd = open(FIFO_NAME, O_WRONLY)) < 0) {
            perror("open");
            return EXIT_FAILURE;
        }

        // Write a message to the FIFO
        if (write(fd, "Hello, world!\n", 14) < 0) {
            perror("write");
            return EXIT_FAILURE;
        }

        // Close the FIFO
        if (close(fd) < 0) {
            perror("close");
            return EXIT_FAILURE;
        }

        // Exit the child process
        exit(EXIT_SUCCESS);
    }

    // Parent process reads from the FIFO
    if (pid > 0) {
        // Read a message from the FIFO
        if (read(fd, buf, sizeof(buf)) < 0) {
            perror("read");
            return EXIT_FAILURE;
        }

        // Print the message
        printf("%s", buf);

        // Close the FIFO
        if (close(fd) < 0) {
            perror("close");
            return EXIT_FAILURE;
        }

        // Wait for the child process to terminate
        if (waitpid(pid, NULL, 0) < 0) {
            perror("waitpid");
            return EXIT_FAILURE;
        }
    }

    // Unlink the FIFO
    if (unlink(FIFO_NAME) < 0) {
        perror("unlink");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}