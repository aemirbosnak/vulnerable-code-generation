//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>

void fibonacci(int num)
{
    int a = 0, b = 1, sum;

    printf("%d %d ", a, b);

    for(int i=2; i<num; i++)
    {
        sum = a + b;
        printf("%d ", sum);
        a = b;
        b = sum;
    }
}

void printLine(int n)
{
    for(int i=0; i<n; i++)
        printf("-");
    printf("\n");
}

int main()
{
    int num;
    printf("Enter the number of terms in Fibonacci sequence to be printed: ");
    scanf("%d", &num);

    printf("\n");

    printf("The Fibonacci sequence for first %d terms: \n\n", num);
    fibonacci(num);

    printf("\n\n");

    int count = 0;
    int temp = num;
    while(temp)
    {
        temp = temp/10;
        count++;
    }

    printLine(count*3);
    printf("|");
    for(int i=0; i<num; i++)
        printf(" %2d |", i+1);

    printf("\n");
    printLine(count*3);

    int a = 0, b = 1, sum;
    printf("| %2d | %2d |", a, b);
    for(int i=2; i<num; i++)
    {
        sum = a + b;
        printf(" %2d |", sum);
        a = b;
        b = sum;
    }

    printf("\n");
    printLine(count*3);

    return 0;
}