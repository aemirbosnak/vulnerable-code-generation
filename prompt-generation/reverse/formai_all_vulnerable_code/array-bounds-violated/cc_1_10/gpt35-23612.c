//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>

// function to calculate and print fibonacci sequence
void fibonacci(int n) {
    int fib[n]; // array to store fibonacci sequence up to n
    fib[0] = 0; // first number in sequence
    fib[1] = 1; // second number in sequence
    printf("%d %d ", fib[0], fib[1]); // print first and second numbers in sequence

    for(int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2]; // calculate next number in sequence
        printf("%d ", fib[i]); // print next number in sequence
    }

    printf("\n");
}

// function to print fibonacci sequence using asterisks
void fibonacci_visual(int n) {
    int fib[n]; // array to store fibonacci sequence up to n
    fib[0] = 0; // first number in sequence
    fib[1] = 1; // second number in sequence
    
    printf("Fibonacci Sequence:\n");

    for(int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2]; // calculate next number in sequence
    }

    for(int i = n-1; i >= 0; i--) {
        // print asterisks according to fibonacci number
        for(int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf(" %d\n", fib[i]); // print fibonacci number next to asterisks
    }
}

int main() {
    int n;

    printf("Enter number of terms for fibonacci sequence: ");
    scanf("%d", &n);

    printf("\n");
    fibonacci(n);

    printf("\n");
    fibonacci_visual(n);

    return 0;
}