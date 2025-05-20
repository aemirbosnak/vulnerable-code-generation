//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CAROUSELS 5
#define BAG_SIZE 10
#define BAG_WEIGHT_LIMIT 50

typedef struct {
    int id;
    int weight;
    char destination[20];
} Bag;

void generateBags(Bag bags[]) {
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i + 1;
        srand(time(NULL) + i);
        bags[i].weight = rand() % BAG_WEIGHT_LIMIT + 1;
        sprintf(bags[i].destination, "Destination %d", rand() % NUM_CAROUSELS + 1);
    }
}

void sortBags(Bag bags[]) {
    for (int i = 0; i < NUM_BAGS - 1; i++) {
        for (int j = i + 1; j < NUM_BAGS; j++) {
            if (bags[i].weight > bags[j].weight) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

void printBags(Bag bags[]) {
    for (int i = 0; i < NUM_BAGS; i++) {
        printf("%d: %s (%d kg)\n", bags[i].id, bags[i].destination, bags[i].weight);
    }
}

int main() {
    Bag bags[NUM_BAGS];
    generateBags(bags);
    sortBags(bags);
    printBags(bags);

    return 0;
}