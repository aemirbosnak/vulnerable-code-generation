//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 4
#define MAX_REQUESTS 100

typedef struct {
    int floor;
    int destination;
    int elevator;
} request;

int main() {
    srand(time(NULL));

    int num_floors = rand() % MAX_FLOORS + 1;
    int num_elevators = rand() % MAX_ELEVATORS + 1;
    int num_requests = rand() % MAX_REQUESTS + 1;

    int floors[MAX_FLOORS];
    for (int i = 0; i < num_floors; i++) {
        floors[i] = i;
    }

    int elevators[MAX_ELEVATORS];
    for (int i = 0; i < num_elevators; i++) {
        elevators[i] = rand() % num_floors;
    }

    request requests[MAX_REQUESTS];
    for (int i = 0; i < num_requests; i++) {
        requests[i].floor = rand() % num_floors;
        requests[i].destination = rand() % num_floors;
        requests[i].elevator = -1;
    }

    int current_time = 0;
    while (1) {
        for (int i = 0; i < num_elevators; i++) {
            if (elevators[i]!= -1) {
                printf("Elevator %d is at floor %d\n", i+1, elevators[i]);
            }
        }

        for (int i = 0; i < num_requests; i++) {
            if (requests[i].elevator == -1) {
                for (int j = 0; j < num_elevators; j++) {
                    if (elevators[j] == requests[i].floor) {
                        requests[i].elevator = j+1;
                        elevators[j] = requests[i].destination;
                        break;
                    }
                }
            }
        }

        current_time++;
        for (int i = 0; i < num_elevators; i++) {
            if (elevators[i]!= -1) {
                int direction = (elevators[i] > elevators[i-1])? 1 : -1;
                elevators[i] += direction;
                if (elevators[i] == requests[i].destination) {
                    requests[i].elevator = -1;
                }
            }
        }
    }

    return 0;
}