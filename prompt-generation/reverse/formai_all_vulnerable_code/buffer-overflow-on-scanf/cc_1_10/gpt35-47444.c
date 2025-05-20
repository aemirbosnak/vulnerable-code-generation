//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL));  //to generate a random number every time the code runs
    int currentFloor = 0;  //initializing the elevator at the ground floor
    int destinationFloor;  
    int floors[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  //elevator can go to 10 floors starting from 0 to 9
    char direction;

    printf("Welcome to the shape-shifting elevator simulation.\n\nThe current floor is %d\n", currentFloor);

    while(1){  //loop to continuously take inputs and perform elevator operations

        destinationFloor = floors[rand() % 10];  //randomly selecting a floor to go to

        if(destinationFloor > currentFloor){
            direction = '+';
        }
        else{
            direction = '-';
        }

        printf("\nPlease enter your current floor: ");
        scanf("%d", &currentFloor);

        if(currentFloor < destinationFloor){
            printf("The elevator is going %c to floor %d\n", direction, destinationFloor);
            while(currentFloor != destinationFloor){  //loop until the elevator reaches the destination floor
                if(currentFloor < destinationFloor){
                    printf("Floor %d... ", ++currentFloor);
                }
                else{
                    printf("Floor %d... ", --currentFloor);
                }
            }
            printf("\nYou have reached your destination floor %d\n", destinationFloor);
        }
        else if(currentFloor > destinationFloor){
            printf("The elevator is going %c to floor %d\n", direction, destinationFloor);
            while(currentFloor != destinationFloor){
                if(currentFloor < destinationFloor){
                    printf("Floor %d... ", ++currentFloor);
                }
                else{
                    printf("Floor %d... ", --currentFloor);
                }
            }
            printf("\nYou have reached your destination floor %d\n", destinationFloor);
        }
        else{
            printf("You are already on the current floor %d\n", currentFloor);
        }
    }

    return 0;
}