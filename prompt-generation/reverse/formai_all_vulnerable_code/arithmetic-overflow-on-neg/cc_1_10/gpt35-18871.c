//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

int multiply(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    else if (b > 0) {
        return a + multiply(a, b-1);
    }
    else if (b < 0) {
        return -multiply(a, -b);
    }
}

int power(int base, int exponent){
    if (exponent == 0){
        return 1;
    }
    else if (exponent > 0){
        return base * power(base, exponent-1);
    }
    else {
        return 1.0 / power(base, -exponent);
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Multiply\n2. Power\n3. Fibonacci\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers to multiply:\n");
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d * %d = %d\n", a, b, multiply(a, b));
            break;
        case 2:
            printf("Enter the base and exponent:\n");
            int base, exponent;
            scanf("%d %d", &base, &exponent);
            printf("%d ^ %d = %d\n", base, exponent, power(base, exponent));
            break;
        case 3:
            printf("Enter the number of elements to generate in the fibonacci series:\n");
            int n;
            scanf("%d", &n);
            printf("The first %d elements of the fibonacci series are:\n", n);
            for (int i = 0; i < n; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}