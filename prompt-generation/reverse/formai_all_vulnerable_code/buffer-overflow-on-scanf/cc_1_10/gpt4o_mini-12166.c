//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to compute the factorial of a number
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial of negative numbers is undefined
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function for the child process to compute and send the factorial
void compute_factorial(int read_fd, int write_fd) {
    close(read_fd); // Close unused read end

    int num;
    // Continuously read numbers and compute factorial
    while (1) {
        // Read number from the parent
        if (read(read_fd, &num, sizeof(num)) <= 0) {
            break; // If reading fails, exit loop
        }
        // Compute factorial
        unsigned long long fact = factorial(num);
        // Send result back to parent
        write(write_fd, &fact, sizeof(fact));
    }

    close(write_fd); // Close write end after completion
    exit(0); // Child process exits
}

// Function for the parent process to handle input and output
void handle_input_output(int read_fd, int write_fd) {
    close(write_fd); // Close unused write end

    int num;
    unsigned long long fact;
    printf("Enter numbers to calculate their factorial (negative to exit):\n");
    while (1) {
        printf("Input: ");
        scanf("%d", &num);
        
        // Break loop if negative number is entered
        if (num < 0) {
            break;
        }

        // Send number to child process
        write(read_fd, &num, sizeof(num));
        // Read factorial result from child process
        read(read_fd, &fact, sizeof(fact));
        printf("Factorial of %d is %llu\n", num, fact);
    }

    close(read_fd); // Close read end after completion
    wait(NULL); // Wait for child process to finish
}

int main() {
    int pipe1[2]; // Pipe for parent to child communication
    int pipe2[2]; // Pipe for child to parent communication

    // Create pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
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
        compute_factorial(pipe1[0], pipe2[1]);
    } else {
        // Parent process
        handle_input_output(pipe1[1], pipe2[0]);
    }

    return 0; // Return success
}