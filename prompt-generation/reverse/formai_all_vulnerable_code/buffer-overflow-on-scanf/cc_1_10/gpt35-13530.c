//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

#define FLOORS 10  //Number of floors in the building
#define ELEVATORS 3 //Number of elevators in the building
#define UP 1 //Direction up
#define DOWN -1 //Direction down
#define IDLE 0 //Elevator is idle

struct Elevator {
    int floor; //Current floor of the elevator
    int direction; //Direction in which the elevator is moving
    bool isMoving; //Flag to indicate if the elevator is moving or not
};

//Function to check if atleast one of the elevators is moving
bool areElevatorsMoving(struct Elevator elevators[]) {
    for(int i=0; i<ELEVATORS; i++) {
        if(elevators[i].isMoving) {
            return true;
        }
    }
    return false;
}

//Function to service requests for floor by elevators
void serviceFloorRequests(int floorRequests[], struct Elevator elevators[]) {
    for(int i=0; i<ELEVATORS; i++) {
        if(elevators[i].isMoving) { //Elevator is moving
            int currentFloor = elevators[i].floor;
            int direction = elevators[i].direction;
            if(currentFloor == floorRequests[i]) { //Elevator has reached the floor that was requested
                elevators[i].isMoving = false;
                elevators[i].direction = IDLE;
                printf("Elevator %d has reached floor %d and is now idle.\n", i, currentFloor);
                floorRequests[i] = 0; //Floor request has been serviced
            }
            else { //Elevator has not reached the floor yet
                elevators[i].floor += direction;
                printf("Elevator %d is moving %s and is now at floor %d.\n", i, direction == UP ? "up" : "down", elevators[i].floor);
            }
        }
        else { //Elevator is idle
            if(floorRequests[i] != 0) { //There is a pending floor request for the elevator
                int currentFloor = elevators[i].floor;
                int requestedFloor = floorRequests[i];
                elevators[i].direction = currentFloor < requestedFloor ? UP : DOWN; //Set the direction in which the elevator needs to move
                elevators[i].isMoving = true; //Set the flag to indicate that the elevator is moving
                printf("Elevator %d has started moving %s from floor %d towards floor %d.\n", i, elevators[i].direction == UP ? "up" : "down", currentFloor, requestedFloor);
            }
        }
    }
}

int main() {
    int floorRequests[ELEVATORS] = {0}; //Array to store the floor requests made by the elevators
    struct Elevator elevators[ELEVATORS] = {
        {0, IDLE, false},
        {0, IDLE, false},
        {0, IDLE, false},
    }; //Array of elevators
    
    int floorRequest; //Variable to store floor requests made by the users
    
    do {
        printf("Enter the floor request (1 to %d) or 0 to exit: ", FLOORS);
        scanf("%d", &floorRequest); //Get the floor request from the user
        
        if(floorRequest >= 1 && floorRequest <= FLOORS) { //Valid floor request
            int elevatorIndex = -1;
            int minDistance = FLOORS + 1; //Assuming maximum distance between two floors is FLOORS
            for(int i=0; i<ELEVATORS; i++) { //Find the elevator which is closest to the requested floor and is idle or moving in the same direction as the requested floor
                int currentFloor = elevators[i].floor;
                int distance = elevators[i].isMoving ? abs(floorRequest - currentFloor) : abs(floorRequest - currentFloor);
                if((!elevators[i].isMoving && elevators[i].direction == IDLE) || (elevators[i].isMoving && elevators[i].direction == (floorRequest > currentFloor ? UP : DOWN))) {
                    if(distance < minDistance) {
                        minDistance = distance;
                        elevatorIndex = i;
                    }
                }
            }
            if(elevatorIndex != -1) { //Elevator found to service the request
                floorRequests[elevatorIndex] = floorRequest;
                printf("Elevator %d has been assigned to service floor %d.\n", elevatorIndex, floorRequest);
            }
            else { //All elevators are busy or moving in the wrong direction
                printf("All elevators are busy or moving in the wrong direction. Please wait.\n");
            }
        }
        else if(floorRequest != 0) { //Invalid floor request
            printf("Invalid floor request. Please try again.\n");
        }

        serviceFloorRequests(floorRequests, elevators); //Service floor requests made by elevators
    } while(floorRequest != 0 || areElevatorsMoving(elevators)); //Loop until all floor requests have been serviced and all elevators are idle

    printf("Thank you for using Elevator Simulation.\n");
    
    return 0;
}