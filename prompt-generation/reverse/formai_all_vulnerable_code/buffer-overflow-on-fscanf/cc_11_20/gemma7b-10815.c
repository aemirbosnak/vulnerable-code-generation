//Gemma-7B DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

int main()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char a[MAX], b[MAX], c[MAX], d[MAX], e[MAX], f[MAX], g[MAX], h[MAX], i_arr[MAX], j_arr[MAX], k_arr[MAX];
    float avg, sum, total, min, max, deviation, std_dev;
    FILE *fp;

    // Open the file
    fp = fopen("data.txt", "r");

    // Read the file content into the array
    fscanf(fp, "%s", a);

    // Close the file
    fclose(fp);

    // Preprocess the data
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = a[i] - 32;
        }
    }

    // Calculate the average
    sum = 0.0;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (isdigit(a[i]))
        {
            sum += atoi(a[i]) * atoi(a[i + 1]);
        }
    }
    avg = sum / 100.0;

    // Calculate the total
    total = 0.0;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (isdigit(a[i]))
        {
            total += atoi(a[i]);
        }
    }

    // Calculate the minimum
    min = MAX;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (isdigit(a[i]))
        {
            min = fmin(min, atoi(a[i]));
        }
    }

    // Calculate the maximum
    max = -MAX;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (isdigit(a[i]))
        {
            max = fmax(max, atoi(a[i]));
        }
    }

    // Calculate the deviation
    deviation = 0.0;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (isdigit(a[i]))
        {
            deviation += (atoi(a[i]) - avg) * (atoi(a[i]) - avg);
        }
    }
    std_dev = deviation / 100.0;

    // Print the results
    printf("Average: %.2f\n", avg);
    printf("Total: %.2f\n", total);
    printf("Minimum: %.2f\n", min);
    printf("Maximum: %.2f\n", max);
    printf("Deviation: %.2f\n", std_dev);

    return 0;
}