//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int search(int n, int target, int **arr)
{
    int i, found = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, target, i;
    int **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target: ");
    scanf("%d", &target);

    if (search(n, target, arr) == 1)
    {
        printf("Target found.\n");
    }
    else
    {
        printf("Target not found.\n");
    }

    return 0;
}