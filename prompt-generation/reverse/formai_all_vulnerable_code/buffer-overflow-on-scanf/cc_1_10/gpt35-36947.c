//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void knapsack(int n, float weight[], float profit[], float capacity);

// Description: A program that implements the greedy algorithm for the fractional knapsack problem.
//              The user inputs the number of items, their weights, profits, and the capacity of the knapsack.

int main()
{
    int n, i;
    float weight[MAX], profit[MAX], capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and profit of each item:\n");
    for(i=0; i<n; i++)
    {
        printf("Item %d weight: ", i+1);
        scanf("%f", &weight[i]);
        printf("Item %d profit: ", i+1);
        scanf("%f", &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    knapsack(n, weight, profit, capacity); 

    return 0;
}

void knapsack(int n, float weight[], float profit[], float capacity)
{
    int i, j;
    float ratio[MAX], temp;

    // Calculate the ratio of profit to weight for each item
    for(i=0; i<n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items in decreasing order of their ratio
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    float total_profit = 0, fraction;
    printf("\nItem\tWeight\tProfit\tRatio\n");

    for(i=0; i<n; i++)
    {
        if(weight[i]<=capacity)
        {
            capacity -= weight[i];
            total_profit += profit[i];
            printf("%d\t%.2f\t%.2f\t%.2f\n", i+1, weight[i], profit[i], ratio[i]);
        } 
        else
        {
            fraction = capacity / weight[i];
            total_profit += profit[i] * fraction;
            printf("%d\t%.2f\t%.2f\t%.2f\n", i+1, weight[i]*fraction, profit[i]*fraction, ratio[i]);
            break;
        }
    }

    printf("The total profit of the knapsack is %.2f\n", total_profit);
}