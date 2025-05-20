//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 10
#define MAX_REQUESTS 100
#define MAX_PASSENGERS 5

typedef struct {
    int floor;
    int capacity;
    int passengers;
    int direction;
    int requests[MAX_REQUESTS];
    int num_requests;
} elevator;

void init_elevator(elevator* e) {
    e->floor = 0;
    e->capacity = MAX_CAPACITY;
    e->passengers = 0;
    e->direction = 1;
    e->num_requests = 0;
}

void add_request(elevator* e, int floor) {
    if (e->num_requests < MAX_REQUESTS) {
        e->requests[e->num_requests] = floor;
        e->num_requests++;
    }
}

int get_next_request(elevator* e) {
    int next_request = -1;
    if (e->num_requests > 0) {
        next_request = e->requests[0];
        int i;
        for (i = 1; i < e->num_requests; i++) {
            if (abs(next_request - e->floor) > abs(e->requests[i] - e->floor)) {
                next_request = e->requests[i];
            }
        }
        e->num_requests--;
    }
    return next_request;
}

void move_elevator(elevator* e) {
    if (e->direction == 1) {
        e->floor++;
    } else {
        e->floor--;
    }
}

void open_doors(elevator* e) {
    printf("Elevator doors open on floor %d\n", e->floor);
}

void close_doors(elevator* e) {
    printf("Elevator doors close on floor %d\n", e->floor);
}

void serve_request(elevator* e, int floor) {
    printf("Elevator stops on floor %d\n", floor);
    e->floor = floor;
    open_doors(e);
    e->num_requests--;
    close_doors(e);
}

void simulate_elevator(elevator* e, int num_floors, int num_passengers) {
    init_elevator(e);
    srand(time(NULL));
    int i;
    for (i = 0; i < num_floors; i++) {
        add_request(e, i);
    }
    while (e->num_requests > 0) {
        int next_request = get_next_request(e);
        printf("Elevator moves to floor %d\n", next_request);
        move_elevator(e);
        serve_request(e, next_request);
    }
    printf("Elevator simulation complete\n");
}

int main() {
    int num_floors, num_passengers;
    printf("Enter number of floors: ");
    scanf("%d", &num_floors);
    printf("Enter number of passengers: ");
    scanf("%d", &num_passengers);
    if (num_floors > MAX_FLOORS || num_passengers > MAX_PASSENGERS) {
        printf("Invalid input\n");
        return 1;
    }
    elevator e;
    simulate_elevator(&e, num_floors, num_passengers);
    return 0;
}