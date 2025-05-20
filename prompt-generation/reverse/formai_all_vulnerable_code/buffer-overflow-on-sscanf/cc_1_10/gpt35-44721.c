//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 2

int elevators[MAX_ELEVATORS] = {0};
int elevator_floors[MAX_ELEVATORS] = {0};

void printElevator(int e) {
    printf("Elevator %d at floor %d\n", e+1, elevator_floors[e]);
}

void printStatus() {
    printf("Current elevator status:\n");
    for(int i=0; i<MAX_ELEVATORS; i++) {
        printElevator(i);
    }
}

int findClosestElevator(int requested_floor) {
    int found_elevator = -1;
    int minimum_distance = MAX_FLOORS;
    for(int i=0; i<MAX_ELEVATORS; i++) {
        int distance = abs(elevator_floors[i] - requested_floor);
        if(distance < minimum_distance) {
            found_elevator = i;
            minimum_distance = distance;
        }
    }
    return found_elevator;
}

int main() {
    int requested_floor;
    int next_elevator = 0;
    char input[10] = "";

    while(1) {
        printf("Enter floor number (0 to exit): ");
        fgets(input, 10, stdin);
        sscanf(input, "%d", &requested_floor);

        if(requested_floor == 0) {
            break;
        }

        int elevator = findClosestElevator(requested_floor);

        printf("Sending elevator %d to floor %d\n", elevator+1, requested_floor);

        printf("Generating elevator ride...\n");

        int current_floor = elevator_floors[elevator];
        while(current_floor != requested_floor) {
            if (requested_floor > current_floor) {
                current_floor++;
            } else {
                current_floor--;
            }
            elevator_floors[elevator] = current_floor;
            printStatus();
        }

        printf("***Elevator arrived at floor %d***\n", current_floor);
    }

    printf("Exiting elevator simulation\n");

    return 0;
}