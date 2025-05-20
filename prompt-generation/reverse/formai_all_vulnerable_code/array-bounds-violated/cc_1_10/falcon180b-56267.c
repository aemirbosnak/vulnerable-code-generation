//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, max, min, sum = 0, count = 0;
    float avg;
    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("The array of %d elements is:\n", n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    max = arr[0];
    min = arr[0];

    for(i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("The maximum element is %d\n", max);
    printf("The minimum element is %d\n", min);

    sum = 0;

    for(i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = (float)sum / n;

    printf("The average of the array is %.2f\n", avg);

    for(i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            count++;
        }
    }

    printf("The number of even elements in the array is %d\n", count);

    return 0;
}