//Gemma-7B DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void sortByAge(int **arr, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*arr)[j] < (*arr)[min])
            {
                min = j;
            }
        }
        temp = (*arr)[min];
        (*arr)[min] = (*arr)[i];
        (*arr)[i] = temp;
    }
}

int main()
{
    int n, i;
    int **arr;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    printf("Enter the ages of each person: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    sortByAge(arr, n);

    printf("Sorted list of ages:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}