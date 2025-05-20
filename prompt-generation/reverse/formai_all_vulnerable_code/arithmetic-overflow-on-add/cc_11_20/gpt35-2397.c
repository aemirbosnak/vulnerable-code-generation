//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
// Fibonacci Sequence Visualizer
// Written in a paranoid style

#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 50

int main() {
    int fib[MAX_FIB]; // the Fibonacci sequence array
    int index = 0; // current index into the array
    int next = 0; // the next number in the sequence

    // Initialize the first two elements of the sequence
    fib[0] = 0;
    fib[1] = 1;

    // Loop through the rest of the sequence, adding each number to the array
    for (int i = 2; i < MAX_FIB; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print out the sequence in a paranoid way
    printf("The Fibonacci sequence is:\n");
    for (int i = 0; i < MAX_FIB; i++) {
        printf("%d ", fib[i]);

        // Check every number for any potential signs of tampering
        if (i % 5 == 0 && fib[i] != (fib[i-1] + fib[i-2]) && fib[i] != (next + fib[i-1])) {
            printf(" (INVALID)");
        }

        // Check the index for any tampering
        if (i == index && index != 0) {
            printf(" (TAMPERED)");
            exit(1);
        }

        // Check the next number for any tampering
        if (i == index+1) {
            next = fib[i];
            if (next != (fib[i-1] + fib[i-2])) {
                printf(" (TAMPERED)");
                exit(1);
            }
        }

        // Check the sum of the previous two numbers for any tampering
        if (i >= 2 && i != index && i != index+1) {
            if (fib[i] != (fib[i-1] + fib[i-2])) {
                printf(" (TAMPERED)");
                exit(1);
            }
        }

        // Randomly reset the index for added paranoia
        if (i % 7 == 0 && rand() % 10 == 0) {
            index = rand() % (i-2) + 2;
            printf(" (RESET INDEX)");
        }
    }

    printf("\n");
    return 0;
}