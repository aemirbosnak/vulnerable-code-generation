//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void fib(int n) {
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i < n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    printf("Fibonacci Sequence:\n");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void printRow(int num, int* arr, int curr, int length) {
    int mid = length / 2;
    if(num > curr) {
        printRow(num, arr, curr * 2, length);
    }
    int spaces = mid - curr / 2;
    for(int i = 0; i < spaces; i++) {
        printf(" ");
    }
    for(int i = 0; i < curr; i++) {
        if(mid - i <= 0 || mid + i >= length) {
            break;
        }
        printf("%d", arr[num - (mid-i-1)]);
    }
    printf("\n");
}

void printFibonacciVisualization(int n) {
    if(n == 0) {
        printf("0\n");
        return;
    }
    if(n == 1) {
        printf("0 \n1\n");
        return;
    }

    int arr[n];
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i < n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    int maxNum = arr[n-1];
    int curr = 2;
    while(curr < n && arr[curr] <= maxNum) {
        curr++;
    }
    curr--;

    for(int i = curr; i >= 0; i--) {
        printRow(i, arr, 1, curr * 2 + 1);
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("\n\n");

    fib(n);

    printf("\n\n");

    printf("Fibonacci Visualization:\n\n");

    printFibonacciVisualization(n);

    return 0;
}