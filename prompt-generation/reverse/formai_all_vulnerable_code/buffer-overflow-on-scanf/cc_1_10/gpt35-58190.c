//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int weights[MAX], profits[MAX], knapsack[MAX];
float ratios[MAX];

void sort(int n)
{
    int i, j;
    float temp;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratios[j]>ratios[i])
            {
                temp=ratios[i];
                ratios[i]=ratios[j];
                ratios[j]=temp;

                temp=weights[i];
                weights[i]=weights[j];
                weights[j]=temp;

                temp=profits[i];
                profits[i]=profits[j];
                profits[j]=temp;
            }
        }
    }
}

void knapsackGreedy(int n, int capacity)
{
    int i;
    float profit=0.0;
    sort(n);
    for(i=0; i<n; i++)
    {
        if(weights[i]>capacity)
        {
            break;
        }
        knapsack[i]=1;
        capacity-=weights[i];
        profit+=profits[i];
    }
    if(i<n)
    {
        knapsack[i]=capacity/weights[i];
        profit+=(knapsack[i]*profits[i]);
    }
    printf("\nItems in the knapsack:\n");
    for(i=0; i<n; i++)
    {
        if(knapsack[i]==1)
        {
            printf("Item %d with weight %d and profit %d is put in knapsack.\n",i+1,weights[i],profits[i]);
        }
        else if(knapsack[i]>1)
        {
            printf("Item %d with weight %d and profit %d is put %d times in knapsack.\n",i+1,weights[i],profits[i],knapsack[i]);
        }
    }
    printf("\nMaximum profit in the knapsack = %.2f",profit);
}

int main()
{
    int n, capacity, i;
    printf("Enter the number of items:\n");
    scanf("%d",&n);

    printf("\nEnter the capacity of the knapsack:\n");
    scanf("%d",&capacity);

    printf("\nEnter the weights of the items:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&weights[i]);
    }

    printf("\nEnter the profits of the items:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&profits[i]);
    }

    for(i=0; i<n; i++)
    {
        ratios[i]=(float)profits[i]/weights[i];
    }

    knapsackGreedy(n,capacity);

    return 0;
}