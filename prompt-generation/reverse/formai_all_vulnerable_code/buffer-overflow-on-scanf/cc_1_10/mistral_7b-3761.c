//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int floor;
    int isMoving;
} Elevator;

Elevator elevator = {1, 0};

void move_elevator(int target_floor) {
    if (elevator.floor == target_floor) {
        printf("Elevator already at floor %d\n", target_floor);
        return;
    }

    if (elevator.isMoving) {
        printf("Elevator is currently moving. Please wait.\n");
        return;
    }

    printf("Elevator moving from floor %d to floor %d\n", elevator.floor, target_floor);
    elevator.isMoving = 1;

    if (target_floor > elevator.floor) {
        sleep(1); // Simulate elevator moving up
        move_elevator(target_floor);
    } else {
        sleep(1); // Simulate elevator moving down
        move_elevator(target_floor);
    }

    elevator.floor = target_floor;
    elevator.isMoving = 0;
    printf("Elevator has reached floor %d\n", target_floor);
}

int main() {
    int user_input;

    while (1) {
        printf("Enter target floor (1, 2, or 3): ");
        scanf("%d", &user_input);

        if (user_input < 1 || user_input > 3) {
            printf("Invalid input. Please enter a valid floor number.\n");
            continue;
        }

        move_elevator(user_input);
    }

    return 0;
}