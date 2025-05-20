//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int value;
    int weight;
} Item;

// A function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    return (r1 > r2) ? -1 : 1; // Sort in descending order
}

// A greedy algorithm to solve the knapsack problem
void cyberKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); // Sort items by value/weight ratio

    int totalValue = 0;
    int totalWeight = 0;
    printf("Cybernetic Loot:\n\n");

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf(">>> Acquired %s (Value: %d, Weight: %d)\n", items[i].name, items[i].value, items[i].weight);
        } else {
            int remainingWeight = capacity - totalWeight;
            if (remainingWeight > 0) {
                double fraction = (double)remainingWeight / items[i].weight;
                totalValue += (int)(items[i].value * fraction);
                printf(">>> Acquired %s (Partial: %d%%)\n", items[i].name, (int)(fraction * 100));
            }
            break; // The capacity is reached
        }
    }
    printf("\nTotal Loot Value: %d\n", totalValue);
    printf("Total Weight Carried: %d\n", totalWeight);
}

int main() {
    int n;
    int capacity;
    Item items[MAX_ITEMS];

    printf(">>> Welcome to the Cyberpunk Loot Collector <<<\n");
    printf("Enter the number of items available: ");
    scanf("%d", &n);

    if (n > MAX_ITEMS) {
        printf("Exceeded max item limit!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name (alphanumeric characters only) of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter value of %s: ", items[i].name);
        scanf("%d", &items[i].value);
        printf("Enter weight of %s: ", items[i].name);
        scanf("%d", &items[i].weight);
    }

    printf("Enter the capacity of your cybernetic backpack: ");
    scanf("%d", &capacity);

    cyberKnapsack(items, n, capacity);
    return 0;
}