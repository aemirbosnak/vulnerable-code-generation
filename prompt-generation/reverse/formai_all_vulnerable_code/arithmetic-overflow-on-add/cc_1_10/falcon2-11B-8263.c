//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int floor;
    int people;
} Floor;

typedef struct {
    Floor floors[10];
} Elevator;

void initialize_elevator(Elevator *elevator) {
    for (int i = 0; i < 10; i++) {
        elevator->floors[i].floor = (rand() % 10) + 1;
        elevator->floors[i].people = 0;
    }
}

void print_elevator(Elevator *elevator) {
    for (int i = 0; i < 10; i++) {
        printf("Floor %d: %d people\n", i + 1, elevator->floors[i].people);
    }
}

void move_elevator(Elevator *elevator, int direction) {
    if (direction == 1) {
        for (int i = 0; i < 10; i++) {
            elevator->floors[i].floor++;
        }
    } else if (direction == -1) {
        for (int i = 0; i < 10; i++) {
            elevator->floors[i].floor--;
        }
    } else {
        printf("Invalid direction\n");
        return;
    }
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    printf("Initial state:\n");
    print_elevator(&elevator);

    int direction;
    int people;

    while (1) {
        printf("Enter direction (+1 for up, -1 for down): ");
        scanf("%d", &direction);

        printf("Enter number of people to move: ");
        scanf("%d", &people);

        if (direction == 1 && elevator.floors[0].people + people > 10) {
            printf("Cannot move up, elevator is full\n");
        } else if (direction == -1 && elevator.floors[9].people + people < 0) {
            printf("Cannot move down, elevator is empty\n");
        } else {
            move_elevator(&elevator, direction);
            elevator.floors[0].people += people;

            printf("Elevator state after moving %d people:\n", people);
            print_elevator(&elevator);
        }
    }

    return 0;
}