//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

void calculate_factorial(int n, int write_fd) {
    int result = factorial(n);
    write(write_fd, &result, sizeof(result));
    close(write_fd);
}

int main() {
    int pipe_fd[2]; // Pipe file descriptors
    pid_t pid;
    int number;

    // Creating a pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);

    // Creating child process
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) { // Child process
        close(pipe_fd[0]); // Close the read end of the pipe
        calculate_factorial(number, pipe_fd[1]);
        exit(0); // Child process exits
    } else { // Parent process
        close(pipe_fd[1]); // Close the write end of the pipe
        int result;
        wait(NULL); // Wait for child to finish
        read(pipe_fd[0], &result, sizeof(result));
        printf("Factorial of %d is %d\n", number, result);
        close(pipe_fd[0]); // Close the read end of the pipe
    }

    return 0;
}