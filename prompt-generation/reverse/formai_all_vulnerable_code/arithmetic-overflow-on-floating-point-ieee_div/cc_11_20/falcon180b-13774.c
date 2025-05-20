//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 1000000

int main()
{
    int i, j, k, n, m, count = 0;
    double sum = 0.0, avg, std_dev;
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    for (i = 0; i < n; i++)
    {
        if (str[i] == '0' || str[i] == '1')
        {
            count++;
        }
    }

    if (count == n)
    {
        printf("Valid binary string.\n");
    }
    else
    {
        printf("Invalid binary string.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            m++;
        }
        else if (str[i] == '1')
        {
            m--;
        }
    }

    avg = (double)m / n;

    for (i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            sum += pow((double)i - avg, 2.0);
        }
        else if (str[i] == '1')
        {
            sum += pow((double)i - avg, 2.0);
        }
    }

    std_dev = sqrt(sum / n);

    printf("Average: %.2f\n", avg);
    printf("Standard deviation: %.2f\n", std_dev);

    return 0;
}