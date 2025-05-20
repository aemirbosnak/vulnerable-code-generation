//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include<stdio.h>

int main(){

    int n, s, i, j;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int capacity[n], profit[n], index[n];
    float ratio[n], total_profit = 0, max_capacity;

    for(i = 0; i < n; i++){
        printf("\nEnter the capacity of Item %d: ", i+1);
        scanf("%d", &capacity[i]);
        printf("Enter the profit of Item %d: ", i+1);
        scanf("%d", &profit[i]);
        ratio[i] = (float)profit[i] / (float)capacity[i]; 
        index[i] = i+1;
    }

    printf("\nEnter the maximum capacity of the knapsack: ");
    scanf("%f", &max_capacity);

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(ratio[i] < ratio[j]){
                float temp_ratio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp_ratio;

                int temp_capacity = capacity[i];
                capacity[i] = capacity[j];
                capacity[j] = temp_capacity;

                int temp_profit = profit[i];
                profit[i] = profit[j];
                profit[j] = temp_profit;

                int temp_index = index[i];
                index[i] = index[j];
                index[j] = temp_index;
            }
        }
    }

    i = 0;
    while(max_capacity > 0){
        if(capacity[i] < max_capacity){
            total_profit += profit[i];
            max_capacity -= capacity[i];
        }
        else{
            total_profit += ratio[i] * max_capacity;
            max_capacity = 0;
        }
        i++;
    }

    printf("\nItems selected based on highest ratio of profit to capacity:\n");
    for(i = 0; i < n; i++){
        if(capacity[i] <= max_capacity){
            printf("\nItem %d with capacity %d and $%d profit included in knapsack", index[i], capacity[i], profit[i]);
            max_capacity -= capacity[i];
            total_profit += profit[i];
        }
    }

    printf("\n\nTotal Profit: $%.2f", total_profit);

    return 0;
}