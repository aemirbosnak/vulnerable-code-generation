//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int floor;
    int people;
} Floor;

void elevator(int numFloors, Floor floors[], int maxPeople) {
    int currentFloor = 0;
    int nextFloor = 0;
    int peopleToGetOff = 0;
    int peopleToGetOn = 0;
    
    printf("Enter the number of floors: ");
    scanf("%d", &numFloors);
    printf("Enter the maximum number of people per floor: ");
    scanf("%d", &maxPeople);
    
    for (int i = 0; i < numFloors; i++) {
        printf("Enter the number of people on floor %d: ", i + 1);
        scanf("%d", &floors[i].people);
    }
    
    while (currentFloor!= numFloors) {
        printf("Current floor: %d\n", currentFloor + 1);
        if (floors[currentFloor].people > 0) {
            peopleToGetOff = floors[currentFloor].people;
            floors[currentFloor].people -= peopleToGetOff;
            printf("People leaving: %d\n", peopleToGetOff);
        }
        for (int j = 0; j < maxPeople; j++) {
            if (nextFloor == numFloors) {
                nextFloor = 0;
            } else if (floors[nextFloor].people > 0 && nextFloor!= currentFloor) {
                peopleToGetOn = floors[nextFloor].people;
                floors[nextFloor].people -= peopleToGetOn;
                printf("People entering: %d\n", peopleToGetOn);
                currentFloor = nextFloor;
                nextFloor = (nextFloor + 1) % numFloors;
            }
        }
    }
}

int main() {
    Floor floors[10];
    int numFloors = 10;
    int maxPeople = 5;
    elevator(numFloors, floors, maxPeople);
    return 0;
}