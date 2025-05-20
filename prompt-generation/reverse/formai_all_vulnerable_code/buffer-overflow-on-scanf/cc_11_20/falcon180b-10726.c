//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE];
    int n, i, j, temp;

    // Input array elements
    printf("Enter array elements:\n");
    for (i = 0; i < MAX_SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Perform arithmetic operations
    printf("Enter the operation:\n");
    scanf("%d", &n);

    switch (n)
    {
        case 1: // Addition
            for (i = 0; i < MAX_SIZE; i++)
            {
                arr[i] += arr[i];
            }
            printf("Result:\n");
            for (i = 0; i < MAX_SIZE; i++)
            {
                printf("%d ", arr[i]);
            }
            break;

        case 2: // Subtraction
            for (i = 0; i < MAX_SIZE; i++)
            {
                arr[i] -= arr[i];
            }
            printf("Result:\n");
            for (i = 0; i < MAX_SIZE; i++)
            {
                printf("%d ", arr[i]);
            }
            break;

        case 3: // Multiplication
            for (i = 0; i < MAX_SIZE; i++)
            {
                arr[i] *= arr[i];
            }
            printf("Result:\n");
            for (i = 0; i < MAX_SIZE; i++)
            {
                printf("%d ", arr[i]);
            }
            break;

        case 4: // Division
            for (i = 0; i < MAX_SIZE; i++)
            {
                if (arr[i] == 0)
                {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                arr[i] /= arr[i];
            }
            printf("Result:\n");
            for (i = 0; i < MAX_SIZE; i++)
            {
                printf("%d ", arr[i]);
            }
            break;

        default:
            printf("Invalid operation\n");
            exit(1);
    }

    return 0;
}