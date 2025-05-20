//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>

// function to print the fibonacci sequence
void fibonacciSequence(int n) {
    int first = 0, second = 1, next;
    printf("%d %d", first, second);
    for (int i = 3; i <= n; i++) {
        next = first + second;
        printf(" %d", next);
        first = second;
        second = next;
    }
}

// function to display the fibonacci sequence using asterisks
void fibonacciVisual(int n) {
    int height = n, length = 2*n, i, j, k;
    int arr[n][length];

    // initialize all values to 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2*n; j++) {
            arr[i][j] = 0;
        }
    }

    // set base case values to 1
    arr[0][n-1] = 1;
    arr[1][n-2] = 1;
    arr[1][n] = 1;

    // calculate values for the rest of the sequence
    for (i = 2; i < n; i++) {
        for (j = n-i; j <= n+i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1];
        }
    }

    // print out the sequence visually using asterisks
    for (i = 0; i < n; i++) {
        for (j = 0; j < length; j++) {
            if (arr[i][j]) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Fibonacci sequence: ");
    fibonacciSequence(n);
    printf("\n\n");
    printf("Fibonacci sequence visualized: \n");
    fibonacciVisual(n);
    return 0;
}