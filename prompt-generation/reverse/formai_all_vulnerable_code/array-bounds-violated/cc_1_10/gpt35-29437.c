//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Baggage {
    int id;
    int weight;
    char destination[3]; // airport code
    int isLoaded;
};

struct Flight {
    int id;
    int maxWeight;
    char destination[3];
    struct Baggage *baggageList;
};

void loadBaggage(struct Flight *flight, int baggageCount) {
    int loadedCount = 0;
    for (int i = 0; i < baggageCount; i++) {
        if (!flight->baggageList[i].isLoaded && flight->baggageList[i].destination == flight->destination && (loadedCount + flight->baggageList[i].weight) <= flight->maxWeight) {
            flight->baggageList[i].isLoaded = 1;
            loadedCount += flight->baggageList[i].weight;
            printf("Baggage ID #%d loaded onto Flight #%d to %s\n", flight->baggageList[i].id, flight->id, flight->destination);
        }
    }
    printf("%d bags loaded onto Flight #%d\n", loadedCount, flight->id);
}

int main() {
    srand(time(0));
    int numFlights = 3;
    int numBaggage = 6;
    struct Flight flights[numFlights];
    struct Baggage baggageList[numBaggage];

    // create flights
    for (int i = 0; i < numFlights; i++) {
        flights[i].id = i;
        flights[i].maxWeight = (rand() % 2000) + 2000;
        char destination[3];
        destination[0] = (rand() % 26) + 65; // letter
        destination[1] = (rand() % 26) + 65; // letter
        destination[2] = (rand() % 10) + 48; // number
        destination[3] = '\0';
        strcpy(flights[i].destination, destination);
        flights[i].baggageList = (struct Baggage*) malloc(numBaggage * sizeof(struct Baggage));
    }

    // create baggage
    for (int i = 0; i < numBaggage; i++) {
        baggageList[i].id = i;
        baggageList[i].weight = (rand() % 50) + 10;
        char destination[3];
        destination[0] = (rand() % 26) + 65; // letter
        destination[1] = (rand() % 26) + 65; // letter
        destination[2] = (rand() % 10) + 48; // number
        destination[3] = '\0';
        strcpy(baggageList[i].destination, destination);
        baggageList[i].isLoaded = 0;
    }

    // add baggage to flights
    for (int i = 0; i < numFlights; i++) {
        for (int j = 0; j < numBaggage; j++) {
            flights[i].baggageList[j] = baggageList[j];
        }
        loadBaggage(&flights[i], numBaggage);
    }

    return 0;
}