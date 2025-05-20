//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

int main(){

    // initializing variables for elevator simulation
    int current_floor = 1;
    int destination_floor, num_of_passengers;
    char direction;

    // initial message for the user
    printf("Welcome to the elevator simulation program!\n");

    // loop for executing elevator simulation
    while(1){
        printf("You are currently on floor %d.\n", current_floor);

        // taking input from user for selecting direction
        printf("Enter 'U' for going up and 'D' for going down: ");
        scanf(" %c", &direction);

        // checking direction input validity
        if(direction != 'U' && direction != 'D'){
            printf("Invalid direction input. Please enter 'U' for going up and 'D' for going down.\n");
            continue;
        }

        // taking input from user for selecting destination floor
        printf("Enter destination floor number (from 1 to 10): ");
        scanf("%d", &destination_floor);

        // checking destination floor input validity
        if(destination_floor < 1 || destination_floor > 10){
            printf("Invalid destination floor. Please enter a number between 1 and 10.\n");
            continue;
        }

        // taking input from user for number of passengers
        printf("Enter number of passengers (max 10): ");
        scanf("%d", &num_of_passengers);

        // checking input for number of passengers validity
        if(num_of_passengers <= 0 || num_of_passengers > 10){
            printf("Invalid number of passengers. Please enter a number between 1 and 10.\n");
            continue;
        }

        // checking direction and adjusting elevator movement based on it
        if(direction == 'U'){
            printf("Going up...\n");
            // going up floor by floor until destination floor is reached
            while(current_floor <= destination_floor){
                printf("Floor %d. Doors opening and closing.\n", current_floor);
                current_floor++;
            }
        }
        else{
            printf("Going down...\n");
            // going down floor by floor until destination floor is reached
            while(current_floor >= destination_floor){
                printf("Floor %d. Doors opening and closing.\n", current_floor);
                current_floor--;
            }
        }

        // confirming the arrival to the destination floor and number of passengers
        printf("You have arrived at floor %d with %d passengers.\n", destination_floor, num_of_passengers);

        // asking if user wants to continue or exit
        printf("Do you want to continue? Enter 'Y' for Yes or 'N' for No: ");
        char choice;
        scanf(" %c", &choice);

        // checking user choice and exiting the program if 'N' is entered
        if(choice == 'N'){
            printf("Exiting the program...");
            break;
        }
    }

    return 0;
}