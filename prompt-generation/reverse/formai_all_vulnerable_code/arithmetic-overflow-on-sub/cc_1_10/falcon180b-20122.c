//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice, n1, n2, i, j, k;
    float sum = 0.0, prod = 1.0, quot, diff;
    char str[100];

    printf("Enter your choice:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square\n6. Cube\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%d %d", &n1, &n2);
            sum = n1 + n2;
            printf("Sum = %d\n", sum);
            break;

        case 2:
            printf("Enter two numbers:\n");
            scanf("%d %d", &n1, &n2);
            diff = n1 - n2;
            printf("Difference = %d\n", diff);
            break;

        case 3:
            printf("Enter two numbers:\n");
            scanf("%d %d", &n1, &n2);
            prod = n1 * n2;
            printf("Product = %d\n", prod);
            break;

        case 4:
            printf("Enter two numbers:\n");
            scanf("%d %d", &n1, &n2);
            quot = n1 / n2;
            printf("Quotient = %d\n", quot);
            break;

        case 5:
            printf("Enter a number:\n");
            scanf("%d", &n1);
            printf("Square = %d\n", n1 * n1);
            break;

        case 6:
            printf("Enter a number:\n");
            scanf("%d", &n1);
            printf("Cube = %d\n", n1 * n1 * n1);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}