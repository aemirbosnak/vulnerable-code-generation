//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define MAX_REQUESTS 100

typedef struct {
    int floor;
    int destination;
} Request;

void add_request(Request* requests, int num_requests, int floor, int destination) {
    for (int i = 0; i < num_requests; i++) {
        if (requests[i].floor == floor && requests[i].destination == destination) {
            return;
        }
    }
    requests[num_requests].floor = floor;
    requests[num_requests].destination = destination;
    num_requests++;
}

void simulate_elevator(int elevator_num, Request* requests, int num_requests, int* current_floor) {
    srand(time(NULL) + elevator_num);
    for (int i = 0; i < num_requests; i++) {
        int floor = requests[i].floor;
        int destination = requests[i].destination;
        printf("Elevator %d is at floor %d and going to floor %d\n", elevator_num, *current_floor, floor);
        *current_floor = floor;
        int direction = rand() % 2;
        if (direction == 0) {
            if (floor > destination) {
                for (int j = floor; j >= destination; j--) {
                    printf("Elevator %d is at floor %d\n", elevator_num, j);
                }
            } else {
                for (int j = floor; j <= destination; j++) {
                    printf("Elevator %d is at floor %d\n", elevator_num, j);
                }
            }
        } else {
            if (floor > destination) {
                for (int j = floor; j >= destination; j--) {
                    printf("Elevator %d is at floor %d\n", elevator_num, j);
                }
            } else {
                for (int j = floor; j <= destination; j++) {
                    printf("Elevator %d is at floor %d\n", elevator_num, j);
                }
            }
        }
    }
}

int main() {
    Request requests[MAX_REQUESTS];
    int num_requests = 0;
    add_request(requests, num_requests, 0, 5);
    add_request(requests, num_requests, 2, 8);
    add_request(requests, num_requests, 4, 2);
    add_request(requests, num_requests, 7, 0);
    add_request(requests, num_requests, 9, 7);

    int current_floor[NUM_ELEVATORS] = {0, 0, 0};

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        simulate_elevator(i, requests, num_requests, &current_floor[i]);
    }

    return 0;
}