//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 1000

typedef struct {
    int value;
    int weight;
} Item;

int compare_items(const void *a, const void *b) {
    Item *item1 = (Item *) a;
    Item *item2 = (Item *) b;

    double ratio1 = (double) item1->value / item1->weight;
    double ratio2 = (double) item2->value / item2->weight;

    if (ratio1 > ratio2) {
        return -1;
    } else if (ratio1 < ratio2) {
        return 1;
    } else {
        return 0;
    }
}

void print_items(Item *items, int n) {
    printf("Items:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] value: %d weight: %d\n", i, items[i].value, items[i].weight);
    }
}

// Greedy algorithm for fractional knapsack problem.
double knapsack_fractional(Item *items, int n, int capacity) {
    double total_value = 0.0;
    int current_weight = 0;

    qsort(items, n, sizeof(Item), compare_items);

    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_weight = capacity - current_weight;
            double fraction = (double) remaining_weight / items[i].weight;
            total_value += fraction * items[i].value;
            break;
        }
    }

    return total_value;
}

// Greedy algorithm for 0/1 knapsack problem.
int knapsack_zero_one(Item *items, int n, int capacity) {
    int **table = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        table[i] = malloc((capacity + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (items[i - 1].weight <= j) {
                table[i][j] = (items[i - 1].value + table[i - 1][j - items[i - 1].weight] > table[i - 1][j])
                                ? items[i - 1].value + table[i - 1][j - items[i - 1].weight] : table[i - 1][j];
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    int result = table[n][capacity];

    for (int i = 0; i <= n; i++) {
        free(table[i]);
    }
    free(table);

    return result;
}

int main() {
    Item items[MAX_ITEMS];
    int n, capacity, choice;

    printf("Enter number of items (1-%d): ", MAX_ITEMS);
    scanf("%d", &n);

    printf("Enter knapsack's capacity (1-%d): ", MAX_WEIGHT);
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter item value and weight: ");
        scanf("%d %d",&items[i].value,&items[i].weight);
    }

    printf("Enter 1 for Fractional Knapsack or 2 for 0/1 Knapsack: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            double result = knapsack_fractional(items, n, capacity);
            printf("Maximum value of items that can be added to the knapsack: $%.2f\n", result);
            break;
        }
        case 2: {
            int result = knapsack_zero_one(items, n, capacity);
            printf("Maximum value of items that can be added to the knapsack: $%d\n", result);
            break;
        }
        default: {
            printf("Invalid choice. Please enter 1 or 2.\n");
            break;
        }
    }

    return 0;
}