//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50
#define MYSTICAL_WIND 1000000

typedef struct {
    int value;
    int weight;
} Item;

int compare(const void *a, const void *b) {
    double ratio_a = (double)((Item*)a)->value / ((Item*)a)->weight;
    double ratio_b = (double)((Item*)b)->value / ((Item*)b)->weight;
    return (ratio_b < ratio_a) - (ratio_b > ratio_a);
}

void surrealGreedyBag(Item items[], int n, int mysticalWeight) {
    qsort(items, n, sizeof(Item), compare);
    
    int currentWeight = 0;
    double totalValue = 0.0;
    int spirits = 0;

    printf("In the realm where logic entwines with the chaotic dance of dreams...\n");
    printf("With a mystical weight of %d, we embark on an odyssey of greed.\n\n", mysticalWeight);

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= mysticalWeight) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            spirits++;
            printf("Whispering to the winds, we take item %d with weight %d and value %d...\n",
                   i, items[i].weight, items[i].value);
        } else {
            printf("The shadows of desperation creep as item %d with weight %d cannot be taken.\n",
                   i, items[i].weight);
        }
    }

    printf("\nIn our ethereal pocket, we hold:\n");
    printf("Total Weight: %d, Total Value: %.2f\n", currentWeight, totalValue);
    printf("We have gathered the spirits of %d items.\n", spirits);
}

int main() {
    Item items[MAX_ITEMS];
    int numberOfItems;

    printf("Dare you step into the surreal harvest of value and weight?\n");
    printf("Input number of items (a dreamer can hold up to %d): ", MAX_ITEMS);
    scanf("%d", &numberOfItems);

    if (numberOfItems > MAX_ITEMS) {
        numberOfItems = MAX_ITEMS;
        printf("Too ambitious! The spirits will allow only %d items!\n", MAX_ITEMS);
    }

    for (int i = 0; i < numberOfItems; i++) {
        items[i].value = rand() % MYSTICAL_WIND;
        items[i].weight = rand() % (MYSTICAL_WIND / 2) + 1; // weight can't be zero
        printf("Item %d: Value = %d, Weight = %d\n", i, items[i].value, items[i].weight);
    }

    int mysticalWeight;
    printf("Charms enchanted, input a mystical weight for our dream bag: ");
    scanf("%d", &mysticalWeight);
    
    surrealGreedyBag(items, numberOfItems, mysticalWeight);

    printf("As dawn breaks upon the dreams, our expedition concludes...\n");
    return 0;
}