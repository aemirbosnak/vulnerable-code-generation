//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>

// function to generate fibonacci sequence up to n terms
int *fibonacci(int n)
{
    static int fib[100]; // static array to hold the sequence
    fib[0] = 0; // base case
    fib[1] = 1; // base case

    for(int i=2; i<n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2]; // formula to generate next term
    }

    return fib;
}

// function to print the fibonacci sequence
void printFibonacci(int n, int *fib)
{
    printf("Fibonacci Sequence:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

// function to display the sequence visually
void displayFibonacci(int n, int *fib)
{
    printf("Fibonacci Sequence Visualizer:\n");

    // determine the maximum number of digits in the sequence
    int maxDigits = 0;
    for(int i=0; i<n; i++)
    {
        int digits = 1;
        int num = fib[i];
        while(num/10 > 0)
        {
            num /= 10;
            digits++;
        }
        if(digits > maxDigits)
            maxDigits = digits;
    }

    // display the sequence row by row
    for(int j=maxDigits; j>=1; j--)
    {
        for(int i=0; i<n; i++)
        {
            int digits = 1;
            int num = fib[i];
            while(num/10 > 0)
            {
                num /= 10;
                digits++;
            }

            // add leading spaces to align the digits
            for(int k=0; k<maxDigits-digits; k++)
                printf(" ");

            // display the digit if it exists, otherwise display a space
            if(j <= digits)
                printf("%d", (fib[i] / (int)pow(10,j-1))%10);
            else
                printf(" ");

            // add spacing between columns
            printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int *fib = fibonacci(n);
    printFibonacci(n,fib);
    printf("\n");
    displayFibonacci(n,fib);

    return 0;
}