//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_ITEMS 100
#define MAX_CAPACITY 1000
#define INF 1000000

// Define structures
typedef struct {
    int id;
    int value;
    int weight;
} Item;

// Define helper functions
void read_items(Item items[], int n);
int knapSack(Item items[], int n, int capacity, int m[], int w[]);

// Define main function
int main() {
    int n, capacity;
    Item items[MAX_ITEMS];
    int m[MAX_CAPACITY + 1], w[MAX_CAPACITY + 1];

    // Read number of items and capacity
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Initialize m and w arrays with zeros
    for (int i = 0; i <= capacity; i++) {
        m[i] = 0;
        w[i] = 0;
    }

    // Read items and call knapsack function
    read_items(items, n);
    knapSack(items, n, capacity, m, w);

    // Print results in a happy style
    printf("\n---- HAPPY KNAPSACK SOLUTION ----\n");
    printf("Total value: %d\n", w[capacity]);
    printf("Items included:\n");
    for (int i = capacity; i >= 0; i--) {
        if (m[i] > 0) {
            printf("Item %d (weight: %d, value: %d)\n", items[i - 1].id, items[i - 1].weight, items[i - 1].value);
        }
    }

    return 0;
}

// Function to read items from standard input
void read_items(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter item %d weight and value: ", i + 1);
        scanf("%d%d", &items[i].weight, &items[i].value);
        items[i].id = i + 1;
    }
}

// Function to solve knapsack problem using greedy approach
int knapSack(Item items[], int n, int capacity, int m[], int w[]) {
    // Build m[] table as in bottom-up approach
    for (int i = 0; i <= capacity; i++) {
        for (int j = 0; j < n; j++) {
            if (items[j].weight <= i) {
                if (m[i] < m[i - items[j].weight] + items[j].value) {
                    m[i] = m[i - items[j].weight] + items[j].value;
                    w[i] = w[i - items[j].weight] + items[j].weight;
                }
            }
        }
    }

    return m[capacity];
}