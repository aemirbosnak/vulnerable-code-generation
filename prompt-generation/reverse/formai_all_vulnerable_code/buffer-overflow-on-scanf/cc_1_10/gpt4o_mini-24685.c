//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int n) {
    // Base case
    if (n <= 1)
        return 1;
    // Recursive case
    return n * factorial(n - 1);
}

void childProcess(int n, int writeFd) {
    // Calculate factorial in the child process
    int result = factorial(n);
    // Write the result to the pipe
    write(writeFd, &result, sizeof(result));
    close(writeFd); // Close the write end of the pipe
    exit(0); // Exit child process
}

int main() {
    int n;
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &n);

    // Create a pipe
    int pipeFd[2];
    if (pipe(pipeFd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipeFd[0]); // Close the read end
        childProcess(n, pipeFd[1]);
    } else {
        // Parent process
        close(pipeFd[1]); // Close the write end

        // Wait for the child to finish
        wait(NULL);

        // Read the result from the pipe
        int result;
        read(pipeFd[0], &result, sizeof(result));
        close(pipeFd[0]); // Close the read end

        printf("Factorial of %d is: %d\n", n, result);
    }

    return 0;
}