//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>

#define MAX_ITEMS 100  // maximum number of items in the knapsack
#define MAX_WEIGHT 1000  // maximum weight capacity of the knapsack

struct item
{
    int value;  // value of the item
    int weight;  // weight of the item
};

// function prototypes
int compare_items(const void *item1, const void *item2);
void knapsack(struct item *items, int num_items, int knapsack_weight);

int main()
{
    struct item items[MAX_ITEMS];
    int num_items, knapsack_weight, i;

    // get number of items and weight capacity from user
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter knapsack weight capacity: ");
    scanf("%d", &knapsack_weight);

    // get item values and weights from user
    printf("Enter item values and weights:\n");
    for (i = 0; i < num_items; i++) {
        printf("Item %d value: ", i+1);
        scanf("%d", &items[i].value);
        printf("Item %d weight: ", i+1);
        scanf("%d", &items[i].weight);
    }

    // sort items in descending order of value/weight ratio
    qsort(items, num_items, sizeof(struct item), compare_items);

    // solve the knapsack problem
    knapsack(items, num_items, knapsack_weight);

    return 0;
}

// function to compare items based on value/weight ratio
int compare_items(const void *item1, const void *item2)
{
    const struct item *i1 = item1;
    const struct item *i2 = item2;
    double ratio1 = (double)i1->value / i1->weight;
    double ratio2 = (double)i2->value / i2->weight;
    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

// function to solve the knapsack problem
void knapsack(struct item *items, int num_items, int knapsack_weight)
{
    int i;
    double total_value = 0.0;
    int total_weight = 0;
    printf("\nSelected items:\n");
    for (i = 0; i < num_items; i++) {
        if (total_weight + items[i].weight <= knapsack_weight) {
            total_value += items[i].value;
            total_weight += items[i].weight;
            printf("Item %d (value=%d, weight=%d)\n", i+1, items[i].value, items[i].weight);
        } else {
            break;
        }
    }
    printf("Total value: %.2f\n", total_value);
    printf("Total weight: %d\n", total_weight);
}