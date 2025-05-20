//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, f = 0;
    scanf("Enter the number of test cases: ", &n);

    for (i = 0; i < n; i++)
    {
        scanf("Enter the number of operations: ", &k);

        switch (k)
        {
            case 1:
                scanf("Enter the number of operands: ", &l);
                for (j = 0; j < l; j++)
                {
                    scanf("Enter the operand: ", &m);
                    f += m;
                }
                break;
            case 2:
                scanf("Enter the operator: ", &m);
                switch (m)
                {
                    case '+':
                        scanf("Enter the two operands: ", &l, &j);
                        f = l + j;
                        break;
                    case '-':
                        scanf("Enter the two operands: ", &l, &j);
                        f = l - j;
                        break;
                    case '*':
                        scanf("Enter the two operands: ", &l, &j);
                        f = l * j;
                        break;
                    case '/':
                        scanf("Enter the two operands: ", &l, &j);
                        f = l / j;
                        break;
                }
                break;
            default:
                printf("Invalid operation\n");
        }

        printf("The final result is: %d\n", f);
    }

    return 0;
}