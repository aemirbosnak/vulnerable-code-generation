//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);
    int weight[n], value[n];
    for(int i = 0; i < n; i++) {
        printf("Enter weight of item %d: ", i+1);
        scanf("%d", &weight[i]);
        printf("Enter value of item %d: ", i+1);
        scanf("%d", &value[i]);
    }
    int order[n], index[n];
    for(int i = 0; i < n; i++)
        order[i] = value[i]/weight[i];
    for(int i = 0; i < n; i++) {
        int max = 0;
        for(int j = 0; j < n; j++) {
            if(order[j] > order[max])
                max = j;
        }
        order[max] = -1;
        index[i] = max;
    }
    int selected[n];
    for(int i = 0; i < n; i++)
        selected[i] = 0;
    int total_value = 0, total_weight = 0;
    for(int i = 0; i < n; i++) {
        int k = index[i];
        if((float)total_weight + weight[k] <= m) {
            selected[k] = 1;
            total_weight += weight[k];
            total_value += value[k];
        }
        else
            break;
    }
    printf("Selected Items:\n");
    for(int i = 0; i < n; i++) {
        if(selected[i])
            printf("Item %d with value %d and weight %d\n", i+1, value[i], weight[i]);
    }
    printf("Total value of selected items: %d\n", total_value);
    printf("Total weight of selected items: %d\n", total_weight);

    return 0;
}