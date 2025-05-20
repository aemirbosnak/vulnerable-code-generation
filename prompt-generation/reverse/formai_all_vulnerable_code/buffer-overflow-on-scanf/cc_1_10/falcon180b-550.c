//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];
    int res[MAX_SIZE];
    int i, j, k, n;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n);

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("Bitwise operations on arrays:\n");
    printf("-----------------------------\n");
    printf("OR:\n");
    for (i = 0; i < n; i++)
    {
        res[i] = arr1[i] | arr2[i];
        printf("%d ", res[i]);
    }
    printf("\n");

    printf("AND:\n");
    for (i = 0; i < n; i++)
    {
        res[i] = arr1[i] & arr2[i];
        printf("%d ", res[i]);
    }
    printf("\n");

    printf("XOR:\n");
    for (i = 0; i < n; i++)
    {
        res[i] = arr1[i] ^ arr2[i];
        printf("%d ", res[i]);
    }
    printf("\n");

    printf("NOT:\n");
    for (i = 0; i < n; i++)
    {
        res[i] = ~arr1[i];
        printf("%d ", res[i]);
    }
    printf("\n");

    printf("Shift left:\n");
    for (i = 0; i < n; i++)
    {
        res[i] = arr1[i] << 2;
        printf("%d ", res[i]);
    }
    printf("\n");

    printf("Shift right:\n");
    for (i = 0; i < n; i++)
    {
        res[i] = arr1[i] >> 2;
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}