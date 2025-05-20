//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int knapsack[MAX][2];
int max_weight = 0;
int item_count = 0;

int compare(const void *a, const void *b) {
    int *ia = (int *) a;
    int *ib = (int *) b;
    return (*ib) - (*ia);
}

void input_data() {
    int i;
    printf("Please enter the maximum weight the knapsack can hold => ");
    scanf("%d", &max_weight);
    printf("Please enter the number of items to be placed in the knapsack => ");
    scanf("%d", &item_count);
    printf("Please enter the value and weight of each item =>\n");
    for (i = 0; i < item_count; i++) {
        printf("(Item %d) Value: ", (i + 1));
        scanf("%d", &knapsack[i][0]);
        printf("(Item %d) Weight: ", (i + 1));
        scanf("%d", &knapsack[i][1]);
        printf("\n");
    }
}

void display_data() {
    int i;
    printf("The items the knapsack can contain are:\n\n");
    for (i = 0; i < item_count; i++) {
        printf("Item %d => Value: %d, Weight: %d\n", i + 1, knapsack[i][0], knapsack[i][1]);
    }
    printf("\nThe maximum weight the knapsack can hold: %d\n\n", max_weight);
}

void sort_items() {
    qsort(knapsack, item_count, sizeof(knapsack[0]), compare);
}

void knapsack_algorithm() {
    int i, weight = 0, value = 0;
    float fraction = 0.0;
    for (i = 0; i < item_count; i++) {
        if (weight + knapsack[i][1] <= max_weight) {
            weight = weight + knapsack[i][1];
            value = value + knapsack[i][0];
        } else {
            fraction = (float)(max_weight - weight) / (float)knapsack[i][1];
            value = value + (int)(fraction * knapsack[i][0]);
            break;
        }
    }
    printf("The maximum value obtainable is: %d\n", value);
}

int main() {
    printf("+++++ Knapsack Problem - Greedy Algorithm +++++\n\n");
    input_data();
    display_data();
    sort_items();
    knapsack_algorithm();
    return 0;
}