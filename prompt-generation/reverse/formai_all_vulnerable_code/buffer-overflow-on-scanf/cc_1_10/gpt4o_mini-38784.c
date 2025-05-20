//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int weight;
    float value;
    float value_per_weight; // value per unit weight
} Item;

// Function to compare items by value/weight ratio
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->value_per_weight < item2->value_per_weight) {
        return 1; // Sort in descending order
    }
    return -1;
}

// A function to calculate the maximum value of a knapsack
float knapsackGreedy(Item items[], int n, int capacity) {
    float total_value = 0.0; // Variable to hold total value of knapsack
    int current_weight = 0;  // Variable to keep track of current weight

    for (int i = 0; i < n; i++) {
        // If adding the whole item won't exceed the capacity, take it
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_value += items[i].value;
            printf("Taking whole item %d (Weight: %d, Value: %.2f)\n", 
                   items[i].id, items[i].weight, items[i].value);
        } else {
            // We can't take the whole item, take a fraction of it
            int remaining_capacity = capacity - current_weight;
            total_value += items[i].value_per_weight * remaining_capacity;
            printf("Taking %d of item %d (Weight: %d, Value: %.2f)\n", 
                   remaining_capacity, items[i].id, remaining_capacity, 
                   items[i].value_per_weight * remaining_capacity);
            break; // We can't take anything else now
        }
    }
    return total_value; // Return the maximum value
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item *items = (Item *)malloc(n * sizeof(Item)); // Dynamic allocation for items

    // Input item details
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1; // Assigning a unique ID to each item
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %f", &items[i].weight, &items[i].value);
        items[i].value_per_weight = items[i].value / items[i].weight; // Calculate value per weight
    }

    printf("Enter capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Sort items by value per weight in descending order
    qsort(items, n, sizeof(Item), compare);

    float max_value = knapsackGreedy(items, n, capacity);

    printf("Maximum value in the knapsack = %.2f\n", max_value);

    free(items); // Free allocated memory
    return 0;
}