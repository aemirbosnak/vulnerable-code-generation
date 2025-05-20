//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int weight;
} Baggage;

typedef struct {
    int numBags;
    Baggage bags[50];
} Airport;

void handleBags(Airport* airport) {
    for (int i = 0; i < airport->numBags; i++) {
        printf("Bag %d: %s, %d lbs\n", airport->bags[i].id, airport->bags[i].name, airport->bags[i].weight);
    }
}

int main() {
    Airport airport;
    airport.numBags = 0;

    printf("Enter the number of bags: ");
    scanf("%d", &airport.numBags);

    if (airport.numBags > 0) {
        for (int i = 0; i < airport.numBags; i++) {
            printf("Enter the ID of bag %d: ", i+1);
            scanf("%d", &airport.bags[i].id);
            fflush(stdin);

            printf("Enter the name of bag %d: ", i+1);
            fgets(airport.bags[i].name, sizeof(airport.bags[i].name), stdin);
            fflush(stdin);

            printf("Enter the weight of bag %d: ", i+1);
            scanf("%d", &airport.bags[i].weight);
            fflush(stdin);
        }

        handleBags(&airport);

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}