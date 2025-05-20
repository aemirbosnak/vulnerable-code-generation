//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item with its weight and value
struct Item {
    int value;
    int weight;
};

// Comparison function for sorting items based on value-to-weight ratio
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r1 < r2) - (r1 > r2); // Returning -1, 0, or 1 for sorting
}

// Function to implement Greedy Knapsack
double greedyKnapsack(struct Item arr[], int n, int W) {
    // Sort the items based on value-to-weight ratio
    qsort(arr, n, sizeof(arr[0]), compare);

    double totalValue = 0.0; // Total value of the knapsack
    int currentWeight = 0;    // Current weight of the knapsack

    // Traverse the items
    for (int i = 0; i < n; i++) {
        // If adding the item exceeds the capacity, take the fraction
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight; // Update the current weight
            totalValue += arr[i].value;     // Add value to the total
            printf("Adding whole item: weight = %d, value = %d\n", arr[i].weight, arr[i].value);
        } else {
            // Take the fraction of the remaining weight
            int remainingWeight = W - currentWeight;
            totalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            printf("Adding fraction of item: weight = %d, value = %d\n", remainingWeight, (int)(arr[i].value * ((double)remainingWeight / arr[i].weight)));
            break; // No more capacity in the knapsack
        }
    }

    return totalValue; // Return the maximum value that can be carried
}

int main() {
    int n, W;

    printf("Surprise! Welcome to the Greedy Knapsack Problem Solver!\n");
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item* arr = (struct Item*)malloc(n * sizeof(struct Item));

    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);

    // Input the items' value and weight
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    // Calculate the maximum value
    double maxValue = greedyKnapsack(arr, n, W);
    printf("The maximum value that can be obtained is: %.2f\n", maxValue);

    // Cleanup
    free(arr);
    return 0;
}