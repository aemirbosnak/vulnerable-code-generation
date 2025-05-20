//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>

// Function prototype for the sorting algorithm
void sort(int n, float arr[], float values[], int index[]);

int main() {
    int n, i;
    float capacity; // Knapsack capacity
    float total_weight = 0, total_value = 0; // Total weight and total value of items in the knapsack
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    // Array to hold weights and values of the items
    float weights[n], values[n];
    
    // Array to hold the index of items after sorting
    int index[n];
    
    // Taking input of weights and values for each item
    printf("\nEnter weights and values for each item:\n");
    for (i = 0; i < n; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Weight: ");
        scanf("%f", &weights[i]);
        printf("Value: ");
        scanf("%f", &values[i]);
        
        // Initializing the index array
        index[i] = i;
    }
    
    // Taking input of the knapsack capacity
    printf("\nEnter the knapsack capacity: ");
    scanf("%f", &capacity);
    
    // Sorting the items in non-increasing order of their value/weight ratio
    sort(n, weights, values, index);
    
    printf("\nItems in the knapsack:\n");
    for (i = 0; i < n; i++) {
        if (total_weight + weights[index[i]] <= capacity) {
            printf("Item %d (Weight: %0.2f, Value: %0.2f) - added\n", index[i]+1, weights[index[i]], values[index[i]]);
            total_weight += weights[index[i]];
            total_value += values[index[i]];
        } else {
            printf("Item %d (Weight: %0.2f, Value: %0.2f) - not added\n", index[i]+1, weights[index[i]], values[index[i]]);
        }
    }
    
    // Outputting the total weight and total value of the items in the knapsack
    printf("\nTotal weight of the items in the knapsack: %0.2f\n", total_weight);
    printf("Total value of the items in the knapsack: %0.2f\n", total_value);
    
    return 0;
}

// Sorting algorithm for sorting the items in non-increasing order of their value/weight ratio
void sort(int n, float arr[], float values[], int index[]) {
    int i, j, max_index;
    float max_value;
    
    for (i = 0; i < n; i++) {
        max_index = i;
        max_value = values[i]/arr[i];
        
        for (j = i+1; j < n; j++) {
            if (values[j]/arr[j] > max_value) {
                max_index = j;
                max_value = values[j]/arr[j];
            }
        }
        
        // Swapping the elements
        float temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
        
        temp = values[i];
        values[i] = values[max_index];
        values[max_index] = temp;
        
        int temp_index = index[i];
        index[i] = index[max_index];
        index[max_index] = temp_index;
    }
}