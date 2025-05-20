//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Floor {
    int floor;
    int capacity;
    int passengers;
    int direction;
};

struct Floor floors[5];

void elevator() {
    int i, floor;
    for (i = 0; i < 5; i++) {
        printf("Enter floor number: ");
        scanf("%d", &floor);
        floors[i].floor = floor;
        floors[i].capacity = 4;
        floors[i].passengers = 0;
        floors[i].direction = 0;
    }

    while (1) {
        printf("What floor would you like to go to? ");
        scanf("%d", &floor);

        for (i = 0; i < 5; i++) {
            if (floor == floors[i].floor) {
                printf("You have reached your floor: %d\n", floor);
                break;
            }
        }

        if (floor == 5) {
            printf("Sorry, the elevator can only go up to floor 5.\n");
        } else if (floor == 0) {
            printf("Sorry, the elevator can only go up from floor 1.\n");
        } else if (floor == floors[i].floor && floors[i].direction == 0) {
            if (floors[i].passengers < floors[i].capacity) {
                floors[i].passengers++;
                floors[i].direction = 1;
                printf("Elevator is going up to floor %d\n", floor);
            } else {
                printf("Elevator is already full.\n");
            }
        } else if (floor == floors[i].floor && floors[i].direction == 1) {
            if (floors[i].passengers > 0) {
                floors[i].passengers--;
                floors[i].direction = 0;
                printf("Elevator is going down to floor %d\n", floor);
            } else {
                printf("Elevator is already empty.\n");
            }
        } else {
            printf("Elevator cannot go to that floor.\n");
        }
    }
}

int main() {
    srand(time(0));
    int floor;

    printf("Welcome to the Elevator Simulator!\n");
    for (int i = 0; i < 5; i++) {
        floors[i].floor = rand() % 10 + 1;
    }
    elevator();

    return 0;
}