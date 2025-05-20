//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int destination;
} Baggage;

Baggage* generateBaggage(int num) {
    Baggage* baggage = (Baggage*)malloc(sizeof(Baggage) * num);
    for (int i = 0; i < num; i++) {
        baggage[i].id = i + 1;
        baggage[i].destination = rand() % 10 + 1;
    }
    return baggage;
}

void printBaggage(Baggage* baggage, int num) {
    for (int i = 0; i < num; i++) {
        printf("Baggage #%d is destined for location #%d\n", baggage[i].id, baggage[i].destination);
    }
}

void sortBaggage(Baggage* baggage, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
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

    Baggage* baggage = generateBaggage(numBaggage);
    printBaggage(baggage, numBaggage);

    sortBaggage(baggage, numBaggage);
    printf("Sorted Baggage:\n");
    printBaggage(baggage, numBaggage);

    return 0;
}