//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FLOORS 10
#define MAX_WEIGHT 5000
#define SPEED 10
#define ELEVATOR_ID "EX-1"

typedef struct {
    int floor;
    int weight;
    char name[20];
} Passenger;

typedef struct {
    int current_floor;
    int target_floor;
    int status; // 0: idle, 1: moving up, 2: moving down
    int weight;
    Passenger passengers[4];
} Elevator;

void print_elevator_status(Elevator *elevator) {
    printf("%s is at floor %d, status: ", ELEVATOR_ID, elevator->current_floor);
    switch (elevator->status) {
        case 0:
            printf("idle\n");
            break;
        case 1:
            printf("moving up\n");
            break;
        case 2:
            printf("moving down\n");
            break;
    }

    printf("Weight: %d kg, passengers:\n", elevator->weight);
    for (int i = 0; i < 4; i++) {
        if (elevator->passengers[i].weight > 0) {
            printf("Passenger %s, floor %d, weight %d kg\n", elevator->passengers[i].name, elevator->passengers[i].floor, elevator->passengers[i].weight);
        }
    }
}

void call_elevator(int floor, char name[20], Elevator *elevator) {
    if (elevator->status != 0) {
        printf("Elevator %s is busy, call ignored\n", ELEVATOR_ID);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (elevator->passengers[i].weight == 0) {
            strcpy(elevator->passengers[i].name, name);
            elevator->passengers[i].floor = floor;
            elevator->passengers[i].weight = 70;
            elevator->weight += 70;
            printf("Passenger %s called elevator %s to floor %d\n", name, ELEVATOR_ID, floor);
            break;
        }
    }
}

void move_elevator(Elevator *elevator) {
    int direction;

    if (elevator->target_floor > elevator->current_floor) {
        direction = 1;
    } else if (elevator->target_floor < elevator->current_floor) {
        direction = -1;
    } else {
        printf("Elevator %s reached floor %d\n", ELEVATOR_ID, elevator->current_floor);
        elevator->status = 0;
        return;
    }

    elevator->status = 1;
    elevator->weight += SPEED;
    elevator->current_floor += direction;
}

int main() {
    Elevator elevator = {0};
    srand(time(NULL));
    int floor, rand_floor;
    char name[20];

    printf("Welcome to the future, please use elevator %s\n", ELEVATOR_ID);

    while (1) {
        scanf("%s %d", name, &floor);
        call_elevator(floor, name, &elevator);

        if (elevator.weight > MAX_WEIGHT) {
            printf("Elevator %s is overloaded, ignoring call\n", ELEVATOR_ID);
            continue;
        }

        if (elevator.current_floor == elevator.target_floor) {
            elevator.target_floor = rand() % (FLOORS + 1);
            elevator.status = 0;
            printf("Elevator %s reached floor %d, leaving for random floor\n", ELEVATOR_ID, elevator.current_floor);
        } else {
            move_elevator(&elevator);
        }

        rand_floor = rand() % (FLOORS + 1);
        if (rand() % 2) { // 50% chance of new call
            call_elevator(rand_floor, "Random Passenger", &elevator);
        }

        print_elevator_status(&elevator);
    }

    return 0;
}