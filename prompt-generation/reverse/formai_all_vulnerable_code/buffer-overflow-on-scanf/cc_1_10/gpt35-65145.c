//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 // Maximum number of items
#define MAX_WEIGHT 100 // Maximum weight of an item

// Structure representing an item
typedef struct {
    int value;
    int weight;
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void* p1, const void* p2) {
    Item* item1 = (Item*) p1;
    Item* item2 = (Item*) p2;
    double ratio1 = ((double) item1->value) / item1->weight;
    double ratio2 = ((double) item2->value) / item2->weight;
    return ratio2 > ratio1 ? 1 : (ratio2 < ratio1 ? -1 : 0);
}

// Function to perform the fractional knapsack algorithm
double fractional_knapsack(Item items[], int n, int W) {
    qsort(items, n, sizeof(Item), compare); // Sort items based on their value-to-weight ratio
    int current_weight = 0;
    double total_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= W) { // Pick the whole item if it fits
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else { // Otherwise, pick a fraction of the item
            int remaining_weight = W - current_weight;
            double fraction = ((double) remaining_weight) / items[i].weight;
            total_value += fraction * items[i].value;
            break;
        }
    }
    return total_value;
}

int main() {
    int n, W; // Number of items and maximum weight of the knapsack
    Item items[MAX_ITEMS];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item #%d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    double result = fractional_knapsack(items, n, W);
    printf("The maximum value that can be obtained is %.2lf.\n", result);
    return 0;
}