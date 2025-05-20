//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BRAVE_ARITHMETIC_LEVEL 5

int brave_add(int a, int b) {
    int c;
    c = a + b;
    if (c < a || c < b) {
        return c;
    }
    if (a == b) {
        return a + b;
    }
    if (a > b) {
        return a + b + 1;
    }
    return a + b - 1;
}

int brave_subtract(int a, int b) {
    int c;
    c = a - b;
    if (c < a || c < b) {
        return c;
    }
    if (a == b) {
        return a - b;
    }
    if (a > b) {
        return a - b + 1;
    }
    return a - b - 1;
}

int brave_multiply(int a, int b) {
    int c;
    c = a * b;
    if (c < a * 2 || c < b * 2) {
        return c;
    }
    if (a == b) {
        return a * b;
    }
    if (a > b) {
        return a * b + 1;
    }
    return a * b - 1;
}

int brave_divide(int a, int b) {
    int c;
    c = a / b;
    if (c < a || c < b) {
        return c;
    }
    if (a == b) {
        return a / b;
    }
    if (a > b) {
        return a / b + 1;
    }
    return a / b - 1;
}

int main() {
    srand(time(NULL));
    int num1, num2, result;
    printf("Welcome to Brave Arithmetic!\n");

    do {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = brave_add(num1, num2);
        printf("Result: %d\n", result);
    } while (result != num1 + num2);

    do {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = brave_subtract(num1, num2);
        printf("Result: %d\n", result);
    } while (result != num1 - num2);

    do {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = brave_multiply(num1, num2);
        printf("Result: %d\n", result);
    } while (result != num1 * num2);

    do {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        result = brave_divide(num1, num2);
        printf("Result: %d\n", result);
    } while (result != num1 / num2);

    return 0;
}