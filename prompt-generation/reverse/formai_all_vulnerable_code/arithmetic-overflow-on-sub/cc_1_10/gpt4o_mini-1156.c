//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void printTriangle(int n, int row, int col);
void execute(int n);
int factorial(int n);
void fprint(int n, int *arr);

int main() {
    int num;
    printf("Enter a number to see its factorial and a triangle:\n");
    scanf("%d", &num);
    
    // Factorial computation
    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);

    // Print triangle
    printf("\nGenerating triangle for %d rows:\n\n", num);
    execute(num);

    return 0;
}

void execute(int n) {
    for (int i = 1; i <= n; i++) {
        printTriangle(n, i, 1);
        printf("\n");
    }
}

void printTriangle(int n, int row, int col) {
    if (row <= n) {
        if (col <= row) {
            printf("* ");
            printTriangle(n, row, col + 1);
        }
        // To print in a new row
        printTriangle(n, row + 1, 1);
    }
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void fprint(int n, int *arr) {
    if (n < 0) {
        return;
    }
    fprint(n - 1, arr);
    printf("%d ", arr[n]);
}

void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * i;  // fill the array with squares
    }
}

void arrayDemo(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    fillArray(arr, size);

    printf("Array contents: ");
    fprint(size - 1, arr);
    printf("\n");

    free(arr);
}