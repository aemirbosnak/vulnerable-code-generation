//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAG_WEIGHT 50
#define MAX_BAGS_PER_PLANE 100

typedef struct {
    char name[50];
    int weight;
    int plane;
} Bag;

void sortBagsByWeight(Bag bags[], int numBags) {
    for (int i = 0; i < numBags; i++) {
        for (int j = i + 1; j < numBags; j++) {
            if (bags[i].weight > bags[j].weight) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

void loadBagsIntoPlanes(Bag bags[], int numBags, int numPlanes) {
    int remainingBags = numBags;
    int remainingPlanes = numPlanes;

    for (int i = 0; i < numPlanes; i++) {
        if (remainingBags == 0) {
            break;
        } else {
            Bag currentBag = bags[--remainingBags];
            currentBag.plane = i;
        }
    }

    for (int i = 0; i < remainingPlanes; i++) {
        printf("%s loaded onto plane %d\n", bags[i].name, bags[i].plane);
    }
}

int main() {
    Bag bags[MAX_BAGS_PER_PLANE];
    int numBags = 0;

    while (1) {
        char name[50];
        int weight;
        printf("Enter bag name: ");
        scanf("%s", name);
        printf("Enter bag weight: ");
        scanf("%d", &weight);

        if (numBags == MAX_BAGS_PER_PLANE) {
            printf("Baggage handling system full. No more bags can be loaded.\n");
            break;
        }

        Bag newBag = {name, weight, -1};
        bags[numBags++] = newBag;
    }

    sortBagsByWeight(bags, numBags);

    int numPlanes = 5;
    loadBagsIntoPlanes(bags, numBags, numPlanes);

    return 0;
}