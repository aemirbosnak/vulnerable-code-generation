//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_VALUE 1000

// Data structure for the items
typedef struct {
    int value;
    int weight;
} item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    const item *ia = (const item *)a;
    const item *ib = (const item *)b;
    return (ia->value * MAX_VALUE) / ia->weight - (ib->value * MAX_VALUE) / ib->weight;
}

// Function to print the selected items and their total value
void print_solution(item *selected, int n) {
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        printf("%d (%d)\n", selected[i].value, selected[i].weight);
    }
    printf("Total value: %d\n", selected[n - 1].value);
}

// Main function to run the greedy algorithm
int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Read in the items
    item *items = (item *)malloc(n * sizeof(item));
    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Sort the items by their value-to-weight ratio
    qsort(items, n, sizeof(item), compare);

    // Initialize the selected items list
    item *selected = (item *)malloc((n + 1) * sizeof(item));
    selected[0].value = 0;
    selected[0].weight = 0;

    // Run the greedy algorithm
    for (int i = 1; i <= n; i++) {
        if (selected[i - 1].weight + items[i - 1].weight <= MAX_SIZE) {
            selected[i].value = selected[i - 1].value + items[i - 1].value;
            selected[i].weight = selected[i - 1].weight + items[i - 1].weight;
        } else {
            selected[i].value = items[i - 1].value;
            selected[i].weight = items[i - 1].weight;
        }
    }

    // Print the solution
    print_solution(selected, n);

    // Free the memory
    free(items);
    free(selected);

    return 0;
}