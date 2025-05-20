//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

// declaring global variables
int max_floor = 10;
int min_floor = 0;
int current_floor = 0;
int destination_floor = 0;
int passengers = 0;
int max_capacity = 10;
int current_capacity = 0;

// Function to print the main menu
void print_menu()
{
    printf("\nWelcome to the Elevator Simulation program!\n");
    printf("Please choose from the following options:\n");
    printf("1. Choose a floor to go to.\n");
    printf("2. Check current floor and capacity.\n");
    printf("3. Add a passenger.\n");
    printf("4. Remove a passenger.\n");
    printf("5. Exit.\n");
}

// Function to move the elevator to the selected floor
void move_elevator()
{
    if(destination_floor > current_floor){
        printf("\nThe elevator is going up to floor %d.\n", destination_floor);
    }
    else{
        printf("\nThe elevator is going down to floor %d.\n", destination_floor);
    }
    current_floor = destination_floor;
    destination_floor = 0;   // reset the destination floor 
}

// main function
int main()
{
    int choice;
    printf("Enter the maximum capacity of the elevator:\n");
    scanf("%d", &max_capacity);
    print_menu();

    do{
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the floor number you want to go to:\n");
                scanf("%d", &destination_floor);
                if(destination_floor >= min_floor && destination_floor <= max_floor){
                    if(destination_floor == current_floor){
                        printf("\nYou are already on floor %d. Please choose a different floor.\n", current_floor);
                    }
                    else{
                        move_elevator();
                        printf("\nThe elevator has arrived at floor %d.\n", current_floor);
                    }
                }
                else{
                    printf("\nThat floor doesn't exist. Please choose a floor between %d and %d.\n", min_floor, max_floor);
                }
                break;
            case 2:
                printf("\nYou are currently on floor %d.\n", current_floor);
                printf("The elevator currently has %d passengers and a capacity of %d.\n", current_capacity, max_capacity);
                break;
            case 3:
                if(current_capacity < max_capacity){
                    current_capacity++;
                    printf("\nA passenger has been added to the elevator. Current capacity is now %d passengers.\n", current_capacity);
                }
                else{
                    printf("\nThe elevator is already at full capacity. Please remove a passenger before adding another.\n");
                }
                break;
            case 4:
                if(current_capacity > 0){
                    current_capacity--;
                    printf("\nA passenger has been removed from the elevator. Current capacity is now %d passengers.\n", current_capacity);
                }
                else{
                    printf("\nThe elevator is currently empty. There are no passengers to remove.\n");
                }
                break;
            case 5:
                printf("\nThank you for using the Elevator Simulation program!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    }while(choice != 5);

    return 0;
}