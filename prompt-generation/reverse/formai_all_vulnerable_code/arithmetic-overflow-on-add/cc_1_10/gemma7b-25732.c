//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    float x_f, y_f, z_f;
    double d_x, d_y, d_z;
    char op, ch, sign, space;

    printf("Enter an operator (+, -, *, /, %): ");
    scanf("%c", &op);

    switch (op)
    {
        case '+':
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            c = a + b;
            printf("The result is: %d\n", c);
            break;
        case '-':
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            c = a - b;
            printf("The result is: %d\n", c);
            break;
        case '*':
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            c = a * b;
            printf("The result is: %d\n", c);
            break;
        case '/':
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            c = a / b;
            printf("The result is: %d\n", c);
            break;
        case '%':
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            c = a % b;
            printf("The result is: %d\n", c);
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}