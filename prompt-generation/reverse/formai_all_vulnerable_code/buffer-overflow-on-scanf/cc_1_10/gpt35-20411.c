//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: lively
// Welcome to the ELEVATOR SIMULATOR 3000!
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 1
#define MAX_ELEVATOR_CAPACITY 10

int currentFloor = 1;
bool isMoving = false;
bool isDoorOpen = false;
int destination = 1;
int numOfPassengers = 0;

void moveElevator() {
    isMoving = true;
    printf("Elevator is moving to floor %d...\n", destination);
    while (currentFloor != destination) {
        if (currentFloor > destination) {
            currentFloor--;
        } else {
            currentFloor++;
        }
        printf("Current floor: %d\n", currentFloor);
        sleep(1);
    }
    isMoving = false;
    printf("Elevator has arrived at floor %d\n", currentFloor);
}

void openDoor() {
    isDoorOpen = true;
    printf("Doors are opening...\n");
    sleep(3);
    printf("Doors are now open\n");
}

void closeDoor() {
    isDoorOpen = false;
    printf("Doors are closing...\n");
    sleep(3);
    printf("Doors are now closed\n");
}

void addPassengers(int num) {
    if (numOfPassengers + num > MAX_ELEVATOR_CAPACITY) {
        printf("Not enough room for %d passengers\n", num);
    } else {
        numOfPassengers += num;
        printf("%d passengers have entered the elevator\n", num);
    }
}

void removePassengers(int num) {
    if (numOfPassengers - num < 0) {
        printf("%d passengers cannot leave, there are only %d in the elevator\n", num, numOfPassengers);
    } else {
        numOfPassengers -= num;
        printf("%d passengers have left the elevator\n", num);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the ELEVATOR SIMULATOR 3000!\n");
    while (true) {
        printf("What floor would you like to go to? (1-10)\n");
        scanf("%d", &destination);
        if (destination < MIN_FLOOR || destination > MAX_FLOOR) {
            printf("Invalid floor, please enter a number between 1 and 10\n");
        } else if (destination == currentFloor) {
            printf("You are already on floor %d\n", currentFloor);
        } else {
            addPassengers(rand() % 5 + 1);
            if (isDoorOpen) {
                closeDoor();
            }
            moveElevator();
            openDoor();
            removePassengers(rand() % 5);
        }
    }
    return 0;
}