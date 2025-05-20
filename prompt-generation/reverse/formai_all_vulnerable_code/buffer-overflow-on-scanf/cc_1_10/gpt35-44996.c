//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10
#define MAX_FLIGHTS 5
#define MAX_LOOPS 4

typedef struct Baggage {
    int id;
    int weight;
    char destination[20];
    char status[10];
} Baggage;

typedef struct Flight {
    int id;
    char destination[20];
    Baggage* baggage_list[MAX_BAGS];
} Flight;

int main() {
    // Initialize the flights
    Flight flights[MAX_FLIGHTS];
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].id = i+1;
        printf("Enter the destination of Flight %d: ", i+1);
        scanf("%s", &flights[i].destination);
        for (int j = 0; j < MAX_BAGS; j++) {
            flights[i].baggage_list[j] = NULL;
        }
    }

    // Initialize the baggage
    Baggage* baggage_list[MAX_BAGS * MAX_FLIGHTS] = {0};
    int num_bags = 0;
    for (int i = 0; i < MAX_LOOPS; i++) {
        int flight_num = rand() % MAX_FLIGHTS;
        int weight = (rand() % 30) + 1;
        Baggage* baggage = malloc(sizeof(Baggage));
        baggage->id = num_bags + 1;
        baggage->weight = weight;
        sprintf(baggage->destination, "%s", flights[flight_num].destination);
        sprintf(baggage->status, "NOT PROCESSED");
        flights[flight_num].baggage_list[i] = baggage;
        baggage_list[num_bags] = baggage;
        num_bags++;
        printf("Baggage %d with weight %d and destination %s added to Flight %d\n",
            baggage->id, baggage->weight, baggage->destination, flights[flight_num].id);
    }

    // Process the baggage for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Processing baggage for Flight %d to destination %s:\n", flights[i].id, flights[i].destination);
        int total_weight = 0;
        for (int j = 0; j < MAX_BAGS; j++) {
            Baggage* baggage = flights[i].baggage_list[j];
            if (baggage != NULL) {
                total_weight += baggage->weight;
                sprintf(baggage->status, "PROCESSED");
                printf("Baggage %d with weight %d and destination %s processed\n",
                    baggage->id, baggage->weight, baggage->destination);
            }
        }
        printf("Total weight of processed baggage for Flight %d: %d\n", flights[i].id, total_weight);
    }

    // Free the memory for the baggage
    for (int i = 0; i < MAX_BAGS * MAX_FLIGHTS; i++) {
        if (baggage_list[i] != NULL) {
            free(baggage_list[i]);
        }
    }

    return 0;
}