//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int floor = 0;
    int floors = 10;
    int passengers = 0;
    int calls = 0;
    int floorsCalled[floors];

    srand(time(NULL));

    while (1) {
        int callFloor = rand() % floors;

        if (callFloor == floor) {
            printf("Passenger arrives at floor %d\n", callFloor);
            passengers++;
        } else {
            printf("Passenger arrives at floor %d\n", callFloor);
            floorsCalled[callFloor]++;
            if (floorsCalled[callFloor] == 1) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 2) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 3) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 4) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 5) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 6) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 7) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 8) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else if (floorsCalled[callFloor] == 9) {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            } else {
                printf("Elevator calls for floor %d\n", callFloor);
                callFloor = floor;
            }
        }

        if (passengers == floors) {
            printf("All floors have been serviced\n");
            break;
        }

        printf("Elevator on floor %d\n", callFloor);

        if (callFloor!= floor) {
            printf("Elevator moves to floor %d\n", callFloor);
            floor = callFloor;
        } else {
            printf("Elevator stays on floor %d\n", callFloor);
        }

        if (floorsCalled[callFloor] == 0) {
            printf("Passenger leaves floor %d\n", callFloor);
            passengers--;
        }
    }

    return 0;
}