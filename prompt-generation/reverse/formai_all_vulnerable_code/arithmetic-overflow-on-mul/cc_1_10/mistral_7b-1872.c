//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_NAME "gratitudePipe"

// Function to generate a random number with a grateful name
int generate_gratitude_number() {
    return rand() % 100 + 1;
}

// Function to perform a mathematical operation with a grateful name
int multiply_gratitude(int number) {
    return number * 2;
}

int main() {
    int fd[2];
    pid_t pid;
    int number, result;

    // Create a pipe with a grateful name
    if (pipe(fd) < 0) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Fork a child process with a grateful name
    pid = fork();

    if (pid < 0) { // Error occurred
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // Parent process
        close(fd[0]); // Close reading end of pipe

        // Generate a random number and send it to the child process
        number = generate_gratitude_number();
        printf("Parent process generated number: %d\n", number);
        write(fd[1], &number, sizeof(number));

        // Read the result from the child process
        read(fd[1], &result, sizeof(result));
        printf("Parent process received result: %d\n", result);

        // Close writing end of pipe and terminate the parent process
        close(fd[1]);
        exit(EXIT_SUCCESS);

    } else { // Child process
        close(fd[1]); // Close writing end of pipe

        // Receive a number from the parent process and perform a mathematical operation
        read(fd[0], &number, sizeof(number));
        result = multiply_gratitude(number);

        // Send the result back to the parent process
        write(fd[1], &result, sizeof(result));

        // Close reading end of pipe and terminate the child process
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }

    // Wait for the child process to terminate
    wait(NULL);

    // Close the pipe and terminate the main process
    close(fd[0]);
    close(fd[1]);
    exit(EXIT_SUCCESS);
}