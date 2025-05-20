//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int num_items, capacity, total_weight = 0;
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    int values[num_items], weights[num_items], selected_items[num_items];

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    for(int i=0; i<num_items; i++) {
        printf("Enter value and weight of item %d: ", i+1);
        scanf("%d %d", &values[i], &weights[i]);
        selected_items[i] = 0;
    }

    // Sort items by their value-to-weight ratio in descending order
    float value_per_weight[num_items];
    for(int i=0; i<num_items; i++) {
        value_per_weight[i] = (float)values[i]/weights[i];
    }

    qsort(value_per_weight, num_items, sizeof(float), compare);

    // Select items greedily to fill knapsack
    int i = num_items - 1;
    while(capacity > 0 && i >= 0) {
        int max_index = -1;
        float max_value_per_weight = -1;
        for(int j=0; j<num_items; j++) {
            if(!selected_items[j] && value_per_weight[i] == (float)values[j]/weights[j]) {
                if(weights[j] <= capacity && value_per_weight[i] > max_value_per_weight) {
                    max_value_per_weight = value_per_weight[i];
                    max_index = j;
                }
            }
        }
        if(max_index != -1) {
            selected_items[max_index] = 1;
            capacity -= weights[max_index];
            total_weight += weights[max_index];
        }
        i--;
    }

    printf("Items selected:\n");
    for(int i=0; i<num_items; i++) {
        if(selected_items[i]) {
            printf("Item %d\n", i+1);
        }
    }

    printf("Total weight: %d\n", total_weight);

    return 0;
}