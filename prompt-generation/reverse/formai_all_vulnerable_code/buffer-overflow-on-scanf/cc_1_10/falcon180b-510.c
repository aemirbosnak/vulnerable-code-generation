//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define MAX_PASSENGERS 10
#define MAX_ELEVATORS 4

typedef struct {
    int floor;
    int direction;
    int capacity;
    int passengers;
} Elevator;

Elevator elevators[MAX_ELEVATORS];

void initialize_elevators() {
    int i;
    for (i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].floor = 0;
        elevators[i].direction = 0;
        elevators[i].capacity = MAX_PASSENGERS;
        elevators[i].passengers = 0;
    }
}

void move_elevators() {
    int i;
    for (i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].direction == 1) {
            elevators[i].floor++;
        } else if (elevators[i].direction == -1) {
            elevators[i].floor--;
        }
        if (elevators[i].floor == 0) {
            elevators[i].direction = 1;
        } else if (elevators[i].floor == NUM_FLOORS - 1) {
            elevators[i].direction = -1;
        }
    }
}

void request_elevator(int floor) {
    int i;
    for (i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].floor == floor && elevators[i].passengers < elevators[i].capacity) {
            elevators[i].passengers++;
            return;
        }
    }
    printf("Sorry, no elevator available\n");
}

void exit_elevator(int floor) {
    int i;
    for (i = 0; i < MAX_ELEVATORS; i++) {
        if (elevators[i].floor == floor && elevators[i].passengers > 0) {
            elevators[i].passengers--;
            return;
        }
    }
}

int main() {
    int choice;
    int floor;
    int i;
    srand(time(NULL));
    initialize_elevators();
    do {
        printf("Elevator Simulation\n");
        printf("1. Request elevator\n");
        printf("2. Exit elevator\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the floor number: ");
                scanf("%d", &floor);
                request_elevator(floor);
                break;
            case 2:
                printf("Enter the floor number: ");
                scanf("%d", &floor);
                exit_elevator(floor);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    } while (choice!= 3);
    return 0;
}