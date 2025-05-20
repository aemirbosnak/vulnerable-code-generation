//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 5
#define MAX_PEOPLE 10

typedef struct {
    int floor;
    int people;
} elevator;

elevator elevators[2];
int current_elevator = 0;
int people_in_elevator[MAX_PEOPLE];
int num_people_in_elevator = 0;

void move_elevator(int direction) {
    if (direction == 1 && elevators[current_elevator].floor < FLOORS - 1) {
        elevators[current_elevator].floor++;
    } else if (direction == 2 && elevators[current_elevator].floor > 0) {
        elevators[current_elevator].floor--;
    }
}

void enter_elevator(int floor) {
    if (num_people_in_elevator < MAX_PEOPLE && floor == elevators[current_elevator].floor) {
        people_in_elevator[num_people_in_elevator] = floor;
        num_people_in_elevator++;
    }
}

int main() {
    int requests[FLOORS][2];
    int i, j, request;

    for (i = 0; i < FLOORS; i++) {
        requests[i][0] = i;
        requests[i][1] = 0;
    }

    for (i = 0; i < FLOORS; i++) {
        while (requests[i][1] == 0) {
            scanf("%d", &request);
            if (request == i) {
                requests[i][1] = 1;
                enter_elevator(i);
            }
        }

        if (elevators[current_elevator].floor == i) {
            move_elevator(1);
        } else {
            move_elevator(requests[i][0] < elevators[current_elevator].floor ? 2 : 1);
        }
    }

    for (i = 0; i < num_people_in_elevator; i++) {
        printf("Person %d went to floor %d\n", i + 1, people_in_elevator[i]);
    }

    return 0;
}