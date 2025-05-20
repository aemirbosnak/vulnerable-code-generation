//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void calculator(int **arr, int n)
{
    int i, j, k, res, op;
    float f1, f2;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of variable %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    printf("Enter the operation (+, -, *, /, %): ");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            printf("Enter the first operand: ");
            scanf("%f", &f1);
            printf("Enter the second operand: ");
            scanf("%f", &f2);
            res = (int)(f1 + f2);
            printf("The result is: %d\n", res);
            break;
        case 2:
            printf("Enter the first operand: ");
            scanf("%f", &f1);
            printf("Enter the second operand: ");
            scanf("%f", &f2);
            res = (int)(f1 - f2);
            printf("The result is: %d\n", res);
            break;
        case 3:
            printf("Enter the first operand: ");
            scanf("%f", &f1);
            printf("Enter the second operand: ");
            scanf("%f", &f2);
            res = (int)(f1 * f2);
            printf("The result is: %d\n", res);
            break;
        case 4:
            printf("Enter the first operand: ");
            scanf("%f", &f1);
            printf("Enter the second operand: ");
            scanf("%f", &f2);
            res = (int)(f1 / f2);
            printf("The result is: %d\n", res);
            break;
        default:
            printf("Invalid operation.\n");
    }

    free(arr);
}

int main()
{
    int **arr = NULL;
    int n;

    calculator(arr, n);

    return 0;
}