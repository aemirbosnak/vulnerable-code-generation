//Falcon-180B DATASET v1.0 Category: File handling ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate the sum of series using Euler's formula
float sum_of_series(int n, float x)
{
    float sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += pow(x, i);
    }
    return sum;
}

// Function to calculate the factorial of a number
int factorial(int n)
{
    int fact = 1;
    for(int i=1; i<=n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    FILE *fp;
    char filename[20];
    int choice, n, i;
    float x, sum;

    // Menu-driven program to perform mathematical operations
    printf("Enter 1 to calculate the sum of series using Euler's formula\n");
    printf("Enter 2 to calculate the factorial of a number\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the number of terms in the series: ");
            scanf("%d", &n);
            printf("Enter the value of x: ");
            scanf("%f", &x);
            printf("The sum of the series is: %.2f\n", sum_of_series(n, x));
            break;

        case 2:
            printf("Enter the number to find the factorial: ");
            scanf("%d", &n);
            printf("The factorial of %d is: %d\n", n, factorial(n));
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}