//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_FLIGHTS 10
#define NUM_DESTINATIONS 5
#define MAX_DELAY 5

typedef struct {
    int flight_num;
    int dest_num;
    int delay;
} Flight;

typedef struct {
    int dest_num;
    char *name;
} Destination;

void generate_flights(Flight flights[], int num_flights) {
    for (int i = 0; i < num_flights; i++) {
        flights[i].flight_num = i + 1;
        flights[i].dest_num = rand() % NUM_DESTINATIONS;
        flights[i].delay = rand() % MAX_DELAY;
    }
}

void generate_destinations(Destination dests[], int num_destinations) {
    for (int i = 0; i < num_destinations; i++) {
        dests[i].dest_num = i + 1;
        dests[i].name = malloc(10 * sizeof(char));
        sprintf(dests[i].name, "City %d", dests[i].dest_num);
    }
}

int main() {
    srand(time(NULL));

    Flight flights[NUM_FLIGHTS];
    generate_flights(flights, NUM_FLIGHTS);

    Destination dests[NUM_DESTINATIONS];
    generate_destinations(dests, NUM_DESTINATIONS);

    int num_bags = 0;
    int bags[NUM_BAGS];

    while (num_bags < NUM_BAGS) {
        int flight_num, dest_num;
        scanf("%d %d", &flight_num, &dest_num);

        if (flight_num >= 1 && flight_num <= NUM_FLIGHTS &&
            dest_num >= 1 && dest_num <= NUM_DESTINATIONS) {

            int delay = flights[flight_num - 1].delay;
            int i;
            for (i = 0; i < num_bags; i++) {
                if (bags[i] == dest_num) {
                    printf("Baggage already on flight %d to %s\n", flight_num, dests[dest_num - 1].name);
                    break;
                }
            }

            if (i == num_bags) {
                bags[num_bags] = dest_num;
                printf("Baggage added to flight %d to %s with delay of %d minutes\n", flight_num, dests[dest_num - 1].name, delay);
                num_bags++;
            }
        } else {
            printf("Invalid flight or destination\n");
        }
    }

    return 0;
}