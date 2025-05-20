//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUMBERS_TO_GENERATE 10
#define BUFFER_SIZE 5

void producer(int write_fd) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < NUMBERS_TO_GENERATE; i++) {
        int num = rand() % 100; // Generate a random number between 0 and 99
        printf("Producer: Generated number %d\n", num);

        // Write the number to the pipe
        if (write(write_fd, &num, sizeof(num)) == -1) {
            perror("Producer: Failed to write to pipe");
            exit(EXIT_FAILURE);
        }

        sleep(1); // Sleep for a second to simulate a delay in data generation
    }

    close(write_fd); // Close the writing end of the pipe
    printf("Producer: Finished generating numbers.\n");
}

void consumer(int read_fd) {
    int num;
    int sum = 0;
    int count = 0;

    // Read numbers from the pipe until the producer closes the write end
    while (read(read_fd, &num, sizeof(num)) > 0) {
        printf("Consumer: Received number %d\n", num);
        sum += num;
        count++;
    }

    if (count > 0) {
        double average = (double)sum / count; // Calculate average
        printf("Consumer: Average of received numbers is %.2f\n", average);
    } else {
        printf("Consumer: No numbers were received.\n");
    }

    close(read_fd); // Close the reading end of the pipe
}

int main() {
    int pipefd[2]; // Array to hold file descriptors for the pipe

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("Main: Failed to create pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process to run the producer
    pid_t pid = fork();
    if (pid < 0) {
        perror("Main: Failed to fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process - Consumer
        close(pipefd[1]); // Close the write end of the pipe
        consumer(pipefd[0]);
        wait(NULL); // Wait for the child process (producer) to finish
    } else {
        // Child process - Producer
        close(pipefd[0]); // Close the read end of the pipe
        producer(pipefd[1]);
    }

    return 0;
}