//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 2
#define MAX_PASSENGERS 10
#define MAX_REQUESTS 50

struct elevator {
    int floor;
    int direction;
    int passengers;
};

struct request {
    int floor;
    int elevator;
    int time;
};

int main() {
    srand(time(NULL));

    struct elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = rand() % NUM_FLOORS;
        elevators[i].direction = (rand() % 2)? 1 : -1;
        elevators[i].passengers = 0;
    }

    struct request requests[MAX_REQUESTS];
    int num_requests = 0;

    while (1) {
        printf("Enter a request (floor elevator time): ");
        scanf("%d %d %d", &requests[num_requests].floor, &requests[num_requests].elevator, &requests[num_requests].time);
        num_requests++;

        if (num_requests >= MAX_REQUESTS) {
            printf("Maximum number of requests reached.\n");
            break;
        }
    }

    for (int i = 0; i < num_requests; i++) {
        int elevator_idx = requests[i].elevator - 1;
        int floor = requests[i].floor;
        int time = requests[i].time;

        while (time > 0 && elevators[elevator_idx].floor!= floor) {
            if (elevators[elevator_idx].direction == 1) {
                elevators[elevator_idx].floor++;
            } else {
                elevators[elevator_idx].floor--;
            }

            time--;
        }

        if (time <= 0) {
            printf("Request %d timed out.\n", i + 1);
        } else {
            elevators[elevator_idx].passengers++;
            printf("Elevator %d picked up %d passengers at floor %d.\n", elevator_idx + 1, requests[i].floor, elevators[elevator_idx].floor);
        }
    }

    return 0;
}