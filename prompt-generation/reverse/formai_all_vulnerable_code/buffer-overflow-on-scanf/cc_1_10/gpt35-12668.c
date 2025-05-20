//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
//The Artistic Kali Search Algorithm
//Written By: The Coding Artist
//Date: 10/08/2021
//Description: This is a unique searching algorithm that uses an unconventional approach to find the desired value in an array.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int arr[100], i, n, x, index;
    printf("---- The Artistic Kali Search Algorithm ----\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //Randomly generating the array
    srand(time(0));
    for(i=0; i<n; i++)
    {
        arr[i] = rand() % 1000;
    }

    printf("\nGenerated array is: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the number to search: ");
    scanf("%d", &x);

    //Artistic searching
    index = -1;
    for(i=0; i<n; i++)
    {
        if(arr[i] == x)
        {
            index = i;
            printf("\nKali has seen the value at index %d! Let's celebrate!", index);
            break;
        }
    }

    if(index == -1)
    {
        printf("\nOops! Kali couldn't find the value in the array.");
    }

    return 0;
}