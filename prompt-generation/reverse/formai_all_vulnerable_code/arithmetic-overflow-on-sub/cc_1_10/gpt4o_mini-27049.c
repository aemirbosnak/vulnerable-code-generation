//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int arr[], int size);
void reverseArray(int arr[], int start, int end);
int factorial(int n);
int fibonacci(int n);
void hanoi(int n, char source, char target, char auxiliary);
void printPyramid(int n, int currentRow);

// Main function
int main() {
    int choice, n;

    printf("Choose an option:\n");
    printf("1. Reverse an Array\n");
    printf("2. Calculate Factorial\n");
    printf("3. Fibonacci Series\n");
    printf("4. Tower of Hanoi\n");
    printf("5. Print Pyramid\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter size of the array: ");
            scanf("%d", &n);
            int *arr = (int *)malloc(n * sizeof(int));
            printf("Enter the elements of the array:\n");
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Original Array: ");
            printArray(arr, n);
            reverseArray(arr, 0, n - 1);
            printf("Reversed Array: ");
            printArray(arr, n);
            free(arr);
            break;

        case 2:
            printf("Enter a number to find its factorial: ");
            scanf("%d", &n);
            printf("Factorial of %d is: %d\n", n, factorial(n));
            break;

        case 3:
            printf("Enter the number of Fibonacci terms to generate: ");
            scanf("%d", &n);
            printf("Fibonacci Series: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;

        case 4:
            printf("Enter number of disks for Tower of Hanoi: ");
            scanf("%d", &n);
            printf("The moves involved are:\n");
            hanoi(n, 'A', 'C', 'B');
            break;

        case 5:
            printf("Enter the number of rows for the pyramid: ");
            scanf("%d", &n);
            printPyramid(n, 1);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}

// Function to print elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to reverse an array recursively
void reverseArray(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArray(arr, start + 1, end - 1);
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to implement Tower of Hanoi recursively
void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

// Function to print pyramid of stars recursively
void printPyramid(int n, int currentRow) {
    if (currentRow > n) {
        return;
    }
    // Print spaces
    for (int i = 0; i < n - currentRow; i++) {
        printf(" ");
    }
    // Print stars
    for (int i = 1; i <= (2 * currentRow - 1); i++) {
        printf("*");
    }
    printf("\n");
    printPyramid(n, currentRow + 1);
}