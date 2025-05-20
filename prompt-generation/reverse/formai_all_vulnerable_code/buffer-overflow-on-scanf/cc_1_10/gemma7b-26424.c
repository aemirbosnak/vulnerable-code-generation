//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, k, max_sum = 0, current_sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            current_sum = 0;
            for (k = 0; k < n; k++)
            {
                if (arr[k][i] > current_sum)
                {
                    current_sum = arr[k][i];
                }
            }
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
        }
    }
    printf("The maximum sum is: %d", max_sum);
}

int main()
{
    int n, i, j, **arr = NULL;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the marks for each student in each subject: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}