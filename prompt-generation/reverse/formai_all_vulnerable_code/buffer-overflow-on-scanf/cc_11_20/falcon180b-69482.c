//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define MAX_VALUE 100

int main()
{
    int arr1[SIZE], arr2[SIZE];
    int choice, i, j, carry=0;

    printf("Enter the elements of first array:\n");
    for(i=0; i<SIZE; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of second array:\n");
    for(i=0; i<SIZE; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("Choose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // Addition
            printf("Addition:\n");
            for(i=0; i<SIZE; i++)
            {
                int sum=arr1[i]+arr2[i]+carry;
                if(sum>MAX_VALUE)
                {
                    printf("Overflow at position %d\n", i);
                    exit(0);
                }
                arr1[i]=sum;
                carry=0;
            }
            break;

        case 2: // Subtraction
            printf("Subtraction:\n");
            for(i=0; i<SIZE; i++)
            {
                int diff=arr1[i]-arr2[i]-carry;
                if(diff<0)
                {
                    printf("Underflow at position %d\n", i);
                    exit(0);
                }
                arr1[i]=diff;
                carry=0;
            }
            break;

        case 3: // Multiplication
            printf("Multiplication:\n");
            for(i=0; i<SIZE; i++)
            {
                int prod=arr1[i]*arr2[i]+carry;
                if(prod>MAX_VALUE)
                {
                    printf("Overflow at position %d\n", i);
                    exit(0);
                }
                arr1[i]=prod;
                carry=0;
            }
            break;

        default:
            printf("Invalid operation\n");
            exit(0);
    }

    printf("Result:\n");
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", arr1[i]);
    }

    return 0;
}