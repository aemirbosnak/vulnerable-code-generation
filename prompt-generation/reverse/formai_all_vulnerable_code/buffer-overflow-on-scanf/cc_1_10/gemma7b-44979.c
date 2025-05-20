//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm(int **arr, int n)
{
    int i, j, total = 0, current_size = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] && current_size < total)
            {
                current_size++;
                total++;
            }
        }
    }
    printf("Total number of students: %d", total);
}

int main()
{
    int i, j, n, **arr;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * MAX * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    printf("Enter the seating arrangement: ");
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