//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items
#define MAX_ITEMS 10

// Define the maximum weight of knapsack
#define MAX_WEIGHT 100

// Define the item structure
struct Item {
    int value;
    int weight;
};

// Function to sort items in non-increasing order
void sortItems(struct Item items[MAX_ITEMS], int n) {
    int i, j;
    struct Item temp;
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if((double)items[i].value/items[i].weight < (double)items[j].value/items[j].weight) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Function to solve the 0/1 Knapsack problem using Greedy Algorithm
int knapsackGreedy(struct Item items[MAX_ITEMS], int n, int maxWeight) {
    int i, curWeight = 0, totalValue = 0;
    for(i=0;i<n;i++) {
        if(curWeight + items[i].weight <= maxWeight) {
            curWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else {
            int remainingWeight = maxWeight - curWeight;
            totalValue += (double)remainingWeight/items[i].weight * items[i].value;
            break;
        }
    }
    return totalValue;
}

// Main function
int main() {
    int n, i, maxWeight;
    struct Item items[MAX_ITEMS];
    
    // Read input values
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight of knapsack: ");
    scanf("%d", &maxWeight);
    printf("Enter the item weights and values:\n");
    for(i=0;i<n;i++) {
        scanf("%d%d", &items[i].weight, &items[i].value);
    }

    // Sort the items in non-increasing order
    sortItems(items, n);

    // Solve the knapsack problem using Greedy Algorithm
    int totalValue = knapsackGreedy(items, n, maxWeight);

    // Print the solution
    printf("Maximum value of items in the knapsack = %d\n", totalValue);

    return 0;
}