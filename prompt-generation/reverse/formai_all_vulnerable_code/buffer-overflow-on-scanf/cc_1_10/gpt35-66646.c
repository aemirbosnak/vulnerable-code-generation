//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include<stdio.h>

int main(){
    int n, i, j;
    float knapsack_weight, max_profit = 0, current_weight = 0, remaining_weight;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    float profit[n], weight[n], ratio[n];
    
    printf("\nEnter the profit and weight of each item:\n");
    
    for(i=0; i<n; i++){
        scanf("%f%f", &profit[i], &weight[i]);
        ratio[i] = profit[i] / weight[i];
    }
    
    printf("\nEnter the weight of the knapsack: ");
    scanf("%f", &knapsack_weight);
    
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(ratio[i] < ratio[j]){
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
                
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }
    
    remaining_weight = knapsack_weight;
    
    for(i=0; i<n; i++){
        if(weight[i] > remaining_weight){
            break;
        }
        current_weight += weight[i];
        max_profit += profit[i];
        remaining_weight -= weight[i];
    }
    
    if(i < n){
        max_profit += remaining_weight * ratio[i];
    }
    
    printf("\nMaximum Profit: %f", max_profit);
    
    return 0;
}