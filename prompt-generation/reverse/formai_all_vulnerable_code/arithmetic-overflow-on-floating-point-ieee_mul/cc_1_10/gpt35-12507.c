//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

#define MAX 50

int main()
{
    int n, i, j, temp, cost = 0;
    int weight[MAX], profit[MAX], ratio[MAX];
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the weight and profit of each item: \n");
    for(i=0; i<n; i++)
    {
        printf("Weight of item %d: ", i+1);
        scanf("%d", &weight[i]);
        
        printf("Profit of item %d: ", i+1);
        scanf("%d", &profit[i]);
        
        ratio[i] = profit[i]/weight[i];
    }
    
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
    
    int capacity;
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    float frac[MAX];
    float totalprofit = 0;
    
    for(i=0; i<n; i++)
    {
        if(weight[i]>capacity)
        {
            break;
        }
        else
        {
            frac[i] = 1.0;
            totalprofit += profit[i];
            capacity -= weight[i];
        }
    }
    
    if(i<n)
    {
        frac[i] = (float)capacity/weight[i];
    }
    
    totalprofit += (frac[i]*profit[i]);
    
    printf("\nResults:\n");
    printf("Maximum profit: %.2f", totalprofit);
    
    return 0;
}