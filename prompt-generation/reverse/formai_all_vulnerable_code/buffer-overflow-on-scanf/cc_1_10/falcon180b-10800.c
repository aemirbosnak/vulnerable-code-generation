//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 10
#define MAX_VALUES 10

// Function to find the maximum value using greedy algorithm
int findMaxValue(int values[], int weights[], int capacity) {
    int n = sizeof(values) / sizeof(values[0]);
    int i, j;
    for (i = 0; i < n; i++) {
        int max_value_index = i;
        for (j = i + 1; j < n; j++) {
            if (values[j] > values[max_value_index]) {
                max_value_index = j;
            }
        }
        int temp_value = values[i];
        values[i] = values[max_value_index];
        values[max_value_index] = temp_value;
    }
    return values[0];
}

// Function to find the maximum number of coins using greedy algorithm
int findMaxCoins(int values[], int weights[], int capacity) {
    int n = sizeof(values) / sizeof(values[0]);
    int i, j;
    for (i = 0; i < n; i++) {
        int max_value_index = i;
        for (j = i + 1; j < n; j++) {
            if (values[j] > values[max_value_index]) {
                max_value_index = j;
            }
        }
        int temp_value = values[i];
        values[i] = values[max_value_index];
        values[max_value_index] = temp_value;
    }
    int max_coins = 0;
    for (i = n - 1; i >= 0; i--) {
        if (weights[i] <= capacity) {
            capacity -= weights[i];
            max_coins++;
        }
    }
    return max_coins;
}

int main() {
    int values[MAX_VALUES], weights[MAX_VALUES];
    int capacity, i;
    printf("Enter the number of items: ");
    scanf("%d", &capacity);
    printf("Enter the values and weights of the items:\n");
    for (i = 0; i < capacity; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }
    int max_value = findMaxValue(values, weights, capacity);
    printf("The maximum value is: %d\n", max_value);
    int max_coins = findMaxCoins(values, weights, capacity);
    printf("The maximum number of coins is: %d\n", max_coins);
    return 0;
}