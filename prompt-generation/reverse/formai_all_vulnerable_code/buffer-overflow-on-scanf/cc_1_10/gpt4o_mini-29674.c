//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio; // Value to weight ratio
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}

void greedyKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    int totalValue = 0;
    int remainingCapacity = capacity;

    printf("Items taken in the knapsack:\n");
    for (int i = 0; i < n; i++) {
        if (remainingCapacity >= items[i].weight) {
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Weight = %d, Value = %d (Fully taken)\n", i + 1, items[i].weight, items[i].value);
        } else {
            float fraction = (float)remainingCapacity / items[i].weight;
            totalValue += (int)(items[i].value * fraction);
            printf("Item %d: Weight = %d, Value = %d (Fraction taken: %.2f)\n", i + 1, items[i].weight, items[i].value, fraction);
            break; // Since we can't add entire item, we are done
        }
    }
    printf("Total value of knapsack: %d\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Welcome to the Greedy Knapsack Solver! 🎉\n");
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    printf("Now, enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &(items[i].weight));
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &(items[i].value));
        
        if (items[i].weight != 0) {
            items[i].ratio = (float)items[i].value / items[i].weight; 
        } else {
            items[i].ratio = 0; // Avoid division by zero for weight 0
        }
    }

    printf("Calculating maximal value possible in the knapsack...\n");
    greedyKnapsack(capacity, items, n);

    free(items); // Release allocated memory
    printf("Thank you for using the Greedy Knapsack Solver! Goodbye! 👋\n");

    return 0;
}