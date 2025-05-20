//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 32

int main() {
    int pipe_fd[2];
    pid_t pid;
    int numbers_to_send = 10;

    // Create the pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    // Create a child process
    if ((pid = fork()) == -1) {
        perror("fork");
        return 1;
    }

    if (pid > 0) { // Parent process
        close(pipe_fd[0]); // Close reading end

        // Send numbers to the child process
        for (int i = 1; i <= numbers_to_send; i++) {
            write(pipe_fd[1], &i, sizeof(int));
            printf("Parent: Sent %d to child\n", i);
        }
        
        // Indicate end of data
        int end_signal = -1; 
        write(pipe_fd[1], &end_signal, sizeof(int));

        close(pipe_fd[1]); // Close writing end
        wait(NULL); // Wait for the child process to finish
        printf("Parent: Finished sending data.\n");

    } else { // Child process
        close(pipe_fd[1]); // Close writing end
        int number;

        // Read numbers from the pipe and calculate their square
        while (1) {
            read(pipe_fd[0], &number, sizeof(int));
            if (number == -1) {
                break; // Exit if end signal is received
            }
            printf("Child: Received %d, its square is %d\n", number, number * number);
        }

        close(pipe_fd[0]); // Close reading end
        printf("Child: Finished processing.\n");
    }

    return 0;
}