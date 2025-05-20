//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define FLOOR_COUNT 10
#define ELEVATOR_COUNT 3

int current_floor[ELEVATOR_COUNT];
int direction[ELEVATOR_COUNT];
int elevator_request[FLOOR_COUNT][ELEVATOR_COUNT];

pthread_mutex_t lock;

void* elevator_thread(void *arg) {
    int elevator_id = *(int*)arg;
    int curr_floor = current_floor[elevator_id];
    int dest_floor = -1;
    while(1) {
        printf("Elevator %d direction is %s and currently at floor %d\n", elevator_id, direction[elevator_id] == 1 ? "up" : "down", curr_floor);
        if(dest_floor == -1 && elevator_request[curr_floor][elevator_id]) {
            dest_floor = curr_floor;
            elevator_request[curr_floor][elevator_id] = 0;
            printf("Requests from floor %d and elevator %d has been accepted\n", curr_floor, elevator_id);
        }
        if(dest_floor == curr_floor) {
            printf("Reached destination floor %d, stopping elevator %d!\n", curr_floor, elevator_id);
            dest_floor = -1;
            pthread_mutex_unlock(&lock);
        }
        else {
            sleep(2);
            curr_floor += direction[elevator_id];
            if(curr_floor == FLOOR_COUNT) {
                printf("Elevator %d reached top floor, changing direction to down\n", elevator_id);
                direction[elevator_id] = -1;
                curr_floor = FLOOR_COUNT-1;
            }
            else if(curr_floor == -1) {
                printf("Elevator %d reached bottom floor, changing direction to up\n", elevator_id);
                direction[elevator_id] = 1;
                curr_floor = 0;
            }
        }
    }
}

int main() {
    pthread_t elevator_tids[ELEVATOR_COUNT];
    pthread_mutex_init(&lock, NULL);
    int i, j;
    for(i=0; i<ELEVATOR_COUNT; i++) {
        current_floor[i] = 0;
        direction[i] = 1;
    }
    for(i=0; i<FLOOR_COUNT; i++) {
        for(j=0; j<ELEVATOR_COUNT; j++) {
            elevator_request[i][j] = 0;
        }
    }

    int elevator_ids[ELEVATOR_COUNT];

    for(i=0; i<ELEVATOR_COUNT; i++) {
        elevator_ids[i] = i;
        pthread_create(&elevator_tids[i], NULL, elevator_thread, &elevator_ids[i]);
    }

    while(1) {
        int floor_num, elevator_num;
        printf("Enter the floor number (0-9): ");
        scanf("%d", &floor_num);
        printf("Enter the elevator number (0-2): ");
        scanf("%d", &elevator_num);

        if(floor_num >= 0 && floor_num <= 9 && elevator_num >= 0 && elevator_num <= 2) {
            elevator_request[floor_num][elevator_num] = 1;
            printf("Request sent successfully!\n");
        }
        else {
            printf("Invalid input, please enter floors and elevators between 0 and 9\n");
        }
    }

    pthread_exit(NULL);
}