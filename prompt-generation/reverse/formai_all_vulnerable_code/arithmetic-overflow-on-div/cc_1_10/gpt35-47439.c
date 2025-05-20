//FormAI DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>

void add(int *a, int *b, int *result) {
    *result = *a + *b;
}

void subtract(int *a, int *b, int *result) {
    *result = *a - *b;
}

void multiply(int *a, int *b, int *result) {
    *result = (*a) * (*b);
}

void divide(int *a, int *b, int *result) {
    if (*b != 0) {
        *result = *a / *b;
    } else {
        printf("Error: division by zero");
    }
}

int main() {
    int a, b, result;
    char operator;

    printf("Enter an arithmetic expression in the form of 'a operator b': ");
    scanf("%d %c %d", &a, &operator, &b);

    switch (operator) {
        case '+':
            add(&a, &b, &result);
            printf("%d + %d = %d", a, b, result);
            break;
        case '-':
            subtract(&a, &b, &result);
            printf("%d - %d = %d", a, b, result);
            break;
        case '*':
            multiply(&a, &b, &result);
            printf("%d * %d = %d", a, b, result);
            break;
        case '/':
            divide(&a, &b, &result);
            if (result != 0) {
                printf("%d / %d = %d", a, b, result);
            }
            break;
        default:
            printf("Error: invalid operator");
            break;
    }

    return 0;
}