//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_FIB 30  // Maximum Fibonacci number to generate
#define PIPE_READ 0
#define PIPE_WRITE 1

void generate_fibonacci(int n, int pipefd) {
    long long fib[MAX_FIB];
    fib[0] = 0; 
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Send Fibonacci sequence through the pipe
    write(pipefd, fib, sizeof(long long) * n);
    close(pipefd); // Close write end
}

void visualize_fibonacci(int pipefd, int n) {
    long long fib[MAX_FIB];

    // Read from pipe
    read(pipefd, fib, sizeof(long long) * n);
    close(pipefd); // Close read end

    // Display Fibonacci sequence graphically
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld: ", fib[i]);
        for (long long j = 0; j < fib[i]; j++) {
            putchar('#'); // Use '#' to represent the Fibonacci value
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to generate (up to %d): ", MAX_FIB);
    scanf("%d", &n);
    
    if (n > MAX_FIB || n < 1) {
        fprintf(stderr, "Please enter a valid number between 1 and %d\n", MAX_FIB);
        return EXIT_FAILURE;
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) { // Child process
        close(pipefd[PIPE_READ]);  // Close read end in child
        generate_fibonacci(n, pipefd[PIPE_WRITE]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipefd[PIPE_WRITE]); // Close write end in parent
        wait(NULL); // Wait for child process to finish
        visualize_fibonacci(pipefd[PIPE_READ], n);
    }

    return EXIT_SUCCESS;
}