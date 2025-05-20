//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct floor {
    int id;
    int current;
    int max;
};

struct floor floors[] = {
    {1, 0, 4},
    {2, 0, 5},
    {3, 0, 6},
    {4, 0, 8},
    {5, 0, 9},
    {6, 0, 10},
};

struct floor *get_floor(int floor_id) {
    for(int i = 0; i < 7; i++) {
        if(floors[i].id == floor_id)
            return &floors[i];
    }
    return NULL;
}

void move_to(struct floor *floor, int direction) {
    int next_floor = floor->id + direction;
    if(next_floor < 0 || next_floor > 6)
        return;
    floor->current = next_floor;
}

void print_floor(struct floor *floor) {
    printf("%d: %d / %d\n", floor->id, floor->current, floor->max);
}

int main() {
    srand(time(NULL));

    struct floor *current_floor = get_floor(rand() % 7);

    while(1) {
        int direction = rand() % 4;
        move_to(current_floor, direction);

        print_floor(current_floor);

        int request = rand() % 4;
        if(request == 0) {
            int destination = rand() % 7;
            while(get_floor(destination)!= current_floor) {
                destination = rand() % 7;
            }
            move_to(current_floor, -request);
        }
    }

    return 0;
}