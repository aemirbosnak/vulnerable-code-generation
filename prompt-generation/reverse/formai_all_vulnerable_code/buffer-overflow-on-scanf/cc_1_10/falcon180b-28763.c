//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 100

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void visualize_fibonacci(int n) {
    int i, j, k;
    int fib_num;

    printf("Fibonacci sequence up to %d terms:\n", n);

    for (i = 0, j = 1, k = 0; k < n; k++) {
        fib_num = fibonacci(k);

        if (fib_num % 2 == 0) {
            printf("%d ", fib_num);
        } else {
            printf("%d ", fib_num);
        }

        if (k == MAX_FIB - 1) {
            printf("\n");
            break;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of terms to display (up to %d): ", MAX_FIB);
    scanf("%d", &n);

    if (n > MAX_FIB) {
        printf("Error: Number of terms exceeds maximum limit.\n");
        exit(1);
    }

    visualize_fibonacci(n);

    return 0;
}