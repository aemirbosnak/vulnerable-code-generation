//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>

struct item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct item *itemA = (struct item *)a;
    struct item *itemB = (struct item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return (ratioB > ratioA) ? 1 : -1;
}

double fractional_knapsack(struct item items[], int n, int W) {
    qsort(items, n, sizeof(struct item), compare);
    double result = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            result += items[i].value;
        }
        else {
            double fraction = (double)W / items[i].weight;
            result += items[i].value * fraction;
            W = 0;
            break;
        }
    }
    return result;
}

int main() {
    int W, n, i;
    struct item items[100];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight limit of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the values and weights of %d items:\n", n);
    for (i = 0; i < n; i++) {
        printf("Item %d value: ", i+1);
        scanf("%d", &items[i].value);
        printf("Item %d weight: ", i+1);
        scanf("%d", &items[i].weight);
    }

    double max_value = fractional_knapsack(items, n, W);

    printf("Maximum value in the knapsack = %0.2lf", max_value);

    return 0;
}