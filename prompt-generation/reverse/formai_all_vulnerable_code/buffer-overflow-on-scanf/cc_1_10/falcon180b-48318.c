//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define MAX_PASSENGERS 8
#define MAX_REQUESTS 20

typedef struct {
    int floor;
    int destination;
    int num_passengers;
} Request;

typedef struct {
    int num_requests;
    Request requests[MAX_REQUESTS];
} Elevator;

void generate_requests(Elevator* elevator) {
    srand(time(NULL));
    for (int i = 0; i < elevator->num_requests; i++) {
        elevator->requests[i].floor = rand() % NUM_FLOORS;
        elevator->requests[i].destination = rand() % NUM_FLOORS;
        elevator->requests[i].num_passengers = rand() % MAX_PASSENGERS + 1;
    }
}

int main() {
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].num_requests = rand() % MAX_REQUESTS + 1;
        generate_requests(&elevators[i]);
    }

    int current_floor = 0;
    while (1) {
        printf("Current floor: %d\n", current_floor);
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d requests:\n", i);
            for (int j = 0; j < elevators[i].num_requests; j++) {
                printf("  Floor %d to %d with %d passengers\n", elevators[i].requests[j].floor, elevators[i].requests[j].destination, elevators[i].requests[j].num_passengers);
            }
        }

        int choice;
        printf("Enter your destination floor: ");
        scanf("%d", &choice);

        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].num_requests > 0 && elevators[i].requests[0].destination == choice) {
                elevators[i].num_requests--;
                current_floor = choice;
                break;
            }
        }

        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].num_requests > 0) {
                elevators[i].requests[0].floor = current_floor;
            }
        }
    }

    return 0;
}