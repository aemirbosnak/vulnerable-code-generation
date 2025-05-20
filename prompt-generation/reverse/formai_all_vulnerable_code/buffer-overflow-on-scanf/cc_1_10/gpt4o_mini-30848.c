//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

// Function to compare items based on value to weight ratio
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    
    // Sort in descending order
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

// Function to perform the greedy algorithm for the knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;

    for(int i = 0; i < n; i++) {
        if (capacity <= 0) break;

        if (items[i].weight <= capacity) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take the fractional part of the item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0; // Knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n;
    int capacity;

    printf("Welcome to the Greedy Knapsack Program! 🎉\n");
    printf("==========================================================\n");
    
    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    // Input weight and value of each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }

    // Input capacity of knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Calculate the maximum value that can be carried
    double max_value = fractionalKnapsack(capacity, items, n);
    
    // Display the result
    printf("The maximum value that can be achieved is: %.2f 💰\n", max_value);
    
    // Free allocated memory
    free(items);
    
    printf("Thank you for using the Greedy Knapsack Program! 🥳\n");
    return 0;
}