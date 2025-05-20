//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define BAG_SIZE 100

typedef struct {
    int id;
    int weight;
    int destination;
} Bag;

Bag bags[MAX_BAGS];

void loadBag(Bag* bag) {
    printf("Enter bag ID: ");
    scanf("%d", &bag->id);
    printf("Enter bag weight: ");
    scanf("%d", &bag->weight);
    printf("Enter bag destination: ");
    scanf("%d", &bag->destination);
}

void unloadBag(Bag* bag) {
    printf("Bag %d unloaded at destination %d\n", bag->id, bag->destination);
}

void sortBags() {
    for (int i = 0; i < MAX_BAGS; i++) {
        for (int j = i + 1; j < MAX_BAGS; j++) {
            if (bags[i].destination > bags[j].destination) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

void printBags() {
    for (int i = 0; i < MAX_BAGS; i++) {
        printf("Bag %d: ID %d, Weight %d, Destination %d\n", i, bags[i].id, bags[i].weight, bags[i].destination);
    }
}

int main() {
    srand(time(NULL));

    int numBags;
    printf("Enter number of bags: ");
    scanf("%d", &numBags);

    for (int i = 0; i < numBags; i++) {
        loadBag(&bags[i]);
    }

    sortBags();

    printf("Sorted bags:\n");
    printBags();

    return 0;
}