//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of Fibonacci terms you want to generate: ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("The first %d Fibonacci terms are:\n", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }

    printf("\n\n");

    int rows, cols;
    printf("Enter the number of rows and columns for Fibonacci visualizer: ");
    scanf("%d %d", &rows, &cols);

    printf("\n");

    int count = 0;
    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            if(count < n) {
                printf("%d ", fib[count]);
            }
            else {
                printf(". ");
            }
            count++;

        }

        printf("\n");

    }

    return 0;
}