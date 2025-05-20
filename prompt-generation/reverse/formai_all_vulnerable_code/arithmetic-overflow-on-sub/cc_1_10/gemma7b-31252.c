//Gemma-7B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void sortByAge(int **arr, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((*arr)[i] > (*arr)[j])
            {
                temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
}

int main()
{
    int i, n, **arr;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the ages of each student: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sortByAge(arr, n);

    printf("Sorted list of students by age:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    free(arr);

    return 0;
}