//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CAPACITY 8 // max capacity of the elevator
#define MAX_FLOORS 16 // max number of floors in the building
#define MIN_FLOORS 2 // minimum number of floors in the building
#define MAX_PASSENGERS 32 // max number of passengers that can be served

int num_floors; // number of floors in the building
int current_floor; // current floor of the elevator
int num_passengers; // number of passengers currently in the elevator
int elevator_capacity; // current capacity of the elevator
int direction; // 1: going up, -1: going down, 0: idle
int passengers[MAX_CAPACITY]; // array of passengers in the elevator
pthread_mutex_t mutex; // mutex variable for thread safety

void *elevator_controller(void *data) {
    int *args = (int *)data;
    int num_passenger = args[0];
    int current_floor = args[1];
    int destination_floor = args[2];

    int i;
    pthread_mutex_lock(&mutex);
    while (current_floor != destination_floor) {
        if (direction == 1) {
            if (current_floor < destination_floor) {
                current_floor++;
            } else {
                current_floor--;
            }
        } else if (direction == -1) {
            if (current_floor > destination_floor) {
                current_floor--;
            } else {
                current_floor++;
            }
        }
        printf("Passenger-%d: Floor %d\n", num_passenger, current_floor);
        sleep(1);
    }

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void *elevator() {
    while (num_passengers > 0) {
        pthread_mutex_lock(&mutex);
        int next_floor = -1;
        int destinations[MAX_CAPACITY] = {-1};

        // find the next destination and collect passengers
        int i;
        for (i=0; i<MAX_CAPACITY; i++) {
            if (passengers[i] != -1) { // passenger on board
                if (destinations[passengers[i]] != 1) { // not already recorded destination
                    destinations[passengers[i]] = 1;
                    if (next_floor == -1) {
                        next_floor = i;
                    }
                }
            }
        }

        // drop off passengers
        for (i=0; i<MAX_CAPACITY; i++) {
            if (passengers[i] != -1) { // passenger on board
                if (passengers[i] == current_floor) { // arrived at destination
                    passengers[i] = -1;
                    num_passengers--;
                    elevator_capacity--;
                }
            }
        }

        // pick up passengers
        for (i=0; i<MAX_CAPACITY; i++) {
            if (destinations[i] == 1 && elevator_capacity < MAX_CAPACITY) { // passenger waiting on this floor
                passengers[elevator_capacity] = i;
                num_passengers++;
                elevator_capacity++;
            }
        }

        // change direction if there are no more destinations
        if (next_floor == -1) {
            if (direction == 1) {
                direction = -1;
            } else if (direction == -1) {
                direction = 1;
            }
        } else if (next_floor > current_floor) {
            direction = 1;
        } else if (next_floor < current_floor) {
            direction = -1;
        }

        current_floor += direction;

        printf("Current Floor: %d\n", current_floor);
        printf("Number of Passengers: %d\n", num_passengers);
        printf("Capacity: %d\n", elevator_capacity);
        printf("Direction: %d\n", direction);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    // get number of floors from user input
    printf("Enter the number of floors in the building (between %d and %d): ", MIN_FLOORS, MAX_FLOORS);
    scanf("%d", &num_floors);

    // validate input
    if (num_floors < MIN_FLOORS || num_floors > MAX_FLOORS) {
        printf("Invalid number of floors. Exiting...");
        return 0;
    }

    int num_passengers = rand() % MAX_PASSENGERS + 1;
    printf("Number of Passengers: %d\n", num_passengers);

    int i;
    for (i=0; i<MAX_CAPACITY; i++) {
        passengers[i] = -1;
    }

    int start_floor, dest_floor;
    pthread_t passenger_threads[num_passengers];
    pthread_t elevator_thread;

    current_floor = 1;
    elevator_capacity = 0;
    direction = 1;

    pthread_create(&elevator_thread, NULL, elevator, NULL);

    for (i=0; i<num_passengers; i++) {
        start_floor = rand() % num_floors + 1;
        dest_floor = rand() % num_floors + 1;

        // ensure start floor and destination floor are not equal
        while (start_floor == dest_floor) {
            dest_floor = rand() % num_floors + 1;
        }

        int args[3] = {i+1, start_floor, dest_floor};
        pthread_create(&passenger_threads[i], NULL, elevator_controller, (void *)args);
        sleep(1);
    }

    for (i=0; i<num_passengers; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    pthread_join(elevator_thread, NULL);

    printf("Simulation complete.\n");

    return 0;
}