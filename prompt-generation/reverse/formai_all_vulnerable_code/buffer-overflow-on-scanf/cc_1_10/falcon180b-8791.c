//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 1000

// Function to find the maximum value in a given array
int findMax(int arr[], int n)
{
    int max = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the greedy algorithm for the fractional knapsack problem
int fractionalKnapsack(int val[], int wt[], int n, int W)
{
    int i, j, k;
    int knap[n]; // Array to store the selected items
    int totalValue = 0; // Total value of selected items
    int currWeight = 0; // Current weight of selected items

    // Initialize the knap array
    for(i=0; i<n; i++)
    {
        knap[i] = 0;
    }

    // Sort the array in decreasing order of value/weight ratio
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if((double)val[i]/wt[i] < (double)val[j]/wt[j])
            {
                int temp = val[i];
                val[i] = val[j];
                val[j] = temp;
                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;
            }
        }
    }

    // Apply the greedy algorithm
    for(i=0; i<n; i++)
    {
        if(currWeight + wt[i] <= W)
        {
            currWeight += wt[i];
            totalValue += val[i];
        }
        else if(currWeight == 0)
        {
            currWeight = wt[i];
            totalValue = val[i];
        }
        else if((double)val[i]/wt[i] > (double)totalValue/currWeight)
        {
            currWeight = wt[i];
            totalValue = val[i];
        }
    }

    return totalValue;
}

// Main function
int main()
{
    int n, i, j, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter the value and weight of each item:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d%d", &val[i], &wt[i]);
    }

    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    int result = fractionalKnapsack(val, wt, n, W);

    printf("The maximum value that can be obtained is: %d\n", result);

    return 0;
}