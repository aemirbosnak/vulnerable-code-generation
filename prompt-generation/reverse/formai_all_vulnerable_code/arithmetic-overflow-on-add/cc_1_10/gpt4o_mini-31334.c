//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_COUNT 10

void generate_numbers(int write_fd) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < NUM_COUNT; i++) {
        int num = rand() % 100; // Generate a random number between 0 and 99
        write(write_fd, &num, sizeof(num)); // Write to the pipe
        printf("Generator: Produced number %d\n", num);
        sleep(1); // Sleep for a second to simulate delay
    }
    close(write_fd); // Close the write end after sending all numbers
}

void process_numbers(int read_fd) {
    int sum = 0;
    int num;
    while (read(read_fd, &num, sizeof(num)) > 0) {
        sum += num; // Sum the received numbers
        printf("Processor: Received number %d\n", num);
    }
    printf("Processor: Total Sum = %d\n", sum);
    close(read_fd); // Close the read end when done
}

int main() {
    int pipe_fd[2]; // File descriptors for the pipe

    if (pipe(pipe_fd) == -1) { // Create the pipe
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork(); // Fork a new process

    if (pid == -1) { // Check for error
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) { // Child process for generating numbers
        close(pipe_fd[0]); // Close the read end
        generate_numbers(pipe_fd[1]); // Generate numbers and write to pipe
    } else { // Parent process for processing numbers
        close(pipe_fd[1]); // Close the write end
        process_numbers(pipe_fd[0]); // Read from pipe and process numbers
        wait(NULL); // Wait for the child to finish
    }

    return EXIT_SUCCESS; // Successful termination
}