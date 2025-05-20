//Gemma-7B DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main()
{
    int i, j, k, l, n, m, data[MAX_SIZE], frequency[MAX_SIZE] = {0};
    float avg, stddev, range, min, max;

    // Reading the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Reading the elements
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    // Calculating the frequency of each element
    for (i = 0; i < n; i++)
    {
        frequency[data[i]]++;
    }

    // Calculating the average
    avg = (float)sum(frequency) / n;

    // Calculating the standard deviation
    stddev = sqrt((float)sumSq(frequency) / n - avg * avg) / n;

    // Calculating the range
    range = max - min;

    // Printing the results
    printf("The average is: %.2f\n", avg);
    printf("The standard deviation is: %.2f\n", stddev);
    printf("The range is: %.2f\n", range);

    return 0;
}

int sum(int arr[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int sumSq(int arr[], int n)
{
    int i, sumSq = 0;

    for (i = 0; i < n; i++)
    {
        sumSq += arr[i] * arr[i];
    }

    return sumSq;
}