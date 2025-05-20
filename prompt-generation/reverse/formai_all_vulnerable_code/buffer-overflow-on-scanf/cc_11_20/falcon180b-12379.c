//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

int main()
{
    int arr1[MAX_SIZE], arr2[MAX_SIZE], result[MAX_SIZE];
    int i, j, k;

    printf("Enter the elements of first array: ");
    for(i=0; i<MAX_SIZE && scanf("%d", &arr1[i])!= EOF; i++);

    printf("Enter the elements of second array: ");
    for(j=0; j<MAX_SIZE && scanf("%d", &arr2[j])!= EOF; j++);

    printf("Bitwise AND of arrays: ");
    for(k=0; k<MAX_SIZE; k++)
    {
        result[k] = arr1[k] & arr2[k];
        printf("%d ", result[k]);
    }
    printf("\n");

    printf("Bitwise OR of arrays: ");
    for(k=0; k<MAX_SIZE; k++)
    {
        result[k] = arr1[k] | arr2[k];
        printf("%d ", result[k]);
    }
    printf("\n");

    printf("Bitwise XOR of arrays: ");
    for(k=0; k<MAX_SIZE; k++)
    {
        result[k] = arr1[k] ^ arr2[k];
        printf("%d ", result[k]);
    }
    printf("\n");

    printf("Bitwise NOT of second array: ");
    for(k=0; k<MAX_SIZE; k++)
    {
        result[k] = ~arr2[k];
        printf("%d ", result[k]);
    }
    printf("\n");

    printf("Left shift of second array by 2: ");
    for(k=0; k<MAX_SIZE; k++)
    {
        result[k] = arr2[k] << 2;
        printf("%d ", result[k]);
    }
    printf("\n");

    printf("Right shift of second array by 2: ");
    for(k=0; k<MAX_SIZE; k++)
    {
        result[k] = arr2[k] >> 2;
        printf("%d ", result[k]);
    }
    printf("\n");

    return 0;
}