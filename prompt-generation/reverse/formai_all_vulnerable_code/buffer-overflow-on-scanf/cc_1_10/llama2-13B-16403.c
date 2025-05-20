//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

#define MAX_NUMBER_OF_PROCESSES 10
#define MAX_NUMBER_OF_OPERATIONS 10

// Function to perform math operations in parallel
void perform_math_operations(int num_operations, int *operations) {
    int i, j, k;
    int result;
    pid_t pid[MAX_NUMBER_OF_PROCESSES];

    // Create a separate process for each operation
    for (i = 0; i < MAX_NUMBER_OF_PROCESSES; i++) {
        pid[i] = fork();
        if (pid[i] == 0) {
            // Child process performs the operation
            for (j = 0; j < num_operations; j++) {
                if (operations[j] == '+') {
                    // Perform addition
                    result = i + j;
                } else if (operations[j] == '-') {
                    // Perform subtraction
                    result = i - j;
                } else if (operations[j] == '*') {
                    // Perform multiplication
                    result = i * j;
                } else if (operations[j] == '/') {
                    // Perform division
                    result = i / j;
                }
                // Print the result of each operation
                printf("%d\n", result);
            }
            exit(0);
        } else {
            // Parent process waits for all child processes to finish
            wait(NULL);
        }
    }
}

int main() {
    int num_operations, i;
    char operations[MAX_NUMBER_OF_OPERATIONS];

    // Read the number of operations and the operations themselves from the user
    printf("Enter the number of operations: ");
    scanf("%d", &num_operations);
    for (i = 0; i < num_operations; i++) {
        printf("Operation %d: ", i + 1);
        scanf(" %c", &operations[i]);
    }

    // Perform the operations in parallel
    perform_math_operations(num_operations, operations);

    return 0;
}