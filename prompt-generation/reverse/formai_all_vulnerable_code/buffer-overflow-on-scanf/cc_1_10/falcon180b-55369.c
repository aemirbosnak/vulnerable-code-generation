//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//Function to calculate factorial of a number
long long int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

//Function to calculate nCr
long long int nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n-r));
}

//Function to calculate nPr
long long int nPr(int n, int r)
{
    return factorial(n) / factorial(n-r);
}

//Function to calculate sum of series
long long int seriesSum(int n, int a, int r)
{
    return (n-1) * (2*a + (n-1)*r);
}

int main()
{
    int n, r, a;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of r: ");
    scanf("%d", &r);
    printf("Enter the value of a: ");
    scanf("%d", &a);

    //Calculate nCr
    printf("nCr = %lld\n", nCr(n, r));

    //Calculate nPr
    printf("nPr = %lld\n", nPr(n, r));

    //Calculate sum of series
    printf("Sum of series = %lld\n", seriesSum(n, a, r));

    return 0;
}