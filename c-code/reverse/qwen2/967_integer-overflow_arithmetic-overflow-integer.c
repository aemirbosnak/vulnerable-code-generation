#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 100

typedef struct {
    int weight;
} Bag;

int compare(const void *a, const void *b) {
    return ((Bag *)a)->weight - ((Bag *)b)->weight;
}

void loadBags(Bag bags[], int numBags, int maxWeight) {
    for (int i = 0; i < numBags; i++) {
        if (bags[i].weight > maxWeight) {
            printf("Error: Bag %d exceeds maximum weight limit.\n", i + 1);
            continue;
        }
        printf("Loading bag %d with weight %d kg.\n", i + 1, bags[i].weight);
    }
}

int main() {
    int numBags, maxWeight;
    Bag bags[MAX_BAGS];

    printf("Enter the number of bags: ");
    scanf("%d", &numBags);

    if (numBags <= 0 || numBags > MAX_BAGS) {
        printf("Error: Invalid number of bags.\n");
        return 1;
    }

    printf("Enter the maximum weight per bag in kg: ");
    scanf("%d", &maxWeight);

    if (maxWeight <= 0) {
        printf("Error: Invalid maximum weight.\n");
        return 1;
    }

    printf("Enter the weights of the bags:\n");
    for (int i = 0; i < numBags; i++) {
        scanf("%d", &bags[i].weight);
    }

    qsort(bags, numBags, sizeof(Bag), compare);

    loadBags(bags, numBags, maxWeight);

    return 0;
}
