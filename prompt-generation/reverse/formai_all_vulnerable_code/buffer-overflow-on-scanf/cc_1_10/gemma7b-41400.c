//Gemma-7B DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define MAX 100

int main()
{
    int i, j, k, n, m, a[MAX], b[MAX], c[MAX];
    float x, y, z, avg, stddev, min, max, range;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Calculate the average
    avg = 0.0;
    for (i = 0; i < n; i++)
    {
        avg += a[i];
    }
    avg /= n;

    // Calculate the standard deviation
    stddev = 0.0;
    for (i = 0; i < n; i++)
    {
        stddev += (a[i] - avg) * (a[i] - avg);
    }
    stddev /= n;
    stddev = sqrt(stddev);

    // Calculate the minimum
    min = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    // Calculate the maximum
    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    // Calculate the range
    range = max - min;

    // Print the results
    printf("The average is: %.2f\n", avg);
    printf("The standard deviation is: %.2f\n", stddev);
    printf("The minimum is: %.2f\n", min);
    printf("The maximum is: %.2f\n", max);
    printf("The range is: %.2f\n", range);

    return 0;
}