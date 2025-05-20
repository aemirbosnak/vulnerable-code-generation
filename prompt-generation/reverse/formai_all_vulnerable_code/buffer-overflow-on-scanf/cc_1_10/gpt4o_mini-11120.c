//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

// Comparison function for sorting items by value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratioA = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratioB = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}

// Function to solve the 0/1 Knapsack problem using a greedy approach
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Sort items by their value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0; // Variable to store the total value accumulated
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If the entire item can be added, add its value
            totalValue += items[i].value;
            capacity -= items[i].weight; // Reduce remaining capacity
        } else {
            // If the item can't be added in full, add the fractional part
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; // Knapsack is full after adding the fractional item
        }
    }
    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Maximum weight capacity of knapsack

    // User inputs for number of items and capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of items. Please enter a positive number.\n");
        return 1;
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &capacity);
    if (capacity <= 0) {
        printf("Invalid capacity. Please enter a positive number.\n");
        return 1;
    }

    struct Item *items = malloc(n * sizeof(struct Item)); // Dynamically allocate memory for items
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // User inputs values and weights of items
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        if (items[i].weight <= 0) {
            printf("Invalid weight for item %d. Weight must be positive.\n", i + 1);
            free(items);
            return 1;
        }
    }

    // Calculate the maximum value for the knapsack
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    // Free allocated memory
    free(items);
    return 0;
}