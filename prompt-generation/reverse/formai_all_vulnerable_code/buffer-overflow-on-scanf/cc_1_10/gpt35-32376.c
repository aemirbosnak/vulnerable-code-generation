//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

void sort(int arr[], int n);

int main() {
    int n, capacity;
    int values[MAX_ITEMS];
    int weights[MAX_ITEMS];
    double ratios[MAX_ITEMS];
    double optimal_value;

    // get user input
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &values[i], &weights[i]);
        ratios[i] = (double) values[i] / weights[i];
    }

    // sort the items by decreasing value-to-weight ratio
    sort(ratios, n);

    // fill the knapsack with items until capacity is reached
    optimal_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (weights[i] <= capacity) {
            optimal_value += values[i];
            capacity -= weights[i];
        } else {
            optimal_value += capacity * ratios[i];
            break;
        }
    }

    printf("Optimal value: %lf\n", optimal_value);

    return 0;
}

void sort(int arr[], int n) {
    // insertion sort algorithm
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}