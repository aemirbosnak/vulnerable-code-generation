//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>

#define MAX_WT 100
#define MAX_VAL 100

int n, maxWt;
int w[MAX_WT];
int v[MAX_VAL];
float density[MAX_VAL];

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort()
{
    for (int i = 0; i < n; i++)
        density[i] = (float)v[i] / w[i];

    for (int i = 0; i < n - 1; i++)
    {
        int maxPos = i;

        for (int j = i + 1; j < n; j++)
        {
            if (density[j] > density[maxPos])
                maxPos = j;
        }

        swap(&density[maxPos], &density[i]);
        swap(&w[maxPos], &w[i]);
        swap(&v[maxPos], &v[i]);
    }
}

float fractionalKnapsack()
{
    float totalValue = 0;
    int currWt = 0;

    for (int i = 0; i < n; i++)
    {
        if (currWt + w[i] <= maxWt)
        {
            currWt += w[i];
            totalValue += v[i];
        }
        else
        {
            int remainingWt = maxWt - currWt;
            totalValue += v[i] * ((float)remainingWt / w[i]);
            break;
        }
    }

    return totalValue;
}

int main()
{
    printf("Enter the number of items\n");
    scanf("%d", &n);

    printf("Enter the maximum weight the bag can hold\n");
    scanf("%d", &maxWt);

    printf("Enter the weight and value of each item\n");
    for (int i = 0; i < n; i++)
    {
        printf("Weight: ");
        scanf("%d", &w[i]);

        printf("Value: ");
        scanf("%d", &v[i]);
    }

    sort();

    float maxVal = fractionalKnapsack();

    printf("The maximum value that can be put in a knapsack of capacity %d is %f\n", maxWt, maxVal);

    return 0;
}