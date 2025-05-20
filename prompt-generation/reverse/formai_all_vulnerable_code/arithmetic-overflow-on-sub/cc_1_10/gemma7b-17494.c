//Gemma-7B DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void sortByHeight(int **arr, int n)
{
    int i, j, h, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i][1] > arr[j][1])
            {
                temp = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("Enter the number of students: ", &n);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the student's name: ");
        scanf("%s", arr[i][0]);
        printf("Enter the student's height: ");
        scanf("%d", &arr[i][1]);
    }

    sortByHeight(arr, n);

    printf("Sorted students by height:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s is %d cm tall\n", arr[i][0], arr[i][1]);
    }

    free(arr);

    return 0;
}