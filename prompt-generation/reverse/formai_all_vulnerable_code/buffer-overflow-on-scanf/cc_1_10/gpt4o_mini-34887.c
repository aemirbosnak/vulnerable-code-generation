//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci_visualization(int n) {
    long long a = 0, b = 1;
    long long fib;

    // Create an array to store Fibonacci numbers
    long long *fib_array = (long long*) malloc(n * sizeof(long long));

    printf("Fibonacci Sequence Visualization (first %d numbers):\n", n);

    // Compute the Fibonacci numbers and store in array
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fib = a;
        } else if (i == 1) {
            fib = b;
        } else {
            fib = a + b;
            a = b;
            b = fib;
        }
        fib_array[i] = fib;
    }

    // Determine maximum width for visualization
    long long max_fib = fib_array[n - 1];
    int max_width = snprintf(NULL, 0, "%lld", max_fib);

    // Print the Fibonacci numbers and their graphical representation
    for (int i = 0; i < n; i++) {
        // Print Fibonacci number
        printf("%*lld: ", max_width, fib_array[i]);

        // Print corresponding number of '*' for visual representation
        for (long long j = 0; j < fib_array[i]; j += 1000) {
            putchar('*');
        }

        // Move to the next line
        putchar('\n');
    }

    // Free allocated memory
    free(fib_array);
}

int main() {
    int count;

    printf("Enter the number of Fibonacci numbers to visualize: ");
    if (scanf("%d", &count) != 1 || count < 1) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    print_fibonacci_visualization(count);

    return 0;
}