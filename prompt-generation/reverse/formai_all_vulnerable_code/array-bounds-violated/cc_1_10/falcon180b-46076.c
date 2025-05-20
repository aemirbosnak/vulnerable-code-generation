//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_PLANES 10
#define NUM_BAGGAGES 50
#define NUM_DESTINATIONS 20

typedef struct {
    int id;
    char destination[20];
} Baggage;

void print_baggage(Baggage baggage) {
    printf("Baggage %d is going to %s\n", baggage.id, baggage.destination);
}

void shuffle_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    Baggage bags[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i + 1;
        sprintf(bags[i].destination, "Destination %d", i + 1);
    }

    int planes[NUM_PLANES];
    for (int i = 0; i < NUM_PLANES; i++) {
        planes[i] = i + 1;
    }

    int baggages[NUM_BAGGAGES];
    for (int i = 0; i < NUM_BAGGAGES; i++) {
        baggages[i] = i + 1;
    }

    int destinations[NUM_DESTINATIONS];
    for (int i = 0; i < NUM_DESTINATIONS; i++) {
        destinations[i] = i + 1;
    }

    shuffle_array(baggages, NUM_BAGGAGES);
    shuffle_array(destinations, NUM_DESTINATIONS);

    for (int i = 0; i < NUM_BAGGAGES; i++) {
        int bag_id = baggages[i];
        int dest_id = destinations[i];

        printf("Baggage %d is going to %d\n", bag_id, dest_id);

        int plane_id = rand() % NUM_PLANES;
        planes[plane_id] = dest_id;
    }

    printf("\nPlanes:\n");
    for (int i = 0; i < NUM_PLANES; i++) {
        printf("Plane %d is going to %d\n", planes[i], i + 1);
    }

    return 0;
}