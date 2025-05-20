//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, e, f;
    char ch;

    printf("Welcome to the Matrix Operations!\n");
    printf("Please select an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    scanf("%c", &ch);

    switch (ch)
    {
        case '1':
            printf("Enter two numbers:");
            scanf("%d %d", &a, &b);
            c = a + b;
            printf("The sum of %d and %d is %d.\n", a, b, c);
            break;

        case '2':
            printf("Enter two numbers:");
            scanf("%d %d", &a, &b);
            c = a - b;
            printf("The difference of %d and %d is %d.\n", a, b, c);
            break;

        case '3':
            printf("Enter two numbers:");
            scanf("%d %d", &a, &b);
            c = a * b;
            printf("The product of %d and %d is %d.\n", a, b, c);
            break;

        case '4':
            printf("Enter two numbers:");
            scanf("%d %d", &a, &b);
            c = a / b;
            printf("The quotient of %d and %d is %d.\n", a, b, c);
            break;

        default:
            printf("Invalid input.\n");
    }

    return 0;
}