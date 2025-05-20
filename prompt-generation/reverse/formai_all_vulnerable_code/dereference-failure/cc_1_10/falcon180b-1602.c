//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_DESTINATIONS 10
#define NUM_CAROUSELS 5

typedef struct {
    int destination;
    char *name;
    char *color;
} Bag;

Bag bags[NUM_BAGS];
int destinations[NUM_DESTINATIONS];
int carousels[NUM_CAROUSELS];

void generateBags() {
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].destination = rand() % NUM_DESTINATIONS;
        bags[i].name = malloc(50 * sizeof(char));
        sprintf(bags[i].name, "Bag %d", i+1);
        bags[i].color = malloc(10 * sizeof(char));
        if (rand() % 2 == 0) {
            strcpy(bags[i].color, "Red");
        } else {
            strcpy(bags[i].color, "Blue");
        }
    }
}

void printBag(Bag bag) {
    printf("Destination: %d\n", bag.destination);
    printf("Name: %s\n", bag.name);
    printf("Color: %s\n", bag.color);
}

void sortBags(int (*compare)(const void *, const void *)) {
    qsort(bags, NUM_BAGS, sizeof(Bag), compare);
}

int compareDestinations(const void *a, const void *b) {
    Bag bagA = *(Bag *)a;
    Bag bagB = *(Bag *)b;

    if (bagA.destination < bagB.destination) {
        return -1;
    } else if (bagA.destination > bagB.destination) {
        return 1;
    } else {
        return 0;
    }
}

int compareColors(const void *a, const void *b) {
    Bag bagA = *(Bag *)a;
    Bag bagB = *(Bag *)b;

    if (strcmp(bagA.color, "Red") < strcmp(bagB.color, "Red")) {
        return -1;
    } else if (strcmp(bagA.color, "Red") > strcmp(bagB.color, "Red")) {
        return 1;
    } else {
        return 0;
    }
}

void printBags() {
    for (int i = 0; i < NUM_BAGS; i++) {
        printBag(bags[i]);
    }
}

int main() {
    srand(time(NULL));
    generateBags();
    printBags();
    sortBags(compareDestinations);
    printBags();
    sortBags(compareColors);
    printBags();

    return 0;
}