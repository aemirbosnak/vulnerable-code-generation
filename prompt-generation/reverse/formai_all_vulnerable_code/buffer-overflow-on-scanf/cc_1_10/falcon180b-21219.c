//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define MAX_PASSENGERS 10
#define MAX_REQUESTS 100

typedef struct {
    int floor;
    int destination;
} Passenger;

Passenger passengers[MAX_PASSENGERS];
int num_passengers;

void add_passenger() {
    printf("Enter floor: ");
    scanf("%d", &passengers[num_passengers].floor);
    printf("Enter destination floor: ");
    scanf("%d", &passengers[num_passengers].destination);
    num_passengers++;
}

void simulate_elevator() {
    int elevator_floor = 0;
    int num_requests = 0;
    int current_time = 0;

    srand(time(NULL));

    while (num_requests < MAX_REQUESTS) {
        current_time++;

        if (current_time % 10 == 0) {
            int new_passenger = rand() % NUM_FLOORS;

            if (new_passenger!= elevator_floor) {
                add_passenger();
            }
        }

        if (num_passengers > 0) {
            int closest_passenger = -1;
            int closest_distance = NUM_FLOORS;

            for (int i = 0; i < num_passengers; i++) {
                int distance = abs(passengers[i].floor - elevator_floor);

                if (distance < closest_distance) {
                    closest_distance = distance;
                    closest_passenger = i;
                }
            }

            if (closest_passenger!= -1) {
                elevator_floor = passengers[closest_passenger].floor;
                num_passengers--;
                num_requests++;
            }
        }
    }

    printf("Simulation complete after %d requests.\n", num_requests);
}

int main() {
    printf("Welcome to the Elevator Simulator!\n");
    simulate_elevator();

    return 0;
}