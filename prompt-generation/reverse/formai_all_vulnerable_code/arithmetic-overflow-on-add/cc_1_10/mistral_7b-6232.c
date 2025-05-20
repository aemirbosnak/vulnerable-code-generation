//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <errno.h>

#define FIFO_NAME "numbers_fifo"

int main() {
    int fd_parent[2], fd_child[2], i, num_generated, num_read;
    double sum, mean;
    pid_t pid;

    // Create parent-to-child pipe
    if (pipe(fd_parent) < 0) {
        perror("pipe parent"), exit(EXIT_FAILURE);
    }

    // Create child process and child-to-parent pipe
    pid = fork();

    if (pid < 0) { // Error occurred
        perror("fork"), exit(EXIT_FAILURE);
    } else if (pid > 0) { // Parent process
        close(fd_parent[0]); // Close read end

        // Create child-to-parent pipe
        if (pipe(fd_child) < 0) {
            perror("pipe child"), exit(EXIT_FAILURE);
        }

        close(STDOUT_FILENO); // Close standard output
        dup2(fd_child[1], STDOUT_FILENO); // Redirect standard output to pipe

        // Generate random numbers and send them to the child process
        srand(time(NULL));
        num_generated = 5;
        for (i = 0; i < num_generated; i++) {
            write(fd_parent[1], &i, sizeof(int));
        }
        close(fd_parent[1]);

        wait(NULL); // Wait for the child process to finish

        // Read the calculated mean from the child process and print it
        read(fd_child[0], &sum, sizeof(double));
        mean = sum / num_generated;
        printf("Mean: %.2f\n", mean);

        close(fd_child[0]);
    } else { // Child process
        close(fd_child[1]); // Close write end

        // Read numbers from parent process and calculate their mean
        for (i = 0; i < num_generated; i++) {
            read(fd_parent[0], &i, sizeof(int));
            sum += i;
        }
        close(fd_parent[0]);

        // Send the mean back to the parent process
        write(STDOUT_FILENO, &sum, sizeof(double));

        exit(EXIT_SUCCESS);
    }

    return 0;
}