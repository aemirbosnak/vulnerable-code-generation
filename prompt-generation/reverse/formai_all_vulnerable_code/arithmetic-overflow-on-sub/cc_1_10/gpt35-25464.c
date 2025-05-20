//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#define MAX 100

int n;
int items[MAX][2];

// function to swap two items
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to sort items based on their value/weight ratio in descending order 
void sort_items()
{
    float ratio[n];
    int i, j;
    for(i = 0; i < n; i++)
        ratio[i] = (float)items[i][0] / (float)items[i][1];
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(ratio[i] < ratio[j]) 
            {
                swap(&items[i][0], &items[j][0]);
                swap(&items[i][1], &items[j][1]);
                swap(&ratio[i], &ratio[j]);
            }
}

// function to calculate the maximum profit based on the given weight limit
int knapsack(int W)
{
    int i, wt = 0;
    float ratio, profit = 0.0;
    for(i = 0; i < n; i++)
    {
        if(wt + items[i][1] <= W)
        {
            wt += items[i][1];
            profit += items[i][0];
        }
        else
        {
            ratio = (float)(W - wt) / (float)items[i][1];
            wt += ratio * items[i][1];
            profit += ratio * items[i][0];
            break;
        }
    }
    return profit;
}

// main function
int main()
{
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the value and weight of the items:\n");
    for(int i = 0; i < n; i++)
        scanf("%d%d", &items[i][0], &items[i][1]);
    printf("Enter the weight limit of the knapsack: ");
    int W;
    scanf("%d", &W);
    // sort the items based on their value/weight ratio to apply the greedy strategy
    sort_items();
    int max_profit = knapsack(W);
    printf("The maximum profit for the given weight limit is: %d\n", max_profit);
    return 0;
}