//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct elevator {
    int current_floor;
    int destination_floor;
    int direction; // 1 up, -1 down
    int passengers; // number of passengers currently in the elevator
} elevator;

elevator elevator1 = {0, 0, 1, 0};

pthread_mutex_t elevator_lock;

void *elevator_thread(void *arg) {
    while (1) {
        pthread_mutex_lock(&elevator_lock);
        if (elevator1.current_floor == elevator1.destination_floor) {
            // drop off passengers
            elevator1.passengers = 0;
            // get new destination floor
            elevator1.destination_floor = rand() % 10;
            // start moving
            elevator1.direction = (elevator1.destination_floor > elevator1.current_floor) ? 1 : -1;
        } else {
            // move up or down
            elevator1.current_floor += elevator1.direction;
        }
        pthread_mutex_unlock(&elevator_lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t tid;
    pthread_create(&tid, NULL, elevator_thread, NULL);
    while (1) {
        // wait for user input
        printf("Enter a floor number (0-9): ");
        int floor;
        scanf("%d", &floor);
        // request elevator
        pthread_mutex_lock(&elevator_lock);
        elevator1.destination_floor = floor;
        pthread_mutex_unlock(&elevator_lock);
        // wait for elevator to arrive and drop off passengers
        while (elevator1.current_floor != floor || elevator1.passengers > 0);
        // get in elevator
        elevator1.passengers++;
    }
    return 0;
}