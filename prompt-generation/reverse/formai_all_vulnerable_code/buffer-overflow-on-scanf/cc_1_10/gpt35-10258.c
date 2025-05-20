//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}

void print_rectangle(int n, int height) {
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_triangle(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int option;
    printf("Welcome to the Fibonacci Sequence Visualizer! Here are your options:\n");
    printf("1. Print the first n numbers of the Fibonacci sequence.\n");
    printf("2. Print a rectangle with n rows and columns.\n");
    printf("3. Print a right-angled triangle with n rows.\n");
    printf("\nEnter your choice (1, 2, or 3): ");
    scanf("%d", &option);

    switch (option) {
        case 1: {
            int n;
            printf("\nEnter the value of n: ");
            scanf("%d", &n);
            printf("The first %d numbers of the Fibonacci sequence are: \n", n);
            fibonacci(n);
            break;
        }
        case 2: {
            int n, height;
            printf("\nEnter the number of rows and columns (n x n): ");
            scanf("%d", &n);
            printf("Enter the height of the rectangle: ");
            scanf("%d", &height);
            printf("Printing a rectangle %d x %d with height %d: \n", n, n, height);
            print_rectangle(n, height);
            break;
        }
        case 3: {
            int n;
            printf("\nEnter the number of rows: ");
            scanf("%d", &n);
            printf("Printing a right-angled triangle with %d rows: \n", n);
            print_triangle(n);
            break;
        }
        default: {
            printf("Invalid choice. Please enter 1, 2, or 3.");
            break;
        }
    }

    return 0;
}