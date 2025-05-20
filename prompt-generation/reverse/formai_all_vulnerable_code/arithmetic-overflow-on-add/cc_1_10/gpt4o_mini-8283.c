//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 128
#define NUM_COUNT 10

// Function to produce random numbers
void producer(int write_fd) {
    srand(time(NULL)); // Seed random number generator

    for (int i = 0; i < NUM_COUNT; i++) {
        int num = rand() % 100; // Generate a random number between 0 and 99
        write(write_fd, &num, sizeof(num)); // Write number to pipe
        printf("Produced: %d\n", num);
        sleep(1); // Simulate some processing time
    }

    // Signal end of production
    int end_signal = -1;
    write(write_fd, &end_signal, sizeof(end_signal));
}

// Function to consume numbers
void consumer(int read_fd) {
    int num;
    int sum = 0;

    while (1) {
        int bytes_read = read(read_fd, &num, sizeof(num)); // Read from pipe
        if (bytes_read <= 0) {
            break; // Exit loop if read fails
        }
        if (num == -1) {
            // End signal
            break;
        }
        sum += num;
        printf("Consumed: %d, Current Sum: %d\n", num, sum);
    }

    printf("Total Sum: %d\n", sum);
}

int main() {
    int pipe_fd[2]; // Pipe file descriptors

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // In child process: Consumer
        close(pipe_fd[1]); // Close unused write end
        consumer(pipe_fd[0]);
        close(pipe_fd[0]); // Close read end after done
        exit(EXIT_SUCCESS);
    } else {
        // In parent process: Producer
        close(pipe_fd[0]); // Close unused read end
        producer(pipe_fd[1]);
        close(pipe_fd[1]); // Close write end after done

        // Wait for child to finish
        wait(NULL);
        printf("Producer finished. Consumer process has ended.\n");
    }

    return 0;
}