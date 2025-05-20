//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

void print(int a) {
    if(a == 0) {
        return;
    } else {
        printf("%d\n", a);
        print(a-1);
    }
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, choice;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Enter your choice: \n1. Print n numbers in decreasing order\n2. Factorial of n\n3. nth term of Fibonacci series\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            print(n);
            break;
        case 2:
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;
        case 3:
            printf("The %dth term of Fibonacci series is %d\n", n, fibonacci(n));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}