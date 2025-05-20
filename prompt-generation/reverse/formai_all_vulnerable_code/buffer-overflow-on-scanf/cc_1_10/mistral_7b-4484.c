//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 10

typedef struct {
    int floor;
    int passengers[ELEVATOR_CAPACITY];
    int current_passenger;
} Elevator;

void init_elevator(Elevator *elevator, int starting_floor) {
    elevator->floor = starting_floor;
    elevator->current_passenger = 0;
}

void add_passenger(Elevator *elevator, int passenger_floor) {
    if (elevator->floor == passenger_floor) {
        if (elevator->current_passenger < ELEVATOR_CAPACITY) {
            elevator->passengers[elevator->current_passenger] = passenger_floor;
            elevator->current_passenger++;
        } else {
            printf("Elevator is full.\n");
        }
    } else {
        printf("Elevator is not at your floor.\n");
    }
}

void move_elevator(Elevator *elevator, int target_floor) {
    int direction = (target_floor > elevator->floor) ? 1 : -1;
    int floors_to_move = abs(target_floor - elevator->floor);

    printf("Elevator is moving to floor %d.\n", target_floor);

    for (int i = 0; i < floors_to_move; i++) {
        elevator->floor += direction;
        printf("Elevator is now at floor %d.\n", elevator->floor);

        for (int j = 0; j < elevator->current_passenger; j++) {
            if (elevator->floor == elevator->passengers[j]) {
                printf("Passenger %d exiting at floor %d.\n", j + 1, elevator->floor);
                elevator->passengers[j] = -1;
                elevator->current_passenger--;
                i--;
                break;
            }
        }
    }
}

int main() {
    Elevator elevator;
    int user_floor, target_floor;

    init_elevator(&elevator, 0);

    while (1) {
        printf("Enter your floor number: ");
        scanf("%d", &user_floor);

        if (user_floor == -1) {
            break;
        }

        add_passenger(&elevator, user_floor);

        printf("Enter target floor number or -1 to exit: ");
        scanf("%d", &target_floor);

        if (target_floor != -1) {
            move_elevator(&elevator, target_floor);
        }
    }

    printf("Thank you for using the elevator simulation.\n");

    return 0;
}