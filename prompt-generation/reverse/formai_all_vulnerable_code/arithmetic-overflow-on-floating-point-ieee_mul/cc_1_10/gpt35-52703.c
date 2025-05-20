//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include<stdio.h>

// function prototype
void knapsack(int n, float weight[], float profit[], float capacity);

int main()
{
    int n, i, j;
    float weight[20], profit[20], capacity, ratio[20], temp;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the weights and profits of each item:\n");
    for(i=0; i<n; i++)
    {
        printf("Weight[%d]: ", i+1);
        scanf("%f", &weight[i]);
        printf("Profit[%d]: ", i+1);
        scanf("%f", &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    // sorting the items based on profit/weight ratio in non-increasing order
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i] < ratio[j])
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

    knapsack(n, weight, profit, capacity);
     
    return 0;
}

// function to implement greedy knapsack algorithm
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], total_profit=0;
    int i, j;

    for(i=0; i<n; i++)
        x[i] = 0.0;

    for(i=0; i<n; i++)
    {
        if(weight[i] > capacity)
            break;
        else
        {
            x[i] = 1.0;
            total_profit += profit[i];
            capacity -= weight[i];
        }
    }

    if(i<n)
        x[i] = capacity / weight[i];

    total_profit += x[i] * profit[i];

    printf("The selected elements are:\n");
    for(i=0; i<n; i++)
    {
        if(x[i] != 0.0)
            printf("Item %d with weight %.2f and profit %.2f\n", i+1, weight[i], profit[i]);
    }

    printf("The total profit is: %.2f\n", total_profit);
}