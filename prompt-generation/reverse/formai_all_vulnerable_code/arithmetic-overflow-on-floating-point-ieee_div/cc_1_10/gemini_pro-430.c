//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Declare variables
    int n, W, i, j, w[100], v[100], x[100];
    float p[100];

    // Get input
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
        p[i] = (float)v[i] / w[i];
    }

    // Sort the items in decreasing order of profit per unit weight
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i] < p[j])
            {
                int temp1 = w[i];
                int temp2 = v[i];
                float temp3 = p[i];
                w[i] = w[j];
                v[i] = v[j];
                p[i] = p[j];
                w[j] = temp1;
                v[j] = temp2;
                p[j] = temp3;
            }
        }
    }

    // Initialize the solution
    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    // Fill the knapsack
    int weight = 0;
    int value = 0;
    for (i = 0; i < n; i++)
    {
        if (weight + w[i] <= W)
        {
            weight += w[i];
            value += v[i];
            x[i] = 1;
        }
    }

    // Print the solution
    printf("The optimal solution is:\n");
    printf("Item  Weight  Value  Status\n");
    for (i = 0; i < n; i++)
    {
        printf("%d    %d    %d    %d\n", i + 1, w[i], v[i], x[i]);
    }
    printf("Total weight: %d\n", weight);
    printf("Total value: %d\n", value);

    return 0;
}