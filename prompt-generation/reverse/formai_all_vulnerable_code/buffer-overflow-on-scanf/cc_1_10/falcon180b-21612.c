//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *destination;
    int weight;
} Baggage;

void generateBaggage(Baggage *baggage, int numBaggage) {
    srand(time(NULL));
    for (int i = 0; i < numBaggage; i++) {
        baggage[i].id = rand() % 10000;
        baggage[i].destination = (char *) malloc(10 * sizeof(char));
        sprintf(baggage[i].destination, "City%d", rand() % 100);
        baggage[i].weight = rand() % 50 + 1;
    }
}

void printBaggage(Baggage *baggage, int numBaggage) {
    for (int i = 0; i < numBaggage; i++) {
        printf("ID: %d, Destination: %s, Weight: %d kg\n", baggage[i].id, baggage[i].destination, baggage[i].weight);
    }
}

void sortBaggage(Baggage *baggage, int numBaggage, int (*compare)(const void *, const void *)) {
    qsort(baggage, numBaggage, sizeof(Baggage), compare);
}

int compareID(const void *a, const void *b) {
    return (*(Baggage *) a).id - (*(Baggage *) b).id;
}

int compareWeight(const void *a, const void *b) {
    return (*(Baggage *) b).weight - (*(Baggage *) a).weight;
}

int main() {
    int numBaggage;
    printf("Enter the number of baggage: ");
    scanf("%d", &numBaggage);

    Baggage *baggage = (Baggage *) malloc(numBaggage * sizeof(Baggage));
    generateBaggage(baggage, numBaggage);
    printBaggage(baggage, numBaggage);

    printf("Sort by ID:\n");
    sortBaggage(baggage, numBaggage, compareID);
    printBaggage(baggage, numBaggage);

    printf("Sort by weight:\n");
    sortBaggage(baggage, numBaggage, compareWeight);
    printBaggage(baggage, numBaggage);

    free(baggage);
    return 0;
}