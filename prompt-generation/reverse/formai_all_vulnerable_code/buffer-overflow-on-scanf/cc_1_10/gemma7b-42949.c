//Gemma-7B DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void sortByHeight(int **arr, int n)
{
    int i, j, h, currentHeight = 0, swapFlag = 0;

    for (i = 0; i < n; i++)
    {
        h = arr[i][1];
        if (h > currentHeight)
        {
            currentHeight = h;
            swapFlag = 1;
        }
    }

    if (swapFlag)
    {
        for (i = 0; i < n; i++)
        {
            h = arr[i][1];
            if (h == currentHeight)
            {
                for (j = i; j < n; j++)
                {
                    if (arr[j][1] < h)
                    {
                        int temp = arr[i][0];
                        arr[i][0] = arr[j][0];
                        arr[j][0] = temp;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the item details (name and height):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", arr[i][0], &arr[i][1]);
    }

    sortByHeight(arr, n);

    printf("Sorted items:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s at height %d\n", arr[i][0], arr[i][1]);
    }

    return 0;
}