//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
// This program demonstrates the concept of Greedy Algorithms
// It takes in user input as array of weights and profits of different items
// Then it calculates the maximum profit that can be obtained by selecting items and their respective weights
// within a given capacity of knapsack

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Structure to store weight and profit of items
struct item {
    int weight;
    int profit;
};

// Function to compare items by their profits per unit weight
int compare(const void* a, const void* b) {
    struct item* item1 = (struct item*)a;
    struct item* item2 = (struct item*)b;
    double ratio1 = (double)item1->profit / item1->weight;
    double ratio2 = (double)item2->profit / item2->weight;
    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    else
        return 0;
}

// Function to calculate maximum profit for given capacity
double getMaximumProfit(struct item items[], int n, int capacity) {
    // Sort items by profits per unit weight in non-increasing order
    qsort(items, n, sizeof(struct item), compare);
    
    double currentWeight = 0;
    double currentProfit = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If current item can be added completely, add it
            currentWeight += items[i].weight;
            currentProfit += items[i].profit;
        }
        else {
            // If current item cannot be added completely, add its fraction
            int remainCapacity = capacity - currentWeight;
            currentProfit += items[i].profit * ((double)remainCapacity / items[i].weight);
            break;
        }
    }
    return currentProfit;
}

int main() {
    struct item items[MAX];
    int n, capacity, i;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    // Take input of weight and profit of each item
    for (i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
    
    // Calculate and print maximum profit
    printf("Maximum profit: $%.2f\n", getMaximumProfit(items, n, capacity));
    
    return 0;
}