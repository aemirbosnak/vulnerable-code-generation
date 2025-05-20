//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 20
#define MAX_DESTINATIONS 100
#define MAX_WAIT_TIME 30

typedef struct {
    int floor;
    int destination;
    int wait_time;
} Passenger;

void initialize_passengers(Passenger* passengers, int num_passengers) {
    int i;
    for (i = 0; i < num_passengers; i++) {
        passengers[i].floor = rand() % MAX_FLOORS;
        passengers[i].destination = rand() % MAX_FLOORS;
        passengers[i].wait_time = rand() % MAX_WAIT_TIME;
    }
}

void simulate_elevator(Passenger* passengers, int num_passengers) {
    int i, j, current_floor, next_floor, num_stops, wait_time;
    for (i = 0; i < num_passengers; i++) {
        current_floor = passengers[i].floor;
        next_floor = passengers[i].destination;
        num_stops = 0;
        while (current_floor!= next_floor) {
            if (current_floor < next_floor) {
                current_floor++;
            } else {
                current_floor--;
            }
            num_stops++;
        }
        wait_time = passengers[i].wait_time;
        printf("Passenger %d is traveling from floor %d to floor %d with %d stops and a wait time of %d seconds.\n",
               i, current_floor, next_floor, num_stops, wait_time);
        sleep(wait_time);
    }
}

int main() {
    int num_passengers;
    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);
    if (num_passengers > MAX_PASSENGERS || num_passengers < 1) {
        printf("Invalid number of passengers.\n");
        return 1;
    }
    Passenger* passengers = malloc(sizeof(Passenger) * num_passengers);
    if (passengers == NULL) {
        printf("Memory error.\n");
        return 1;
    }
    initialize_passengers(passengers, num_passengers);
    simulate_elevator(passengers, num_passengers);
    free(passengers);
    return 0;
}