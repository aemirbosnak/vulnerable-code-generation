//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include<stdio.h>

int main()
{
    int a, b, sum, difference, product, quotient;

    printf("Enter two numbers:\n");

    scanf("%d%d", &a, &b);

    sum = a + b;
    difference = a - b;
    product = a * b;
    quotient = a / b;

    printf("\n\nThe sum of %d and %d is:%d\n", a, b, sum);

    printf("The difference of %d and %d is:%d\n", a, b, difference);

    printf("The product of %d and %d is:%d\n", a, b, product);

    printf("The quotient of %d and %d is:%d\n", a, b, quotient);

    if(a == b)
    {
        printf("The numbers are equal\n");
    }
    else if(a > b)
    {
        printf("The larger number is:%d\n", a);
    }
    else
    {
        printf("The larger number is:%d\n", b);
    }

    int i;
    printf("\n\nPrinting the even numbers between %d and %d:\n", a, b);
    for(i = a; i <= b; i++)
    {
        if(i % 2 == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n\nPrinting the odd numbers between %d and %d:\n", a, b);
    for(i = a; i <= b; i++)
    {
        if(i % 2 != 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n\nPrinting the Fibonacci sequence between %d and %d:\n", a, b);
    int n1 = 0, n2 = 1, n3 = 0;
    
    printf("%d %d ", n1, n2);
    
    while(n3 <= b)
    {
        n3 = n1 + n2;

        if(n3 >= a && n3 <= b)
        {
            printf("%d ", n3);
        }

        n1 = n2;
        n2 = n3;
    }

    printf("\n\nThank you for using this awesome arithmetic program!\n");

    return 0;
}