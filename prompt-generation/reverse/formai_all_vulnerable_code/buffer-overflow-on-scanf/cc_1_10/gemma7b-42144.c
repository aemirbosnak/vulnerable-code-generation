//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void arith_shapeshift(int n)
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    switch (n)
    {
        case 1:
            a = 5;
            b = 10;
            c = a + b;
            printf("The sum of %d and %d is %d.\n", a, b, c);
            break;
        case 2:
            d = 15;
            e = 20;
            f = d - e;
            printf("The difference of %d and %d is %d.\n", d, e, f);
            break;
        case 3:
            g = 25;
            h = 30;
            i = g * h;
            printf("The product of %d and %d is %d.\n", g, h, i);
            break;
        case 4:
            j = 40;
            k = 45;
            l = j / k;
            printf("The quotient of %d and %d is %d.\n", j, k, l);
            break;
        case 5:
            m = 55;
            n = 60;
            o = m + n;
            printf("The sum of %d and %d is %d.\n", m, n, o);
            break;
        default:
            printf("Invalid input.\n");
    }
}

int main()
{
    int choice;

    printf("Enter your choice:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Sum and Product\n");
    scanf("%d", &choice);

    arith_shapeshift(choice);

    return 0;
}