//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 5 // Size of the buffer (number of random numbers)

void producer(int write_fd) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < BUFFER_SIZE; i++) {
        int num = rand() % 100; // Generate a random number between 0 and 99
        write(write_fd, &num, sizeof(num)); // Write to the pipe
        printf("Producer produced: %d\n", num);
        sleep(1); // Sleep for a second to mimic work (optional)
    }
    close(write_fd); // Close the write end of the pipe
}

void consumer(int read_fd) {
    int num;
    int sum = 0;
    while (read(read_fd, &num, sizeof(num)) > 0) { // Read from the pipe
        printf("Consumer received: %d\n", num);
        sum += num; // Add received number to sum
    }
    printf("Consumer's sum: %d\n", sum); // Print the total sum
    close(read_fd); // Close the read end of the pipe
}

int main() {
    int pipe_fd[2]; // Array to hold pipe file descriptors
    if (pipe(pipe_fd) == -1) { // Create a pipe
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork(); // Create a new process
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process - Producer
        close(pipe_fd[0]); // Close the read end
        producer(pipe_fd[1]); // Call producer function
        wait(NULL); // Wait for child process to finish
    } else { // Child process - Consumer
        close(pipe_fd[1]); // Close the write end
        consumer(pipe_fd[0]); // Call consumer function
    }

    return 0;
}