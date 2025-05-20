//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_BAG_WEIGHT 50
#define MAX_BAG_SIZE 100

struct Bag {
    int weight;
    int size;
    int destination;
};

void generateBags(struct Bag bags[], int numBags) {
    srand(time(NULL));
    for (int i = 0; i < numBags; i++) {
        bags[i].weight = rand() % MAX_BAG_WEIGHT + 1;
        bags[i].size = rand() % MAX_BAG_SIZE + 1;
        bags[i].destination = rand() % 10 + 1;
    }
}

void sortBags(struct Bag bags[], int numBags) {
    for (int i = 0; i < numBags - 1; i++) {
        for (int j = i + 1; j < numBags; j++) {
            if (bags[i].weight > bags[j].weight) {
                struct Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

int main() {
    struct Bag bags[MAX_BAGS];
    int numBags;

    printf("Enter the number of bags: ");
    scanf("%d", &numBags);

    if (numBags > MAX_BAGS) {
        printf("Error: Too many bags\n");
        return 1;
    }

    generateBags(bags, numBags);
    sortBags(bags, numBags);

    printf("Sorted bags by weight:\n");
    for (int i = 0; i < numBags; i++) {
        printf("Bag %d: Weight %d, Size %d, Destination %d\n", i + 1, bags[i].weight, bags[i].size, bags[i].destination);
    }

    return 0;
}