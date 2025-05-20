//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to implement the greedy algorithm for the fractional knapsack problem
void greedy_knapsack(int num_items, int knap_cap, int *values, int *weights, int *selected_items) {
    // Initialize the selected items array
    for (int i = 0; i < num_items; i++) {
        selected_items[i] = 0;
    }

    // Sort the items by decreasing value-to-weight ratio
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (values[j] / weights[j] > values[i] / weights[i]) {
                int temp_value = values[i];
                int temp_weight = weights[i];
                values[i] = values[j];
                weights[i] = weights[j];
                values[j] = temp_value;
                weights[j] = temp_weight;
            }
        }
    }

    // Fill the knapsack with the highest value-to-weight ratio items
    int remaining_cap = knap_cap;
    for (int i = num_items - 1; i >= 0 && remaining_cap > 0; i--) {
        if (selected_items[i] == 0 && values[i] / weights[i] >= remaining_cap) {
            remaining_cap -= values[i] / weights[i];
            selected_items[i] = 1;
        }
    }

    // Print the selected items and the total value
    printf("Selected items: ");
    for (int i = 0; i < num_items; i++) {
        if (selected_items[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\nTotal value: %d\n", remaining_cap);
}

// Main function to test the greedy algorithm
int main() {
    int num_items, knap_cap;
    int *values, *weights, *selected_items;

    // Get the number of items and knapsack capacity from the user
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &knap_cap);

    // Allocate memory for the arrays
    values = (int *) malloc(num_items * sizeof(int));
    weights = (int *) malloc(num_items * sizeof(int));
    selected_items = (int *) malloc(num_items * sizeof(int));

    // Generate random values and weights for the items
    for (int i = 0; i < num_items; i++) {
        values[i] = rand_num(1, 100);
        weights[i] = rand_num(1, 10);
    }

    // Call the greedy algorithm function
    greedy_knapsack(num_items, knap_cap, values, weights, selected_items);

    // Free the allocated memory
    free(values);
    free(weights);
    free(selected_items);

    return 0;
}