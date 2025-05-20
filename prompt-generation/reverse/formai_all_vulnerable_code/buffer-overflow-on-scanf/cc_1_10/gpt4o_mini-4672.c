//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>

// Function to generate Fibonacci numbers and visualize them
void generate_fibonacci(int n) {
    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (!fib) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize the first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    // Generate Fibonacci sequence
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Visualize the Fibonacci sequence
    printf("\nFibonacci Sequence Visualizer\n");
    printf("Index\tValue\tVisualization\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%lld\t", i, fib[i]);

        // Create a simple visualization with asterisks
        for (long long j = 0; j < fib[i] / 1000000; j++) {
            printf("*");
        }
        printf("\n");
    }

    free(fib);
}

int main() {
    int num;

    do {
        printf("Enter the number of Fibonacci elements to generate (greater than 2): ");
        scanf("%d", &num);
        if (num <= 2) {
            printf("Please enter a value greater than 2.\n");
        }
    } while (num <= 2);

    // Prepare to clear the terminal screen
    const char *clear_command = "clear";
    if (fork() == 0) {
        execlp(clear_command, clear_command, NULL);
        exit(0);
    }
    wait(NULL);

    // Call the function to generate and visualize Fibonacci numbers
    generate_fibonacci(num);

    return 0;
}