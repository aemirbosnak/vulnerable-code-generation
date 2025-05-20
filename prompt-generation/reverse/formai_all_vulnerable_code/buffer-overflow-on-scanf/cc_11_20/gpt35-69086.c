//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGGAGE_COUNT 500
#define MAX_SORTER_COUNT 10
#define MAX_FLIGHT_COUNT 50

typedef struct BaggageTag {
    int id;
    int flightNumber;
    bool isSorted;
} BaggageTag;

typedef struct Flight {
    int number;
    int departureTime;
    int baggageCount;
    BaggageTag baggage[MAX_BAGGAGE_COUNT];
} Flight;

typedef struct Sorter {
    int id;
    bool isBusy;
    int flightNumber;
    int baggageIndex;
} Sorter;

int main() {
    int flightCount, sorterCount;
    printf("Enter number of flights: ");
    scanf("%d", &flightCount);
    Flight flights[MAX_FLIGHT_COUNT];
    for (int i = 0; i < flightCount; i++) {
        Flight flight;
        flight.number = i + 1;
        printf("Enter departure time for flight %d: ", flight.number);
        scanf("%d", &flight.departureTime);
        printf("Enter number of baggage for flight %d: ", flight.number);
        scanf("%d", &flight.baggageCount);
        for (int j = 0; j < flight.baggageCount; j++) {
            BaggageTag baggage;
            baggage.id = j + 1;
            baggage.flightNumber = flight.number;
            baggage.isSorted = false;
            flight.baggage[j] = baggage;
        }
        flights[i] = flight;
    }
    printf("Enter number of bag sorters: ");
    scanf("%d", &sorterCount);
    Sorter sorters[MAX_SORTER_COUNT];
    for (int i = 0; i < sorterCount; i++) {
        Sorter sorter;
        sorter.id = i + 1;
        sorter.isBusy = false;
        sorter.flightNumber = 0;
        sorter.baggageIndex = -1;
        sorters[i] = sorter;
    }
    printf("Simulation started...\n");
    int currentTime = 0;
    bool allBaggageSorted = false;
    while (!allBaggageSorted) {
        // Check if all baggage is sorted
        allBaggageSorted = true;
        for (int i = 0; i < flightCount; i++) {
            for (int j = 0; j < flights[i].baggageCount; j++) {
                if (!flights[i].baggage[j].isSorted) {
                    allBaggageSorted = false;
                    break;
                }
            }
        }
        // Update sorters
        for (int i = 0; i < sorterCount; i++) {
            if (sorters[i].isBusy) {
                if (currentTime >= flights[sorters[i].flightNumber - 1].departureTime) {
                    printf("Sorter %d missed flight %d.\n", sorters[i].id, sorters[i].flightNumber);
                    sorters[i].isBusy = false;
                    sorters[i].flightNumber = 0;
                    sorters[i].baggageIndex = -1;
                } else {
                    flights[sorters[i].flightNumber - 1].baggage[sorters[i].baggageIndex].isSorted = true;
                    sorters[i].isBusy = false;
                    sorters[i].flightNumber = 0;
                    sorters[i].baggageIndex = -1;
                    printf("Sorter %d sorted baggage for flight %d.\n", sorters[i].id, flights[sorters[i].flightNumber - 1].number);
                }
            }
        }
        // Assign baggage to sorters
        for (int i = 0; i < flightCount; i++) {
            if (currentTime >= flights[i].departureTime) {
                continue;
            }
            for (int j = 0; j < flights[i].baggageCount; j++) {
                if (flights[i].baggage[j].isSorted) {
                    continue;
                }
                for (int k = 0; k < sorterCount; k++) {
                    if (!sorters[k].isBusy) {
                        sorters[k].isBusy = true;
                        sorters[k].flightNumber = i + 1;
                        sorters[k].baggageIndex = j;
                        printf("Sorter %d assigned to baggage %d for flight %d.\n", sorters[k].id, flights[i].baggage[j].id, flights[i].number);
                        break;
                    }
                }
            }
        }
        // Wait for one minute
        currentTime++;
        printf("\n");
    }
    printf("All baggage sorted.\n");
    return 0;
}