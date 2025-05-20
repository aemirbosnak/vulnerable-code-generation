//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int destination;
    int status;
} Baggage;

void generateBaggage(Baggage* baggage, int numBaggage) {
    srand(time(NULL));
    for (int i = 0; i < numBaggage; i++) {
        baggage[i].id = rand() % 1000;
        baggage[i].destination = rand() % 10;
        baggage[i].status = 0;
    }
}

void displayBaggage(Baggage* baggage, int numBaggage) {
    for (int i = 0; i < numBaggage; i++) {
        printf("Baggage %d: ID - %d, Destination - %d, Status - %d\n", i+1, baggage[i].id, baggage[i].destination, baggage[i].status);
    }
}

void sortBaggage(Baggage* baggage, int numBaggage) {
    for (int i = 0; i < numBaggage-1; i++) {
        for (int j = i+1; j < numBaggage; j++) {
            if (baggage[i].destination > baggage[j].destination) {
                Baggage temp = baggage[i];
                baggage[i] = baggage[j];
                baggage[j] = temp;
            }
        }
    }
}

int main() {
    int numBaggage;
    printf("Enter the number of baggage: ");
    scanf("%d", &numBaggage);

    Baggage baggage[numBaggage];
    generateBaggage(baggage, numBaggage);
    displayBaggage(baggage, numBaggage);

    sortBaggage(baggage, numBaggage);
    printf("\nBaggage sorted by destination:\n");
    displayBaggage(baggage, numBaggage);

    return 0;
}