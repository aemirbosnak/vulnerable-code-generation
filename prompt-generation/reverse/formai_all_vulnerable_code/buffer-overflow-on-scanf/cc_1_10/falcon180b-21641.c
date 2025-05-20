//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main() {
    int n, m, i, j, k, l, c, d;
    float x, y, z, a, b, s, t, u, v;
    char ch;

    printf("Enter the number of decimal places to which you want to round off the result: ");
    scanf("%d", &n);

    printf("Enter the first number: ");
    scanf("%f", &x);

    printf("Enter the second number: ");
    scanf("%f", &y);

    printf("Enter the operation to be performed:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &c);

    switch(c) {
        case 1:
            s = x + y;
            printf("\nResult: %.*f\n", n, s);
            break;
        case 2:
            s = x - y;
            printf("\nResult: %.*f\n", n, s);
            break;
        case 3:
            s = x * y;
            printf("\nResult: %.*f\n", n, s);
            break;
        case 4:
            if(y == 0) {
                printf("\nError: Division by zero\n");
            } else {
                s = x / y;
                printf("\nResult: %.*f\n", n, s);
            }
            break;
        default:
            printf("\nError: Invalid operation\n");
    }

    return 0;
}