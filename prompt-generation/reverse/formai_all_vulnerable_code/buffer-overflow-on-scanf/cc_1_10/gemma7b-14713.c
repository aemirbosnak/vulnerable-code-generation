//Gemma-7B DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void dancing_queen(int n);

int main()
{
    int n;

    printf("Enter the number of dancers: ");
    scanf("%d", &n);

    dancing_queen(n);

    return 0;
}

void dancing_queen(int n)
{
    int i, j, k, count = 0;
    int *arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        arr[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                arr[i] = 0;
            }
            else
            {
                arr[i] = 1;
            }
        }
    }

    for (k = 0; k < n; k++)
    {
        if (arr[k] == 0)
        {
            count++;
        }
    }

    printf("The number of lonely dancers is: %d", count);
}