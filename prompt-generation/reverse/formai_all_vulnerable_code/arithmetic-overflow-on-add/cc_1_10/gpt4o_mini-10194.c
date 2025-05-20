//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define BUFFER_SIZE 10

void producer(int write_fd, int count) {
    for (int i = 0; i < count; i++) {
        int random_number = rand() % 100; // Generate a random number between 0 and 99
        write(write_fd, &random_number, sizeof(random_number));
        printf("Produced: %d\n", random_number);
        sleep(1); // Sleep to simulate time taken to produce an item
    }

    int stop_signal = -1; // Stop signal for the consumer
    write(write_fd, &stop_signal, sizeof(stop_signal));
    close(write_fd);
}

void consumer(int read_fd) {
    int number;
    int total = 0;
    int count = 0;

    while (1) {
        read(read_fd, &number, sizeof(number));
        if (number == -1) { // Check for the stop signal
            break;
        }
        total += number;
        count++;
        printf("Consumed: %d\n", number);
    }

    if (count > 0) {
        printf("Average: %.2f\n", (double)total / count);
    } else {
        printf("No numbers were consumed.\n");
    }

    close(read_fd);
}

int main() {
    int pipe_fd[2];
    pid_t pid;

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL)); // Seed random number generator
    
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process - Producer
        close(pipe_fd[0]); // Close reading end
        int numbers_to_produce = 5; // Produce 5 numbers
        producer(pipe_fd[1], numbers_to_produce);
        wait(NULL); // Wait for child process to finish
    } else { // Child process - Consumer
        close(pipe_fd[1]); // Close writing end
        consumer(pipe_fd[0]);
    }

    return 0;
}