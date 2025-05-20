//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

int requests[NUM_FLOORS]; //array of floors that have made an elevator request
pthread_mutex_t req_mutex = PTHREAD_MUTEX_INITIALIZER; // mutex for concurrent access to the request array

//Elevator struct definition
typedef struct {
    int curr_floor;
    int direction; //1 for up, -1 for down, 0 for idle
    int num_passengers;
    int max_capacity;
    int passengers[NUM_FLOORS];
} elevator;

elevator elevators[NUM_ELEVATORS]; //array of elevators

//Function to move the elevator up or down one floor
void move_elevator(elevator *e) {
    e->curr_floor += e->direction;
}

//Thread function for elevator movement
void *elevator_movement(void *arg) {
    int id = *((int*) arg);
    free(arg);

    elevator *e = &elevators[id];

    while (1) {
        //check for elevator requests
        pthread_mutex_lock(&req_mutex);
        int req_floor = -1;

        for (int i = 0; i < NUM_FLOORS; i++) {
            if (requests[i]) {
                req_floor = i;
                break;
            }
        }

        if (req_floor != -1) { //if there's a request, move towards that floor
            if (e->curr_floor < req_floor) {
                e->direction = 1;
                move_elevator(e);
            }

            else if (e->curr_floor > req_floor) {
                e->direction = -1;
                move_elevator(e);
            }

            else { //elevator has arrived at requested floor
                e->direction = 0;
                e->num_passengers += requests[req_floor];
                requests[req_floor] = 0;
            }
        } 

        else { //if no requests, idle on current floor
            e->direction = 0;
        }

        pthread_mutex_unlock(&req_mutex); //release lock

        //sleep for elevator movement delay (simulating elevator speed)
        usleep(1000000);

    }

    return NULL;
}

int main() {
    //initialize elevators
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].curr_floor = 0;
        elevators[i].direction = 0;
        elevators[i].num_passengers = 0;
        elevators[i].max_capacity = 10;
    }

    //initialize request array
    for (int i = 0; i < NUM_FLOORS; i++) {
        requests[i] = 0;
    }

    //create elevator threads
    pthread_t elevator_threads[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&elevator_threads[i], NULL, elevator_movement, arg);
    }

    //main loop for taking elevator requests
    while (1) {
        int floor, dir, num_people;
        printf("Enter elevator request floor, direction (1 for up, -1 for down), and number of people: ");
        scanf("%d %d %d", &floor, &dir, &num_people);

        pthread_mutex_lock(&req_mutex);
        requests[floor] += num_people;
        pthread_mutex_unlock(&req_mutex);
    }

    return 0;
}