//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include<stdio.h>

// Defining structure for items
struct Item {
    int value;
    int weight;
};

// Bubble sort to sort the items array based on value/weight ratio
void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if((items[j].value)/(items[j].weight) < (items[j+1].value)/(items[j+1].weight)) {
                temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

// Function to calculate maximum value of items that can be put in a sack of capacity W
int knapsack(struct Item items[], int n, int W) {
    int i, w;
    float ratio, value=0;
    sortItems(items, n); // Sorting items based on value/weight ratio in descending order
    
    for(i=0; i<n; i++) {
        if(W == 0) // Sack is full, break the loop
            break;
        w = (W < items[i].weight) ? W : items[i].weight; // Take the minimum of weight of current item and remaining sack capacity
        ratio = (float) items[i].value / items[i].weight; 
        value += ratio*w;
        W -= w;
    }
    return value;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for(int i=0; i<n; i++) {
        printf("Item %d -\n", i+1);
        printf("Value: ");
        scanf("%d", &items[i].value);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    int max_value = knapsack(items, n, W);
    printf("Maximum value of items that can be put in the knapsack of capacity %d is: %d", W, max_value);
    
    return 0;
}