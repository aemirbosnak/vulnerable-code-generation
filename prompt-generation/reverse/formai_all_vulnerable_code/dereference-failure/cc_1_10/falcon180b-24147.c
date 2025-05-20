//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_PASSENGERS 10

typedef struct {
    int passenger_id;
    int bag_count;
    int *bag_ids;
} Passenger;

typedef struct {
    int id;
    int destination;
} Bag;

Passenger passengers[NUM_PASSENGERS];
Bag bags[NUM_BAGS];
int bag_count = 0;

void generate_passengers() {
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        passengers[i].passenger_id = i + 1;
        passengers[i].bag_count = rand() % 5 + 1;
        passengers[i].bag_ids = malloc(sizeof(int) * passengers[i].bag_count);
        for (int j = 0; j < passengers[i].bag_count; j++) {
            passengers[i].bag_ids[j] = -1;
        }
    }
}

void generate_bags() {
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i + 1;
        bags[i].destination = rand() % NUM_PASSENGERS + 1;
    }
}

void assign_bags_to_passengers() {
    for (int i = 0; i < NUM_BAGS; i++) {
        int passenger_id = bags[i].destination;
        for (int j = 0; j < passengers[passenger_id - 1].bag_count; j++) {
            if (passengers[passenger_id - 1].bag_ids[j] == -1) {
                passengers[passenger_id - 1].bag_ids[j] = i + 1;
                break;
            }
        }
    }
}

void print_passengers_and_bags() {
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        printf("Passenger %d has %d bags: ", passengers[i].passenger_id, passengers[i].bag_count);
        for (int j = 0; j < passengers[i].bag_count; j++) {
            printf("%d ", passengers[i].bag_ids[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    generate_passengers();
    generate_bags();
    assign_bags_to_passengers();

    print_passengers_and_bags();

    return 0;
}