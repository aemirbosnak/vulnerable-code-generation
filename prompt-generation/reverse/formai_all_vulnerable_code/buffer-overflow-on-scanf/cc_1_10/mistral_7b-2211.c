//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define NUM_ELEVATORS 5
#define FLOORS 10
#define MAX_DELAY 5
#define PRINT_INTERVAL 1

typedef struct elevator_ctrl {
    int floor;
    int direction;
    int speed;
    int delay;
} elevator_ctrl_t;

elevator_ctrl_t elevators[NUM_ELEVATORS];

void init_elevators(void) {
    int i;

    for (i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = 1;
        elevators[i].speed = 1;
        elevators[i].delay = rand() % (MAX_DELAY + 1);
    }
}

void simulate_elevator(int idx) {
    int new_floor;

    printf("Elevator %d: Floor %d, Direction %s\n", idx, elevators[idx].floor,
           elevators[idx].direction > 0 ? "Up" : "Down");

    usleep(elevators[idx].speed * 1000);

    if (elevators[idx].direction > 0) {
        new_floor = elevators[idx].floor + 1;

        if (new_floor > FLOORS) {
            elevators[idx].direction = -1;
            elevators[idx].floor = FLOORS;
        }
    } else {
        new_floor = elevators[idx].floor - 1;

        if (new_floor < 0) {
            elevators[idx].direction = 1;
            elevators[idx].floor = 0;
        }
    }

    elevators[idx].floor = new_floor;

    usleep(elevators[idx].delay * 1000);

    if (PRINT_INTERVAL) {
        printf("Elevator %d: Floor %d, Direction %s\n", idx, elevators[idx].floor,
               elevators[idx].direction > 0 ? "Up" : "Down");
    }

    simulate_elevator((idx + 1) % NUM_ELEVATORS);
}

int main() {
    clock_t start;
    int user_input;

    srand(time(NULL));

    init_elevators();

    start = clock();

    while (1) {
        printf("User Input: ");
        scanf("%d", &user_input);

        if (user_input == 'q') {
            break;
        }

        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i].floor == user_input) {
                elevators[i].direction = !elevators[i].direction;
                break;
            }
        }

        simulate_elevator(0);
    }

    printf("Total Execution Time: %.2fs\n", (float)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}