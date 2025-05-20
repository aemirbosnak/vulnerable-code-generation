//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Item structure to hold an item and its value/weight
struct Item {
    int value;
    int weight;
};

// Function to compare two items based on their value-to-weight ratio
int cmp(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 > r2) ? -1 : (r1 < r2) ? 1 : 0;
}

// Greedy function to solve the fractional knapsack problem
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sorting items by value-to-weight ratio
    qsort(arr, n, sizeof(arr[0]), cmp);

    double totalValue = 0.0; // To store maximum value

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            // If item can be fully accommodated
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // If item cannot be fully accommodated
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break; // Knapsack is full
        }
    }

    return totalValue; // Return the maximum value achieved
}

int main() {
    int n, W;

    // Read number of items and capacity of knapsack
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter maximum weight of the knapsack: ");
    scanf("%d", &W);

    struct Item *arr = (struct Item *)malloc(n * sizeof(struct Item));

    // Read values and weights of each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    // Call to the fractional knapsack function
    double maxValue = fractionalKnapsack(W, arr, n);

    // Display the result
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    // Free dynamically allocated memory
    free(arr);
    return 0;
}