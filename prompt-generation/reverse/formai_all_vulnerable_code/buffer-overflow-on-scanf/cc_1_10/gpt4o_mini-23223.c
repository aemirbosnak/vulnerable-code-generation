//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

void printStars(int n) {
    if (n <= 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
    printStars(n - 1);
}

void printInvertedTriangle(int n) {
    if (n <= 0) {
        return;
    }
    printStars(n);
    printInvertedTriangle(n - 1);
}

void printSpaces(int n) {
    if (n <= 0) {
        return;
    }
    printf(" ");
    printSpaces(n - 1);
}

void printPyramid(int n, int currentLevel) {
    if (currentLevel > n) {
        return;
    }
    printSpaces(n - currentLevel);
    printStars(currentLevel);
    printPyramid(n, currentLevel + 1);
}

void printDiamond(int n) {
    if (n <= 0) {
        return;
    }
    printPyramid(n, 1);
    printInvertedTriangle(n - 1);
}

void countUp(int current, int target) {
    if (current > target) {
        return;
    }
    printf("%d ", current);
    countUp(current + 1, target);
}

void countDown(int current) {
    if (current < 1) {
        return;
    }
    printf("%d ", current);
    countDown(current - 1);
}

void printArrayRecursively(int *arr, int n, int index) {
    if (index >= n) {
        return;
    }
    printf("%d ", arr[index]);
    printArrayRecursively(arr, n, index + 1);
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Enter the number of layers for the diamond shape: ");
    scanf("%d", &n);
    printf("Diamond Shape:\n");
    printDiamond(n);

    printf("\nCount Up to 5:\n");
    countUp(1, 5);
    printf("\nCount Down from 5:\n");
    countDown(5);
    printf("\n");

    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    printf("Array Elements:\n");
    printArrayRecursively(arr, arrSize, 0);
    printf("\n");

    int facNum;
    printf("\nEnter a number to calculate its factorial: ");
    scanf("%d", &facNum);
    printf("Factorial of %d is %d\n", facNum, factorial(facNum));

    int fibNum;
    printf("Enter a number to get Fibonacci sequence up to that number: ");
    scanf("%d", &fibNum);
    printf("Fibonacci numbers:\n");
    for (int i = 0; i <= fibNum; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}