//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int n, i, j, max_profit = 0, current_profit = 0;
    int weight[MAX_SIZE], value[MAX_SIZE], capacity = 50;
    int selected_items[MAX_SIZE];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the weight and value of each item
    for (i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    // Sort items in decreasing order of value/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((double)value[j] / weight[j] > (double)value[i] / weight[i]) {
                int temp = i;
                i = j;
                j = temp;
            }
        }
    }

    // Apply greedy algorithm to maximize profit
    for (i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            selected_items[i] = 1;
            capacity -= weight[i];
            current_profit += value[i];
        } else if (capacity < weight[i]) {
            int max_value_index = -1;
            int max_value = 0;

            for (j = 0; j < i; j++) {
                if (selected_items[j] == 1 && ((double)value[j] / weight[j]) > max_value) {
                    max_value = (double)value[j] / weight[j];
                    max_value_index = j;
                }
            }

            if (max_value_index!= -1) {
                selected_items[max_value_index] = 0;
                capacity += weight[max_value_index];
                current_profit -= value[max_value_index];
            }
        }
    }

    printf("Selected items: ");
    for (i = 0; i < n; i++) {
        if (selected_items[i] == 1) {
            printf("%d ", i + 1);
        }
    }

    printf("\nMaximum profit: %d", max_profit);

    return 0;
}