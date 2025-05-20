//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 20
#define MAX_NUMBERS 10

void generate_numbers(int write_fd) {
    for (int i = 1; i <= MAX_NUMBERS; i++) {
        write(write_fd, &i, sizeof(int));
        printf("Generated number: %d\n", i);
        sleep(1);  // Simulate some delay
    }
    close(write_fd);  // Close the writing end of the pipe
}

void calculate_squares(int read_fd, int write_fd) {
    int num;
    while (read(read_fd, &num, sizeof(int)) > 0) {
        int square = num * num;
        write(write_fd, &square, sizeof(int));
        printf("Calculated square of %d: %d\n", num, square);
    }
    close(read_fd);   // Close the reading end of the pipe
    close(write_fd);  // Close the writing end of the pipe
}

void receive_squares(int read_fd) {
    int square;
    while (read(read_fd, &square, sizeof(int)) > 0) {
        printf("Received square: %d\n", square);
    }
    close(read_fd);  // Close the reading end of the pipe
}

int main() {
    int pipe1[2];  // Pipe for parent to child
    int pipe2[2];  // Pipe for child to parent

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {  // Parent process
        close(pipe1[0]); // Close unused read end of pipe1
        close(pipe2[1]); // Close unused write end of pipe2

        printf("Parent Process: Generating numbers...\n");
        generate_numbers(pipe1[1]); // Write numbers to child

        wait(NULL);  // Wait for the child process to finish
        printf("Parent Process: Receiving squares...\n");
        receive_squares(pipe2[0]); // Read squares from child
        
    } else {  // Child process
        close(pipe1[1]); // Close unused write end of pipe1
        close(pipe2[0]); // Close unused read end of pipe2

        printf("Child Process: Calculating squares...\n");
        calculate_squares(pipe1[0], pipe2[1]); // Read numbers and send squares

        exit(EXIT_SUCCESS);
    }

    return 0;
}