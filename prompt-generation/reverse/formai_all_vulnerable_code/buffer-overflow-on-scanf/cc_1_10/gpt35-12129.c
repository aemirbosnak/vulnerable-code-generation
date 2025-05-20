//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>

void knapSack(int *wt, float *val, int n, int W)
{
    float *ratio = malloc(n*sizeof(float));   // Array to store ratios of values and weights
    int i, j, temp;   // Variables for loop iterators and temporary storage
    
    // Calculation of ratios
    for(i = 0; i < n; i++)
        ratio[i] = val[i]/wt[i];
    
    // Bubble sort based on ratios
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(ratio[j] < ratio[j+1])
            {
                // Swapping of ratios
                temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;
                
                // Swapping of weights
                temp = wt[j];
                wt[j] = wt[j+1];
                wt[j+1] = temp;
                
                // Swapping of values
                float tmp = val[j];
                val[j] = val[j+1];
                val[j+1] = tmp;
            }
        }
    }
    
    int curWt = 0;   // Current weight of knapsack
    float finalVal = 0;   // Maximum value
    
    // Calculation of maximum value
    for(i = 0; i < n; i++)
    {
        if(curWt + wt[i] <= W)
        {
            curWt += wt[i];
            finalVal += val[i];
        }
        else
        {
            int remainWt = W - curWt;
            finalVal += (val[i]/wt[i]) * remainWt;
            break;
        }
    }
    
    printf("The maximum value that can be obtained is: %f", finalVal);
    free(ratio);
}

int main()
{
    int i, n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight that the knapsack can carry: ");
    scanf("%d", &W);
    
    int *wt = malloc(n*sizeof(int));   // Array to store weights
    float *val = malloc(n*sizeof(float));   // Array to store values
    
    // Input of weights and values of each item
    for(i = 0; i < n; i++)
    {
        printf("Enter the weight and value of item %d: ", i+1);
        scanf("%d %f", &wt[i], &val[i]);
    }
    
    knapSack(wt, val, n, W);
    
    free(wt);
    free(val);
    
    return 0;
}