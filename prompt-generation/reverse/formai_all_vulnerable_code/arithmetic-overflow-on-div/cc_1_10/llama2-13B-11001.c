//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m, p, q, r, s;
    float a, b, c, d, e, f;
    char op;

    printf("Welcome to Arithmetic Land!\n");

    // Calculator Menu
    printf("Please select an operation (+, -, *, /, %): ");
    scanf(" %c", &op);

    // Get the numbers
    printf("Enter the first number: ");
    scanf(" %d", &n);
    printf("Enter the second number: ");
    scanf(" %d", &m);

    // Perform the operation
    if (op == '+') {
        a = n + m;
        b = n - m;
        c = n * m;
        d = n / m;
        e = n % m;
    } else if (op == '-') {
        a = n - m;
        b = n + m;
        c = n * m;
        d = n / m;
        e = n % m;
    } else if (op == '*') {
        a = n * m;
        b = n / m;
        c = n + m;
        d = n - m;
        e = n % m;
    } else if (op == '/') {
        a = n / m;
        b = n * m;
        c = n + m;
        d = n - m;
        e = n % m;
    } else if (op == '%') {
        a = n % m;
        b = n / m;
        c = n + m;
        d = n - m;
        e = n * m;
    }

    // Print the results
    printf("Result of %c %d and %d is:\n", op, n, m);
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    printf("d = %f\n", d);
    printf("e = %f\n", e);

    return 0;
}