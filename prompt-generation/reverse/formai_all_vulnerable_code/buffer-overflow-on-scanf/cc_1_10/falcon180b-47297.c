//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, temp;
    int fib[100];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of terms to generate
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    // Initialize the first two terms of the sequence
    fib[0] = 0;
    fib[1] = 1;

    // Generate the remaining terms of the sequence
    for (i = 2; i < n; i++) {
        // Randomly choose two previous terms to add together
        j = rand() % (i - 1);
        k = rand() % (i - 1);
        while (k == j) {
            k = rand() % (i - 1);
        }

        // Add the two terms together and store the result
        temp = fib[j] + fib[k];

        // Check if the result is too large to be stored in an int
        if (temp < 0) {
            printf("Error: Result is too large to be stored in an int.\n");
            exit(1);
        }

        // Store the result in the sequence
        fib[i] = temp;
    }

    // Print the sequence
    printf("Fibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}