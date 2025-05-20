//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t;
    int x, y, z;
    int sum1, sum2, sum3;
    int product1, product2, product3;
    int difference1, difference2;
    int quotient1, quotient2;

    printf("Welcome to the Retro Arithmetic Calculator!\n");
    printf("Please enter two integers:\n");
    scanf("%d %d", &a, &b);

    sum1 = a + b;
    product1 = a * b;
    difference1 = a - b;
    quotient1 = a / b;

    printf("Sum: %d\n", sum1);
    printf("Product: %d\n", product1);
    printf("Difference: %d\n", difference1);
    printf("Quotient: %d\n", quotient1);

    printf("\n");

    printf("Welcome to the Retro Arithmetic Calculator!\n");
    printf("Please enter three integers:\n");
    scanf("%d %d %d", &c, &d, &e);

    sum2 = c + d + e;
    product2 = c * d * e;

    printf("Sum: %d\n", sum2);
    printf("Product: %d\n", product2);

    printf("\n");

    printf("Welcome to the Retro Arithmetic Calculator!\n");
    printf("Please enter four integers:\n");
    scanf("%d %d %d %d", &f, &g, &h, &i);

    sum3 = f + g + h + i;
    product3 = f * g * h * i;

    printf("Sum: %d\n", sum3);
    printf("Product: %d\n", product3);

    return 0;
}