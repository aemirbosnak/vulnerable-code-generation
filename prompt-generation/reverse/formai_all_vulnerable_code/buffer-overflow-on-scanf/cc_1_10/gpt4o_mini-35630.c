//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 5

typedef struct {
    int current_floor;
    bool is_in_use;
} Elevator;

typedef struct {
    Elevator elevator;
    int requested_floor;
} Building;

void init_building(Building *building) {
    building->elevator.current_floor = 1; // Starting from ground floor
    building->elevator.is_in_use = false;
    building->requested_floor = -1;
}

void request_elevator(Building *building, int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("Alas! A fleeting wish at a floor that does not stand.\n");
        return;
    }
    building->requested_floor = floor;
    printf("O fair Juliet, the elevator hath been summoned to the %dth floor!\n", floor);
}

void move_elevator(Building *building) {
    building->elevator.is_in_use = true;
    int start = building->elevator.current_floor;
    int end = building->requested_floor;

    if (start < end) {
        for (int i = start; i <= end; i++) {
            printf("Ascending to floor %d...\n", i);
            sleep(1);
        }
    } else {
        for (int i = start; i >= end; i--) {
            printf("Descending to floor %d...\n", i);
            sleep(1);
        }
    }

    building->elevator.current_floor = end;
    printf("The elevator hath arrived at the %dth floor! Step forth, dear aspirations!\n", end);
    building->requested_floor = -1; // Reset request
    building->elevator.is_in_use = false;
}

void entering_elevator() {
    printf("Enter thou, with hopes and dreams entwined!\n");
}

void farewell() {
    printf("Parting is such sweet sorrow...\n");
}

int main() {
    Building fair_verona;
    init_building(&fair_verona);

    int choice;
    while (true) {
        printf("\nHark! Choose thy path:\n1. Request Elevator\n2. Exit\nYour choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int floor;
            printf("Which floor dost thou desire? (1 - %d): ", MAX_FLOORS);
            scanf("%d", &floor);
            request_elevator(&fair_verona, floor);
            if (fair_verona.requested_floor != -1) {
                entering_elevator();
                move_elevator(&fair_verona);
                farewell();
            }
        } else if (choice == 2) {
            printf("As night follows day, so I must take my leave. Adieu!\n");
            break;
        } else {
            printf("Prithee! Choose wisely.\n");
        }
    }

    return 0;
}