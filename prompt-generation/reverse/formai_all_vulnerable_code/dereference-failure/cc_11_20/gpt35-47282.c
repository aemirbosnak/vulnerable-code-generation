//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define ELEVATOR_CAPACITY 10

pthread_mutex_t floors_mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t elevators_sem;
pthread_t elevators[NUM_ELEVATORS];

int floors[NUM_FLOORS][ELEVATOR_CAPACITY];
int num_people_waiting[NUM_FLOORS] = {0}; // number of people waiting on each floor
int num_people_in_elevator[NUM_ELEVATORS] = {0}; // number of people in each elevator
int elevator_floors[NUM_ELEVATORS] = {0}; // the current floor of each elevator
int elevator_directions[NUM_ELEVATORS] = {1,-1,1}; // the direction of each elevator (1 = up, -1 = down)
int target_floor[NUM_ELEVATORS][NUM_FLOORS] = {0}; // the number of people on a given floor that wants to go to a given floor for each elevator
int idle_elevators = NUM_ELEVATORS;

void *elevator_thread(void *id) {
    int elevator_id = *(int*)id;
    int current_floor = elevator_floors[elevator_id];
    int current_direction = elevator_directions[elevator_id];

    while (1) {
        // check if there are any people in the elevator that want to get off
        int num_people_in_elevator_current_floor = 0;
        for (int i = 0; i < num_people_in_elevator[elevator_id]; i++) {
            if (floors[current_floor][i] == current_floor) {
                num_people_in_elevator_current_floor++;
            }
        }
        if (num_people_in_elevator_current_floor > 0) {
            printf("Elevator %d arrived at floor %d\n", elevator_id, current_floor);
            // let the people that want to get off leave the elevator
            num_people_in_elevator[elevator_id] -= num_people_in_elevator_current_floor;
            sem_post(&elevators_sem);
        }

        // check if there are any people on the current floor that want to go in the same direction as the elevator
        int num_people_waiting_current_floor = num_people_waiting[current_floor];
        int num_people_to_pickup = 0;
        for (int i = 0; i < num_people_waiting_current_floor; i++) {
            if (current_direction == 1 && floors[current_floor][i] > current_floor) {
                num_people_to_pickup++;
            } else if (current_direction == -1 && floors[current_floor][i] < current_floor) {
                num_people_to_pickup++;
            }
        }
        if (num_people_to_pickup > 0) {
            printf("Elevator %d arrived at floor %d\n", elevator_id, current_floor);
            // let the people that want to go in the same direction enter the elevator
            int num_people_pickedup = 0;
            for (int i = 0; i < num_people_waiting_current_floor; i++) {
                if (num_people_pickedup == ELEVATOR_CAPACITY) {
                    break;
                }
                if (current_direction == 1 && floors[current_floor][i] > current_floor) {
                    floors[current_floor][i] = -1; // person got on the elevator
                    target_floor[elevator_id][floors[current_floor][i]]++;
                    num_people_in_elevator[elevator_id]++;
                    num_people_waiting[current_floor]--;
                    num_people_pickedup++;
                } else if (current_direction == -1 && floors[current_floor][i] < current_floor) {
                    floors[current_floor][i] = -1; // person got on the elevator
                    target_floor[elevator_id][floors[current_floor][i]]++;
                    num_people_in_elevator[elevator_id]++;
                    num_people_waiting[current_floor]--;
                    num_people_pickedup++;
                }
            }
            sem_post(&elevators_sem);
        }

        // check if the elevator needs to change direction
        int should_change_direction = 0;
        for (int i = 0; i < NUM_FLOORS; i++) {
            if (target_floor[elevator_id][i] > 0) {
                if (current_direction == 1 && i < current_floor) {
                    should_change_direction = 1;
                } else if (current_direction == -1 && i > current_floor) {
                    should_change_direction = 1;
                }
            }
        }
        if (should_change_direction) {
            current_direction *= -1;
            printf("Elevator %d changed direction\n", elevator_id);
        }

        // update the current floor of the elevator
        current_floor += current_direction;
        elevator_floors[elevator_id] = current_floor;

        // check if the elevator needs to stop
        if (num_people_in_elevator[elevator_id] == 0 && num_people_waiting[current_floor] == 0 && target_floor[elevator_id][current_floor] == 0) {
            idle_elevators++;
            sem_wait(&elevators_sem);
            idle_elevators--;
        }
    }
}

int main() {
    sem_init(&elevators_sem, 0, 0);

    // spawn elevator threads
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        int *id = malloc(sizeof(*id));
        *id = i;
        pthread_create(&elevators[i], NULL, elevator_thread, id);
    }

    // generate random test data
    srand(123);
    for (int i = 0; i < 100; i++) {
        int floor = rand() % NUM_FLOORS;
        int target_floor = rand() % NUM_FLOORS;
        int elevator_id = rand() % NUM_ELEVATORS;
        if (num_people_waiting[floor] < ELEVATOR_CAPACITY) {
            floors[floor][num_people_waiting[floor]] = target_floor;
            num_people_waiting[floor]++;
        }
    }

    // wait for elevator threads to finish
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevators[i], NULL);
    }

    sem_destroy(&elevators_sem);

    return 0;
}