//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct luggage {
    char* id;
    int weight;
};

struct flight {
    char* idFlight;
    struct luggage *luggages;
    int numLuggages;
};

void printLuggage(struct luggage* l) {
    printf("Luggage ID: %s\n", l->id);
    printf("Luggage weight: %d\n", l->weight);
    printf("\n");
}

void printFlight(struct flight* f) {
    printf("Flight ID: %s\n", f->idFlight);
    printf("Number of Luggages: %d\n", f->numLuggages);
    for(int i = 0; i < f->numLuggages; i++) {
        printf("Luggage %d:\n", i+1);
        printLuggage(&f->luggages[i]);
    }
}

void destroyFlight(struct flight* f) {
    for(int i = 0; i < f->numLuggages; i++) {
        free(f->luggages[i].id);
    }
    free(f->luggages);
    free(f->idFlight);
    free(f);
}

int main() {
    int numFlights;
    printf("Enter number of flights: ");
    scanf("%d", &numFlights);

    struct flight** allFlights = (struct flight**) malloc(sizeof(struct flight*) * numFlights);
    for(int i = 0; i < numFlights; i++) {
        allFlights[i] = (struct flight*) malloc(sizeof(struct flight));
        printf("Enter Flight ID: ");
        char flightId[50];
        scanf("%s", flightId);
        allFlights[i]->idFlight = (char*) malloc(sizeof(char) * (strlen(flightId) + 1));
        strcpy(allFlights[i]->idFlight, flightId);

        printf("Enter number of luggages: ");
        scanf("%d", &allFlights[i]->numLuggages);
        allFlights[i]->luggages = (struct luggage*) malloc(sizeof(struct luggage) * allFlights[i]->numLuggages);
        for(int j = 0; j < allFlights[i]->numLuggages; j++) {
            allFlights[i]->luggages[j].id = (char*) malloc(sizeof(char) * 10);
            sprintf(allFlights[i]->luggages[j].id, "%s-%d", allFlights[i]->idFlight, j+1);
            printf("Enter luggage weight: ");
            scanf("%d", &allFlights[i]->luggages[j].weight);
        }
    }

    printf("\n");

    for(int i = 0; i < numFlights; i++) {
        printf("Flight %d:\n", i+1);
        printFlight(allFlights[i]);
    }

    for(int i = 0; i < numFlights; i++) {
        destroyFlight(allFlights[i]);
    }

    free(allFlights);
    return 0;
}