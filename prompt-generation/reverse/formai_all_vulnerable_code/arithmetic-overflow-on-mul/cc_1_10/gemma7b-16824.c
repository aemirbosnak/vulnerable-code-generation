//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, m, i, j, x, y, ctr = 0, arr[MAX];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the dimensions of the matrix: ");
        scanf("%d %d", &m, &n);

        printf("Enter the elements of the matrix: ");
        for (j = 0; j < m; j++)
        {
            for (y = 0; y < n; y++)
            {
                scanf("%d", &arr[ctr]);
                ctr++;
            }
        }

        x = findMedian(arr, m, n);
        printf("The median of the matrix is: %d\n", x);
    }

    return 0;
}

int findMedian(int *arr, int m, int n)
{
    int sum = 0, i, ctr = 0, med;

    for (i = 0; i < m; i++)
    {
        for (ctr = 0; ctr < n; ctr++)
        {
            sum += arr[ctr];
        }
    }

    med = sum / (m * n);

    return med;
}