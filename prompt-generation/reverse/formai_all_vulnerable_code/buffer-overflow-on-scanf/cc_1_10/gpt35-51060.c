//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>

#define MAX 1000

int n, weight[MAX], value[MAX];

void knapsack(int capacity){

    int i, j, profit = 0, ratios[MAX];
    float temp;

    // calculate the ratio of value to weight for each item
    for(i = 0; i < n; i++){
        ratios[i] = value[i]/weight[i];
    }

    // sort the items based on their ratios in descending order
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(ratios[i] < ratios[j]){
                temp = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
            }
        }
    }

    // fill the knapsack with items in descending order of their ratios
    for(i = 0; i < n; i++){
        if(weight[i] <= capacity){
            capacity -= weight[i];
            profit += value[i];
        }
        else{
            // take a fraction of the remaining item
            profit += capacity * ratios[i];
            break;
        }
    }

    printf("Maximum profit = %d", profit);
}

int main(){

    int i, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for(i = 0; i < n; i++){
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(capacity);

    return 0;
}