//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
/* Invasive Greedy Algorithm Example in C */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, k, t, sum = 0;
    srand(time(NULL));

    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];

    for(i=0; i<n; i++)
    {
        arr[i] = rand() % 100 + 1; //generating random integers between 1 and 100
        printf("%d ", arr[i]);
    }
    printf("\n");

    //sorting the array using selection sort algorithm
    for(i=0; i<n-1; i++)
    {
        k = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
        }
        t = arr[i];
        arr[i] = arr[k];
        arr[k] = t;
    }

    printf("Sorted Array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //finding sum of smallest k elements in the sorted array
    printf("Enter the value of k: ");
    scanf("%d",&k);
    for(i=0; i<k; i++)
    {
        sum += arr[i];
    }

    printf("Sum of smallest %d elements in the array: %d", k, sum);

    return 0;
}