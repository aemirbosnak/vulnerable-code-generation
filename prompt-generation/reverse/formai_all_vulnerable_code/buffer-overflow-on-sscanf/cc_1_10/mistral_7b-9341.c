//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#define MAX_FLOORS 10
#define MIN_FLOOR 0
#define MAX_CMD_LEN 10
#define IDLE 0
#define MOVING_UP 1
#define MOVING_DOWN 2

typedef struct {
    int current_floor;
    int direction;
} Elevator;

void print_status(Elevator e) {
    printf("Elevator is currently at floor %d and moving %s\n", e.current_floor,
           e.direction == IDLE ? "idle" : e.direction == MOVING_UP ? "up" : "down");
}

void move_elevator(Elevator *e, int new_floor) {
    if (e->current_floor == new_floor) {
        printf("Elevator is already at floor %d\n", new_floor);
        return;
    }

    if (e->direction == IDLE) {
        e->direction = new_floor > e->current_floor ? MOVING_UP : MOVING_DOWN;
        e->current_floor += e->direction == MOVING_UP ? 1 : -1;
        printf("Elevator started moving towards floor %d\n", new_floor);
    } else {
        if (new_floor == e->current_floor) {
            printf("Elevator is already at floor %d\n", new_floor);
            return;
        }

        if (e->direction == MOVING_UP && new_floor < e->current_floor) {
            printf("Elevator cannot move down to floor %d while moving up\n", new_floor);
            return;
        }

        if (e->direction == MOVING_DOWN && new_floor > e->current_floor) {
            printf("Elevator cannot move up to floor %d while moving down\n", new_floor);
            return;
        }

        printf("Elevator changed direction to move towards floor %d\n", new_floor);
        e->direction = new_floor > e->current_floor ? MOVING_DOWN : MOVING_UP;
        e->current_floor += e->direction == MOVING_UP ? 1 : -1;
    }
}

int main() {
    Elevator elevator = {.current_floor = 0, .direction = IDLE};
    char cmd[MAX_CMD_LEN];
    int new_floor;

    while (1) {
        print_status(elevator);
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        if (sscanf(cmd, "%d", &new_floor) != 1 || new_floor < MIN_FLOOR || new_floor > MAX_FLOORS) {
            printf("Invalid command, please enter a valid floor number\n");
            continue;
        }

        move_elevator(&elevator, new_floor);
    }

    return 0;
}