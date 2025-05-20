//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, p, q, r, s, t, u, v, w, x, y, z;
    float f, g, h, jh, kgh;

    printf("Enter the number of test cases:");
    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        printf("Enter the number of operations:");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                printf("Enter the operand:");
                scanf("%d", &x);

                printf("The result is: %d", x * 2);
                break;

            case 2:
                printf("Enter the two operands:");
                scanf("%d", &x);
                scanf("%d", &y);

                printf("The result is: %d", x + y);
                break;

            case 3:
                printf("Enter the two operands:");
                scanf("%d", &x);
                scanf("%d", &y);

                printf("The result is: %f", (float)x / y);
                break;

            default:
                printf("Invalid operation");
                break;
        }

        printf("\n");
    }

    return 0;
}