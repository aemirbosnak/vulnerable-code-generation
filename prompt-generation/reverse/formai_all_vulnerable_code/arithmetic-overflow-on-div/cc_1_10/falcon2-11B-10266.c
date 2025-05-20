//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the weight and value of each item
int weight[] = {2, 3, 4, 5, 6};
int value[] = {3, 6, 9, 12, 15};

// Define the maximum capacity of the knapsack
int capacity = 10;

// Function to calculate the maximum value that can be obtained using the greedy algorithm
int greedy(int capacity, int n, int *weight, int *value) {
    int max_value = 0;
    int i;

    // Sort the items in decreasing order of their values per weight ratio
    for (i = 0; i < n; i++) {
        int j;
        for (j = i + 1; j < n; j++) {
            if (value[j] / weight[j] > value[i] / weight[i]) {
                int temp = value[j] / weight[j];
                value[j] = value[i] / weight[i];
                value[i] = temp;
                int temp2 = weight[j];
                weight[j] = weight[i];
                weight[i] = temp2;
            }
        }
    }

    // Calculate the maximum value that can be obtained using the greedy algorithm
    for (i = 0; i < n; i++) {
        if (capacity - weight[i] >= 0) {
            capacity -= weight[i];
            max_value += value[i];
        } else {
            break;
        }
    }

    return max_value;
}

// Function to print the maximum value obtained using the greedy algorithm
void print_max_value(int capacity, int n, int *weight, int *value) {
    int max_value = 0;
    int i;

    // Sort the items in decreasing order of their values per weight ratio
    for (i = 0; i < n; i++) {
        int j;
        for (j = i + 1; j < n; j++) {
            if (value[j] / weight[j] > value[i] / weight[i]) {
                int temp = value[j] / weight[j];
                value[j] = value[i] / weight[i];
                value[i] = temp;
                int temp2 = weight[j];
                weight[j] = weight[i];
                weight[i] = temp2;
            }
        }
    }

    // Calculate the maximum value that can be obtained using the greedy algorithm
    for (i = 0; i < n; i++) {
        if (capacity - weight[i] >= 0) {
            capacity -= weight[i];
            max_value += value[i];
        } else {
            break;
        }
    }

    // Print the maximum value obtained using the greedy algorithm
    printf("Maximum value obtained using greedy algorithm: %d\n", max_value);
}

int main() {
    int capacity = 10;
    int n = 5;
    int *weight = weight;
    int *value = value;

    // Calculate the maximum value that can be obtained using the greedy algorithm
    int max_value = greedy(capacity, n, weight, value);

    // Print the maximum value obtained using the greedy algorithm
    print_max_value(capacity, n, weight, value);

    return 0;
}