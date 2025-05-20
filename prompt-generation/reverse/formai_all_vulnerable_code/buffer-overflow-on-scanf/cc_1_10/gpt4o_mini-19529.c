//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double weight;
    double value;
    double value_per_weight;
} Item;

// Comparator function for sorting items by value per weight in descending order
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->value_per_weight > item1->value_per_weight) - (item2->value_per_weight < item1->value_per_weight);
}

// Function to solve the fractional knapsack problem
double fractional_knapsack(Item items[], int n, double capacity) {
    // Sort items based on value per weight
    qsort(items, n, sizeof(Item), compare);

    double total_value = 0.0;

    // Iterate through sorted items
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) {
            break;
        }
        if (items[i].weight <= capacity) {
            // If the item can be fully taken
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            // Take the fraction of the item that fits
            total_value += items[i].value_per_weight * capacity; 
            capacity = 0; // Knapsack is now full
        }
    }
    return total_value;
}

int main() {
    int n;
    double capacity;

    // Taking input for number of items and capacity of knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item items[n];

    // Taking input for weight and value of each item
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter weight and value for item %d: ", items[i].id);
        scanf("%lf %lf", &items[i].weight, &items[i].value);
        
        // Calculate value per weight for each item
        items[i].value_per_weight = items[i].value / items[i].weight;
    }

    // Taking input for the capacity of knapsack
    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);

    // Calculate maximum value we can carry
    double max_value = fractional_knapsack(items, n, capacity);

    // Print the result
    printf("Maximum value in the knapsack = %.2lf\n", max_value);

    return 0;
}