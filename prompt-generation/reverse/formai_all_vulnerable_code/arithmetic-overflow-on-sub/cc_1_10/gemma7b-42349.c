//Gemma-7B DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void sortByAge(int **arr, int n)
{
    int i, j, k, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*arr[j]) < (*arr[min]))
            {
                min = j;
            }
        }

        temp = (*arr[min]);
        (*arr[min]) = (*arr[i]);
        (*arr[i]) = temp;
    }
}

int main()
{
    int n, i;
    int *arr;

    printf("Enter the number of persons: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the age of each person: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sortByAge(&arr, n);

    printf("Sorted by age:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}