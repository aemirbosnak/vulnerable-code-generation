//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int num_items, i, j, max_value, current_value;
    int *values = NULL, *selected = NULL;
    char input[MAX_SIZE];
    
    // Read the number of items
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    
    // Allocate memory for the values array
    values = (int *) malloc(num_items * sizeof(int));
    if (values == NULL) {
        printf("Error: could not allocate memory.\n");
        return 1;
    }
    
    // Read the values
    for (i = 0; i < num_items; i++) {
        printf("Enter the value for item %d: ", i+1);
        scanf("%d", &values[i]);
    }
    
    // Allocate memory for the selected array
    selected = (int *) malloc(num_items * sizeof(int));
    if (selected == NULL) {
        printf("Error: could not allocate memory.\n");
        return 1;
    }
    
    // Initialize the selected array
    for (i = 0; i < num_items; i++) {
        selected[i] = 0;
    }
    
    // Initialize the maximum value
    max_value = values[0];
    
    // Find the maximum value
    for (i = 1; i < num_items; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }
    
    // Initialize the current value
    current_value = max_value;
    
    // Select the items
    for (i = 0; i < num_items; i++) {
        if (values[i] == max_value) {
            selected[i] = 1;
            current_value -= values[i];
        }
    }
    
    // Print the selected items
    for (i = 0; i < num_items; i++) {
        if (selected[i] == 1) {
            printf("Item %d selected.\n", i+1);
        }
    }
    
    // Free the memory
    free(values);
    free(selected);
    
    return 0;
}