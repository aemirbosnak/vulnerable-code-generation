//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void print_square(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_circle(int radius) {
    for (int y = radius; y >= -radius; y--) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void print_fibonacci_shapes(int fib[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nFibonacci number: %d\n", fib[i]);
        if (i % 3 == 0) { // Print square for every third Fibonacci number
            print_square(fib[i]);
        } else if (i % 3 == 1) { // Print triangle for every third Fibonacci number + 1
            print_triangle(fib[i]);
        } else { // Print circle for every third Fibonacci number + 2
            print_circle(fib[i] / 3); // Scale down for visualization
        }
    }
}

int main() {
    int num; 
    printf("Enter the number of Fibonacci terms to visualize: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    int *fibonacci = (int *)malloc(num * sizeof(int));
    if (fibonacci == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Generate Fibonacci sequence
    fibonacci[0] = 0;
    if (num > 1) {
        fibonacci[1] = 1;
    }
    for (int i = 2; i < num; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Visualize Fibonacci numbers
    print_fibonacci_shapes(fibonacci, num);

    free(fibonacci);
    return 0;
}