//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include<stdio.h>

/* This program implements the Fractional Knapsack Problem using a greedy algorithm. */

#define MAX_SIZE 100

typedef struct{
    int value;
    int weight;
    float ratio;
} Item;

int compare(Item a, Item b) {
    return a.ratio < b.ratio;
}

int main() {
    int n, W;
    Item items[MAX_SIZE];
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    
    printf("Enter the value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    
    // sort the items in descending order of their ratio
    qsort(items, n, sizeof(Item), compare);
    
    int i = 0;
    float max_value = 0.0;
    
    while(W > 0 && i < n) {
        if(items[i].weight <= W) {
            // take the entire item as it can be accommodated in the knapsack
            max_value += items[i].value;
            W -= items[i].weight;
        } else {
            // take a fraction of the item that can fit in the knapsack
            max_value += W * items[i].ratio;
            W = 0;
        }
        i++;
    }
    
    printf("Maximum possible value that can be obtained = %0.2f\n", max_value);
    return 0;
}