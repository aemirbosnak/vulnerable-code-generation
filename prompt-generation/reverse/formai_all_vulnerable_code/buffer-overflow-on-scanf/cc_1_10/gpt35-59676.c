//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

// Recursive function to find the factorial of a number
int factorial(int num)
{
    if(num <= 1)
        return 1;

    return num * factorial(num-1);
}

// Recursive function to print the first 'n' numbers of the Fibonacci sequence
void fibonacci(int n, int num1, int num2)
{
    if(n == 0)
        return;

    printf("%d, ", num1);
    fibonacci(n-1, num2, num1+num2);
}

// Recursive function to print the elements of an array in reverse order
void reverseArray(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start+1, end-1);
}

// Recursive function to find the sum of digits of a number
int sumOfDigits(int num)
{
    if(num == 0)
        return 0;

    return (num%10) + sumOfDigits(num/10);
}

int main()
{
    int choice, num, n, i, sum;
    int arr[100];

    // Menu driven program to showcase different recursive functions
    printf("Choose an option:\n");
    printf("1. Find factorial of a number\n");
    printf("2. Print first 'n' elements of Fibonacci sequence\n");
    printf("3. Reverse an array\n");
    printf("4. Find sum of digits of a number\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("Factorial of %d is: %d\n", num, factorial(num));
            break;

        case 2:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Fibonacci series: ");
            fibonacci(n, 0, 1);
            printf("\n");
            break;

        case 3:
            printf("Enter number of elements in array: ");
            scanf("%d", &n);
            printf("Enter %d elements: ", n);
            for(i=0; i<n; i++)
                scanf("%d", &arr[i]);
            reverseArray(arr, 0, n-1);
            printf("Reversed array: ");
            for(i=0; i<n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            break;

        case 4:
            printf("Enter a number: ");
            scanf("%d", &num);
            sum = sumOfDigits(num);
            printf("Sum of digits of %d is: %d\n", num, sum);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}