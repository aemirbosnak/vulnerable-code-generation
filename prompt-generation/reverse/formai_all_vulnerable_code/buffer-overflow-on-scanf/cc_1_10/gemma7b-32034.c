//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, x, y, z, min, max, sum = 0, ctr = 0, arr[MAX];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of elements: ");
        scanf("%d", &x);

        printf("Enter the elements: ");
        for (j = 0; j < x; j++)
        {
            scanf("%d", &arr[j]);
        }

        min = arr[0];
        max = arr[0];

        for (k = 0; k < x; k++)
        {
            if (arr[k] < min)
            {
                min = arr[k];
            }

            if (arr[k] > max)
            {
                max = arr[k];
            }
        }

        sum = 0;
        for (z = 0; z < x; z++)
        {
            sum += arr[z];
        }

        ctr = 0;
        for (z = 0; z < x; z++)
        {
            if (arr[z] % 2 == 0)
            {
                ctr++;
            }
        }

        printf("The minimum element is: %d\n", min);
        printf("The maximum element is: %d\n", max);
        printf("The total sum is: %d\n", sum);
        printf("The number of even elements is: %d\n", ctr);
    }

    return 0;
}