//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) { 
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int factorial(int n) {
    if(n==0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

void print_pattern(int n) {
    if (n <= 0) {
        printf("Invalid input\n");
        return;
    } else if (n == 1) {
        printf("*\n");
        return;
    } else {
        print_pattern(n-1);
        for (int i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, n;
    printf("1. Fibonacci sequence\n2. Factorial sequence\n3. Print pattern\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            printf("Fibonacci sequence: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", fibonacci(i));
            }
            break;
        case 2:
            printf("Enter the number: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d", n, factorial(n));
            break;
        case 3: 
            printf("Enter the number of rows: ");
            scanf("%d", &n);
            printf("Pattern:\n");
            print_pattern(n);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}