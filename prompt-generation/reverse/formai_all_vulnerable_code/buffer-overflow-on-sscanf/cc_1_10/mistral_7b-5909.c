//MISTRAL-7B DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 50

void fibonacci(int n, int *a, int *b);
void check_input(int *n);

int main() {
    int n;
    check_input(&n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int a = 0, b = 1;
    fibonacci(n, &a, &b);

    printf("Fibonacci sequence up to %d:\n", n);
    printf("%d %d", a, b);

    while (a < n) {
        fibonacci(n, &a, &b);
        printf(" %d", a);
    }

    printf("\n");

    return 0;
}

void fibonacci(int n, int *a, int *b) {
    if (*b >= n)
        return;

    int temp = *a;
    *a = *b;
    *b = temp + *b;

    printf("%d ", *b);

    fibonacci(n, a, b);
}

void check_input(int *n) {
    char str[MAX_INPUT + 1];
    fgets(str, sizeof(str), stdin);

    sscanf(str, "%d", n);

    if (n == NULL || *n == '\n') {
        printf("Invalid input. Please enter a positive integer.\n");
        check_input(n);
    }
}