//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include<stdio.h>

int floors[10] = {0}; //initializing an array for floors as 0
int currentFloor = 1; //to keep track of currentfloor
int direction = 1; //1 for up and 2 for down

int main() {
    printf("Welcome to Elevator Simulation!\n");
    while(1) {  //infinite loop

        if(direction == 1) {
            printf("Elevator is moving up to floor %d\n", currentFloor);
            floors[currentFloor-1] = 0; //make it 0 as it reaches that floor
            currentFloor++;
        } else {
            printf("Elevator is moving down to floor %d\n", currentFloor);
            floors[currentFloor-1] = 0;
            currentFloor--;
        }

        if(currentFloor == 10 || currentFloor == 1) {
            direction = (direction == 1) ? 2 : 1; //if reached 10th or 1st floor change the direction
        }

        //Printing the elevator's current position and floors
        printf("Elevator is currently at floor %d\n", currentFloor);
        printf("Floors : ");
        for(int i=0; i<10; i++) {
            printf("%d ", floors[i]);
        }
        printf("\n");

        printf("Which floor would you like to go to? (Enter 0 to exit)\n");
        
        int floor;
        scanf("%d", &floor);

        if(floor == 0) { //if 0 is entered, break the loop and exit the program
            break;
        }

        if(floor == currentFloor) {
            printf("You are already on floor %d.\n", currentFloor);
        } else if(floor < 1 || floor > 10) {
            printf("Invalid floor number!\n");
        } else {
            printf("Going to floor %d...\n", floor);
            floors[floor-1] = 1; //make it 1 as it stops on that floor
            if(floor > currentFloor) {
                printf("Going up...\n");
                while(currentFloor != floor) {
                    currentFloor++;
                    printf("Elevator is now on floor %d\n", currentFloor);
                    floors[currentFloor-1] = 0;
                }
            } else {
                printf("Going down...\n");
                while(currentFloor != floor) {
                    currentFloor--;
                    printf("Elevator is now on floor %d\n", currentFloor);
                    floors[currentFloor-1] = 0;
                }
            }
            printf("Arrived at floor %d\n", currentFloor);
        }
    }

    printf("Thank you for using Elevator Simulation!\n");
    return 0;
}