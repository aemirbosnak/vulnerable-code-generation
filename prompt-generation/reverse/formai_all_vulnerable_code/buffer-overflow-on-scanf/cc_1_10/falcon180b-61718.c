//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

int main()
{
    int n;
    int arr[MAX_SIZE];
    int sum = 0;
    int max_sum = 0;
    int i, j, k;
    int index;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("The sum of the array elements is %d\n", sum);

    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        index = rand() % n;
        for (j = i; j < index; j++)
        {
            k = arr[j];
            arr[j] = arr[index];
            arr[index] = k;
        }
    }

    printf("The randomized array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    max_sum = arr[0];
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }

    printf("The maximum sum of subarray is %d\n", max_sum);

    return 0;
}