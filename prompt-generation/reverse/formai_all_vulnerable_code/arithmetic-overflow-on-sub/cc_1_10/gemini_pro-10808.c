//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of items
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct {
    int value;  // The value of the item
    int weight; // The weight of the item
} item_t;

// Define the knapsack problem
typedef struct {
    int capacity;  // The capacity of the knapsack
    item_t *items; // The items to be added to the knapsack
    int num_items; // The number of items to be added to the knapsack
} knapsack_problem_t;

// Sort the items in decreasing order of value per weight
void sort_items(item_t *items, int num_items) {
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if ((double)items[i].value / items[i].weight < (double)items[j].value / items[j].weight) {
                item_t temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Solve the knapsack problem using the greedy algorithm
int solve_knapsack(knapsack_problem_t *knapsack) {
    // Sort the items in decreasing order of value per weight
    sort_items(knapsack->items, knapsack->num_items);

    // Initialize the total value of the items in the knapsack
    int total_value = 0;

    // Iterate over the items
    for (int i = 0; i < knapsack->num_items; i++) {
        // If the item can fit in the knapsack, add it to the knapsack
        if (knapsack->capacity >= knapsack->items[i].weight) {
            total_value += knapsack->items[i].value;
            knapsack->capacity -= knapsack->items[i].weight;
        }
        // Otherwise, break out of the loop
        else {
            break;
        }
    }

    // Return the total value of the items in the knapsack
    return total_value;
}

// Print the solution to the knapsack problem
void print_solution(knapsack_problem_t *knapsack, int total_value) {
    printf("The total value of the items in the knapsack is %d.\n", total_value);
    printf("The items in the knapsack are:\n");
    for (int i = 0; i < knapsack->num_items; i++) {
        if (knapsack->items[i].weight <= knapsack->capacity) {
            printf("Item %d: value = %d, weight = %d\n", i + 1, knapsack->items[i].value, knapsack->items[i].weight);
        }
    }
}

// Read the knapsack problem from a file
knapsack_problem_t *read_knapsack_problem(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        return NULL;
    }

    // Read the capacity of the knapsack
    int capacity;
    fscanf(file, "%d", &capacity);

    // Read the number of items
    int num_items;
    fscanf(file, "%d", &num_items);

    // Allocate memory for the items
    item_t *items = malloc(sizeof(item_t) * num_items);
    if (items == NULL) {
        printf("Could not allocate memory for items.\n");
        return NULL;
    }

    // Read the items
    for (int i = 0; i < num_items; i++) {
        fscanf(file, "%d %d", &items[i].value, &items[i].weight);
    }

    // Close the file
    fclose(file);

    // Create the knapsack problem
    knapsack_problem_t *knapsack = malloc(sizeof(knapsack_problem_t));
    if (knapsack == NULL) {
        printf("Could not allocate memory for knapsack.\n");
        return NULL;
    }

    knapsack->capacity = capacity;
    knapsack->items = items;
    knapsack->num_items = num_items;

    // Return the knapsack problem
    return knapsack;
}

// Free the memory allocated for the knapsack problem
void free_knapsack_problem(knapsack_problem_t *knapsack) {
    // Free the memory allocated for the items
    free(knapsack->items);

    // Free the memory allocated for the knapsack
    free(knapsack);
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the knapsack problem from the file
    knapsack_problem_t *knapsack = read_knapsack_problem(argv[1]);
    if (knapsack == NULL) {
        return 1;
    }

    // Solve the knapsack problem using the greedy algorithm
    int total_value = solve_knapsack(knapsack);

    // Print the solution to the knapsack problem
    print_solution(knapsack, total_value);

    // Free the memory allocated for the knapsack problem
    free_knapsack_problem(knapsack);

    // Return 0 to indicate success
    return 0;
}