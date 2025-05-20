//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 20
#define MAX_REQUESTS 100

int num_floors;
int num_passengers;
int num_requests;
int elevator_position;
int elevator_direction;
int elevator_speed;
int request_queue[MAX_REQUESTS];
int front_request, rear_request;

void initialize() {
    srand(time(NULL));
    num_floors = rand() % MAX_FLOORS + 1;
    num_passengers = rand() % MAX_PASSENGERS + 1;
    num_requests = rand() % MAX_REQUESTS + 1;
    elevator_position = 1;
    elevator_direction = 1;
    elevator_speed = 1;
    front_request = -1;
    rear_request = -1;
}

void enqueue_request(int floor) {
    if (rear_request == MAX_REQUESTS - 1) {
        printf("Request queue is full.\n");
        return;
    }
    rear_request++;
    request_queue[rear_request] = floor;
}

int dequeue_request() {
    if (front_request == -1) {
        return -1;
    }
    int floor = request_queue[front_request];
    front_request++;
    return floor;
}

void move_elevator() {
    if (elevator_direction == 1) {
        elevator_position++;
        if (elevator_position > num_floors) {
            elevator_direction = 0;
        }
    } else {
        elevator_position--;
        if (elevator_position < 1) {
            elevator_direction = 1;
        }
    }
}

int main() {
    initialize();
    int current_floor = 1;
    int destination_floor;
    int i, j;

    printf("Elevator simulation begins:\n");
    printf("Number of floors: %d\n", num_floors);
    printf("Number of passengers: %d\n", num_passengers);
    printf("Number of requests: %d\n", num_requests);

    for (i = 0; i < num_passengers; i++) {
        destination_floor = rand() % num_floors + 1;
        enqueue_request(destination_floor);
    }

    while (front_request!= -1 || rear_request!= -1) {
        current_floor = elevator_position;
        move_elevator();

        for (j = front_request; j <= rear_request; j++) {
            if (request_queue[j] == current_floor) {
                printf("Stopped at floor %d\n", current_floor);
                if (elevator_direction == 1) {
                    elevator_position--;
                } else {
                    elevator_position++;
                }
                front_request = j + 1;
                rear_request = j - 1;
                break;
            } else if (request_queue[j] < current_floor && elevator_direction == 1) {
                printf("Passed floor %d\n", request_queue[j]);
            } else if (request_queue[j] > current_floor && elevator_direction == 0) {
                printf("Passed floor %d\n", request_queue[j]);
            }
        }
    }

    printf("Elevator simulation ends.\n");

    return 0;
}