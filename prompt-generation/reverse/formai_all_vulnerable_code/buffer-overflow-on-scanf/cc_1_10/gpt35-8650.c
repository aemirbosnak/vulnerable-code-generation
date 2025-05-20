//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

int paranoid_fibonacci(int n) {
    if (n == 0) {
        printf("Initializing the sequence with 0...\n");
        return 0;
    }
    else if (n == 1) {
        char message[] = "Are you sure you want to start the Fibonacci sequence with 1? (y/n): ";
        char answer;
        printf("%s", message);
        answer = getchar();
        if (answer == 'y' || answer == 'Y') {
            printf("Initializing the sequence with 1...\n");
            return 1;
        }
        else {
            printf("Initializing the sequence with 0...\n");
            return 0;
        }
    }
    else if (n < 0) {
        char message[] = "Are you trying to initialize the sequence with a negative number? (y/n): ";
        char answer;
        printf("%s", message);
        answer = getchar();
        if (answer == 'y' || answer == 'Y') {
            printf("Initializing the sequence with 0...\n");
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        printf("Starting the Fibonacci sequence with 0 and 1...\n");
        int fib[n];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        printf("The Fibonacci sequence up to position %d is: ", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", fib[i]);
        }
        printf("\n");
        return fib[n-1];
    }
}

int main() {
    int n;
    printf("Enter the position of the Fibonacci number you want to generate: ");
    scanf("%d", &n);
    int fib = paranoid_fibonacci(n);
    printf("The Fibonacci number at position %d is: %d\n", n, fib);
    return 0;
}