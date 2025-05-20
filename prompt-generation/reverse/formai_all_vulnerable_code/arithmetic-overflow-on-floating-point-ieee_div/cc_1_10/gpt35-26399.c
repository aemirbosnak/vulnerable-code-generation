//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 10

typedef struct{
    int weight;
    int profit;
    float weight_per_unit;
}item;

int cmpfunc(const void * a, const void * b){
    item *ia = (item *)a;
    item *ib = (item *)b;
    return (int)(ib->weight_per_unit - ia->weight_per_unit);
}

void knapsack_greedy(item items[], int n, int W){
    qsort(items, n, sizeof(items[0]), cmpfunc);

    int i = 0;
    float profit = 0;

    while(W > 0 && i < n){
        if(items[i].weight <= W){
            W -= items[i].weight;
            profit += items[i].profit;
            i++;
        }
        else{
            float fraction = (float)W / (float)items[i].weight;
            W = 0;
            profit += (fraction * items[i].profit);
            i++;
        }
    }

    printf("The maximum profit obtained with the knapsack is: %.2f\n", profit);
}

int main(){
    item items[MAX_ITEMS];
    int W;
    int n, i;

    printf("Enter the total number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the weight and profit for each item:\n");
    for(i = 0; i < n; i++){
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].weight_per_unit = (float)items[i].profit / (float)items[i].weight;  
    }

    knapsack_greedy(items, n, W);

    return 0;
}