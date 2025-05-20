//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
#include <stdio.h> //standard input-output header file
#include <stdlib.h> //standard library header file
#include <unistd.h> //header file for sleep function

int main() {
    int current_floor = 0, dest_floor, choice, floors_to_move, elevator_speed, i, j, k;
    //initialize necessary variables

    printf("Welcome to the Elevator Simulation Program!\n");
    printf("===========================================\n");

    printf("\nEnter the speed of the elevator (in floors per second): ");
    scanf("%d", &elevator_speed); //user input for elevator speed

    while(1) { //infinite loop for simulation

        printf("\n\nThe elevator is currently on floor %d\n", current_floor);

        printf("What is your destination floor? ");
        scanf("%d", &dest_floor); //user input for desired floor

        if(dest_floor > current_floor) {
            floors_to_move = dest_floor - current_floor; //calculate number of floors to move up
            printf("The elevator will move up to floor %d\n", dest_floor);
        }
        else if(dest_floor < current_floor) {
            floors_to_move = current_floor - dest_floor; //calculate number of floors to move down
            printf("The elevator will move down to floor %d\n", dest_floor);
        }
        else {
            printf("You are already on that floor!\n"); //if user is already on the desired floor
            continue; //start the simulation from the beginning
        }

        printf("\nPress 1 to proceed with the elevator's movement, or press 2 to cancel: ");
        scanf("%d", &choice); //user input for confirmation

        if(choice == 1) { //if user confirms

            printf("\nThe elevator is moving.\n");

            for(i = 0; i < floors_to_move; i++) { //loop to simulate movement
                printf("Floor %d\n", current_floor);
                sleep(1/elevator_speed); //sleep function to simulate elevator speed
                current_floor++; //increment current floor
            }

            printf("\nThe elevator has arrived at floor %d\n", dest_floor);
        }
        else { //if user cancels
            printf("\nThe elevator has been cancelled.\n");
        }

        printf("\nPress 1 to continue with another user, or press 2 to exit: ");
        scanf("%d", &choice); //user input for continuing or exiting

        if(choice == 1) { //if user continues
            continue; //start the simulation from the beginning
        }
        else if(choice == 2) { //if user exits
            for(j = 3; j >= 1; j--) { //countdown before exiting
                printf("\nExiting in %d...\n", j);
                sleep(1); //sleep function to simulate countdown
            }
            printf("\nGoodbye!\n"); //exit message
            exit(0); //exit program
        }
        else { //if user inputs an invalid choice
            for(k = 3; k >= 1; k--) { //countdown before starting simulation again
                printf("\nInvalid choice. Starting simulation again in %d...\n", k);
                sleep(1); //sleep function to simulate countdown
            }
            continue; //start the simulation from the beginning
        }
    }

    return 0;
}