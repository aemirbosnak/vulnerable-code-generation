//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum number of items
#define MAX_WEIGHT 1000 // Maximum total weight of items allowed
#define MAX_NAME_LEN 20 // Maximum length of item name

typedef struct item
{
    char name[MAX_NAME_LEN];
    int weight;
    int value;
} Item;

int cmpfunc(const void *a, const void *b)
{
    const Item *item1 = (const Item *)a;
    const Item *item2 = (const Item *)b;

    double ratio1 = (double)item1->value/item1->weight;
    double ratio2 = (double)item2->value/item2->weight;

    if(ratio1 < ratio2)
    {
        return 1;
    }
    else if(ratio1 > ratio2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void knapsack(Item *items, int num_items, int max_weight)
{
    int i, j = 0;
    int total_weight = 0, total_value = 0;
    double fraction;
    Item temp;

    // Sort the items in descending order of their value-to-weight ratio
    qsort(items, num_items, sizeof(Item), cmpfunc);

    printf("Items included in the knapsack:\n");

    // Add items to the knapsack until it is full
    for(i = 0; i < num_items && total_weight < max_weight; i++)
    {
        if(items[i].weight + total_weight <= max_weight)
        {
            printf("%s\n", items[i].name);
            total_weight += items[i].weight;
            total_value += items[i].value;
        }
        else
        {
            // Add a fraction of the item if it can't be added in its entirety
            fraction = (double)(max_weight - total_weight)/items[i].weight;
            strcpy(temp.name, items[i].name);
            temp.weight = max_weight - total_weight;
            temp.value = fraction * items[i].value;
            printf("%s (fraction)\n", temp.name);
            total_weight += temp.weight;
            total_value += temp.value;
        }
    }

    printf("\nTotal weight: %d\nTotal value: %d", total_weight, total_value);
}

void main()
{
    int num_items, max_weight, i;
    Item items[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &max_weight);

    printf("Enter the name, weight, and value of each item:\n");

    for(i = 0; i < num_items; i++)
    {
        printf("\nItem %d:\n", i+1);

        printf("Name: ");
        scanf("%s", items[i].name);

        printf("Weight: ");
        scanf("%d", &items[i].weight);

        printf("Value: ");
        scanf("%d", &items[i].value);
    }

    knapsack(items, num_items, max_weight);
}