//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

int n;
int m;
int wt[MAX];
int val[MAX];
int W = 50;

// Function to find the maximum value of a given item that can be included in knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i = 0;
    int k = 0;

    for (i = 0; i < n; i++)
    {
        if (wt[i] <= W)
        {
            k += val[i];
        }
    }
    return k;
}

// Function to implement the greedy algorithm to solve the knapsack problem
void greedyAlgorithm(int val[], int wt[], int n)
{
    int W = 50;
    int k = 0;
    int i = 0;

    while (k < W)
    {
        int max_val_index = 0;

        for (i = 0; i < n; i++)
        {
            if (wt[i] <= W && val[i] > val[max_val_index])
            {
                max_val_index = i;
            }
        }

        k += val[max_val_index];
        W -= wt[max_val_index];
    }

    printf("The maximum value that can be obtained is: %d\n", k);
}

// Main function to run the program
int main()
{
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("The maximum value that can be obtained is: ");
    greedyAlgorithm(val, wt, n);

    return 0;
}