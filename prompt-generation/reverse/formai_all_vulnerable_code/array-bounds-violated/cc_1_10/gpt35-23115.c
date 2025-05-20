//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, temp;
    float mean, variance, sd;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate n random integers between 0 and 100
    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 101;
    }

    // Display the array
    printf("Array generated:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calculate mean
    mean = 0;
    for(i = 0; i < n; i++)
    {
        mean += arr[i];
    }
    mean /= n;

    // Calculate variance
    variance = 0;
    for(i = 0; i < n; i++)
    {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }
    variance /= n;

    // Calculate standard deviation
    sd = sqrt(variance);

    // Sort the array using bubble sort
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Display the sorted array
    printf("\n\nSorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Display the statistics
    printf("\n\nStatistics:\n");
    printf("Mean = %.2f\n", mean);
    printf("Variance = %.2f\n", variance);
    printf("Standard deviation = %.2f\n", sd);

    return 0;
}