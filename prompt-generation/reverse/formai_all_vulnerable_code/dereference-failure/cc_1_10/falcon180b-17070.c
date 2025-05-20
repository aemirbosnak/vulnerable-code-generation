//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_BAG_TYPES 5

typedef struct {
    int flight_number;
    int bag_type;
    int destination;
} Bag;

typedef struct {
    int capacity;
    Bag bags[MAX_BAGS];
    int num_bags;
} ConveyorBelt;

typedef struct {
    int num_flights;
    int flights[MAX_FLIGHTS];
} FlightSchedule;

void generate_bag(Bag* bag) {
    bag->flight_number = rand() % MAX_FLIGHTS;
    bag->bag_type = rand() % MAX_BAG_TYPES;
    bag->destination = rand() % 2;
}

void generate_flight_schedule(FlightSchedule* schedule) {
    schedule->num_flights = rand() % MAX_FLIGHTS;
    for (int i = 0; i < schedule->num_flights; i++) {
        schedule->flights[i] = rand() % MAX_FLIGHTS;
    }
}

void print_bag(Bag bag) {
    printf("Flight: %d, Bag Type: %d, Destination: %d\n", bag.flight_number, bag.bag_type, bag.destination);
}

void print_conveyor_belt(ConveyorBelt belt) {
    printf("Number of bags: %d\n", belt.num_bags);
    for (int i = 0; i < belt.num_bags; i++) {
        print_bag(belt.bags[i]);
    }
}

void add_bag(ConveyorBelt* belt, Bag bag) {
    if (belt->num_bags >= MAX_BAGS) {
        printf("Conveyor belt is full!\n");
        return;
    }
    belt->bags[belt->num_bags++] = bag;
}

int main() {
    srand(time(NULL));

    FlightSchedule schedule;
    generate_flight_schedule(&schedule);

    ConveyorBelt belt;
    belt.capacity = MAX_BAGS;

    int num_bags = 0;
    for (int i = 0; i < schedule.num_flights; i++) {
        int num_bags_flight = rand() % 10;
        for (int j = 0; j < num_bags_flight; j++) {
            Bag bag;
            generate_bag(&bag);
            add_bag(&belt, bag);
            num_bags++;
        }
    }

    printf("Number of bags processed: %d\n", num_bags);

    print_conveyor_belt(belt);

    return 0;
}