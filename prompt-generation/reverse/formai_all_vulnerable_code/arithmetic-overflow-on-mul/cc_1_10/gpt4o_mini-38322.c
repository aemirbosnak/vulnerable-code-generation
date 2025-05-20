//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NUMBERS 10

int main() {
    int pipe1[2]; // Pipe for parent to child
    int pipe2[2]; // Pipe for child to parent
    pid_t pid;
    int numbers[MAX_NUMBERS];
    int squared[MAX_NUMBERS];
    int i;

    // Create pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Create child process
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipe1[1]); // Close unused write end of pipe1
        close(pipe2[0]); // Close unused read end of pipe2

        // Read numbers from parent
        read(pipe1[0], numbers, sizeof(numbers));
        
        // Perform squaring
        for (i = 0; i < MAX_NUMBERS; i++) {
            squared[i] = numbers[i] * numbers[i];
        }
        
        // Send results to parent
        write(pipe2[1], squared, sizeof(squared));
        
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipe1[0]); // Close unused read end of pipe1
        close(pipe2[1]); // Close unused write end of pipe2

        // Generate numbers and send to child
        for (i = 0; i < MAX_NUMBERS; i++) {
            numbers[i] = i + 1; // Numbers from 1 to 10
        }
        
        write(pipe1[1], numbers, sizeof(numbers));
        close(pipe1[1]); // Close write end of pipe1

        // Wait for child to finish
        wait(NULL);

        // Read results from child
        read(pipe2[0], squared, sizeof(squared));
        
        // Print results
        printf("Squared values:\n");
        for (i = 0; i < MAX_NUMBERS; i++) {
            printf("%d squared is %d\n", numbers[i], squared[i]);
        }
        
        close(pipe2[0]); // Close read end of pipe2
        exit(EXIT_SUCCESS);
    }

    return 0;
}