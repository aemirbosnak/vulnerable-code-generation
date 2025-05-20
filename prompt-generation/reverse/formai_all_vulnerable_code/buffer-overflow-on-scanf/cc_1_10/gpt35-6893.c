//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include<stdio.h>

// Function to calculate factorial of a number
int factorial(int num)
{
    if(num == 0)
        return 1;
    else
        return num * factorial(num-1);
}

// Function to calculate nCr value using factorial function
int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n-r));
}

// Function to print Pascal's triangle of n rows
void printPascalTriangle(int n)
{
    int i, j;

    // Loop for each row
    for(i=0; i<n; i++)
    {
        // Loop to print n-i spaces in each row
        for(j=0; j<n-i; j++)
        {
            printf(" ");
        }

        // Loop to print values in each row
        for(j=0; j<=i; j++)
        {
            printf("%d ", nCr(i, j));
        }

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &n);

    // Print Pascal's triangle
    printPascalTriangle(n);

    return 0;
}