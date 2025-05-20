//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 5
#define MAX_REQUESTS 50
#define ELEVATOR_SPEED 5

// Elevator data structure
typedef struct {
    int floor;
    int direction;
} Elevator;

// Request data structure
typedef struct {
    int floor;
    int time;
} Request;

// Initialize elevator and request arrays
Elevator elevators[MAX_ELEVATORS];
Request requests[MAX_REQUESTS];

int main() {
    int num_elevators, num_requests;
    int i, j, k;

    // Initialize random seed
    srand(time(NULL));

    // Get number of elevators and requests from user
    printf("Enter number of elevators: ");
    scanf("%d", &num_elevators);
    printf("Enter number of requests: ");
    scanf("%d", &num_requests);

    // Initialize elevators
    for (i = 0; i < num_elevators; i++) {
        elevators[i].floor = rand() % MAX_FLOORS;
        elevators[i].direction = rand() % 2? 1 : -1;
    }

    // Initialize requests
    for (i = 0; i < num_requests; i++) {
        requests[i].floor = rand() % MAX_FLOORS;
        requests[i].time = rand() % 1000;
    }

    // Simulate elevator movements
    for (i = 0; i < num_requests; i++) {
        for (j = 0; j < num_elevators; j++) {
            if (elevators[j].floor == requests[i].floor) {
                if (elevators[j].direction == 1 && requests[i].floor < elevators[j].floor) {
                    elevators[j].floor--;
                } else if (elevators[j].direction == -1 && requests[i].floor > elevators[j].floor) {
                    elevators[j].floor++;
                } else {
                    elevators[j].floor = requests[i].floor;
                }
                break;
            }
        }
    }

    // Print final elevator positions
    printf("\nFinal elevator positions:\n");
    for (i = 0; i < num_elevators; i++) {
        printf("Elevator %d is on floor %d\n", i+1, elevators[i].floor);
    }

    return 0;
}