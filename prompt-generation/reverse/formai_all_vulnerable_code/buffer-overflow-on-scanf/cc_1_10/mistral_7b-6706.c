//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_ELEVATOR 3
#define MIN_DELAY 3
#define MAX_DELAY 10

typedef struct {
    int floor;
    int direction;
} Elevator;

Elevator elevators[MAX_ELEVATOR];
int current_floor = 0;
int elevators_count = 0;

void print_status() {
    printf("Current floor: %d\n", current_floor);
    printf("Elevators:\n");
    for (int i = 0; i < MAX_ELEVATOR; ++i) {
        if (elevators[i].floor != -1) {
            printf("Elevator %d: Floor %d\n", i + 1, elevators[i].floor);
        }
    }
}

void go_up(int elevator_id) {
    if (elevators[elevator_id].floor < current_floor) {
        int delay = rand() % (MAX_DELAY - MIN_DELAY + 1) + MIN_DELAY;
        printf("Elevator %d going up to floor %d with a delay of %d seconds...\n", elevator_id + 1, current_floor, delay);
        sleep(delay);
        elevators[elevator_id].floor = current_floor;
        --current_floor;
        --elevators_count;
    }
}

void go_down(int elevator_id) {
    if (elevators[elevator_id].floor > current_floor) {
        int delay = rand() % (MAX_DELAY - MIN_DELAY + 1) + MIN_DELAY;
        printf("Elevator %d going down to floor %d with a delay of %d seconds...\n", elevator_id + 1, current_floor, delay);
        sleep(delay);
        elevators[elevator_id].floor = current_floor;
        ++current_floor;
        ++elevators_count;
    }
}

void call_elevator(int floor) {
    if (current_floor != floor) {
        for (int i = 0; i < MAX_ELEVATOR; ++i) {
            if (elevators[i].floor == -1) {
                elevators[i].floor = floor;
                printf("Elevator %d called to floor %d\n", i + 1, floor);
                if (current_floor < floor) {
                    go_up(i);
                } else {
                    go_down(i);
                }
                ++elevators_count;
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ELEVATOR; ++i) {
        elevators[i].floor = -1;
    }

    while (1) {
        print_status();
        int user_floor;
        scanf("%d", &user_floor);
        call_elevator(user_floor);
    }

    return 0;
}