//Falcon-180B DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_TRIALS 100

int main()
{
    int i, j, k, n, m, count = 0, trials = 0;
    int *arr;
    int sum = 0;
    int flag = 0;
    int seed;
    struct timespec tp;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Error: Memory could not be allocated.\n");
        exit(0);
    }

    printf("Enter the elements of the array: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Enter the number of trials: ");
    scanf("%d", &trials);

    seed = time(NULL);

    srand(seed);

    for (k = 0; k < trials; k++)
    {
        for (i = 0; i < n; i++)
        {
            j = rand() % n;

            if (i!= j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        flag = 0;

        for (i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            count++;
        }
    }

    printf("The number of times the array was sorted in ascending order is %d.\n", count);

    free(arr);

    return 0;
}