//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 1
#define ELEVATOR_CAPACITY 10
#define DOOR_OPEN_TIME 5

typedef struct {
    int floor;
    bool isDoorOpen;
    int numPeopleInside;
} Elevator;

void initializeElevator(Elevator *elevator);
bool isElevatorFull(Elevator *elevator);
void openDoor(Elevator *elevator);
void closeDoor(Elevator *elevator);
void goToFloor(Elevator *elevator, int floor);
void printElevatorStatus(Elevator *elevator);

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    
    Elevator elevator;
    initializeElevator(&elevator);
    
    for (int i = 1; i <= 20; i++) { // Loop 20 times to simulate moving between floors
        printf("Elevator is on floor %d\n", elevator.floor);
        
        if (elevator.isDoorOpen) {
            elevator.isDoorOpen = false; // Close door if it's open
            printf("Door closed\n");
        }
        
        int numPeopleToEnter = rand() % (ELEVATOR_CAPACITY - elevator.numPeopleInside) + 1;
        elevator.numPeopleInside += numPeopleToEnter;
        printf("%d people entered the elevator\n", numPeopleToEnter);
        
        int numPeopleToExit = rand() % (elevator.numPeopleInside + 1);
        elevator.numPeopleInside -= numPeopleToExit;
        printf("%d people exited the elevator\n", numPeopleToExit);
        
        int destinationFloor = rand() % MAX_FLOOR + 1;
        goToFloor(&elevator, destinationFloor);
        
        openDoor(&elevator);
        printf("Door opened\n");
        
        printf("Waiting for passengers...\n");
        sleep(DOOR_OPEN_TIME);
    }
    
    return 0;
}

void initializeElevator(Elevator *elevator) {
    elevator->floor = MIN_FLOOR;
    elevator->isDoorOpen = false;
    elevator->numPeopleInside = 0;
}

bool isElevatorFull(Elevator *elevator) {
    return elevator->numPeopleInside == ELEVATOR_CAPACITY;
}

void openDoor(Elevator *elevator) {
    elevator->isDoorOpen = true;
}

void closeDoor(Elevator *elevator) {
    elevator->isDoorOpen = false;
}

void goToFloor(Elevator *elevator, int floor) {
    int direction = (floor > elevator->floor) ? 1 : -1;
    
    while (elevator->floor != floor) {
        elevator->floor += direction;
        printElevatorStatus(elevator);
        sleep(1); // Pause for 1 second to simulate time passing
    }
}

void printElevatorStatus(Elevator *elevator) {
    printf("Elevator is on floor %d with %d people inside\n", elevator->floor, elevator->numPeopleInside);
}