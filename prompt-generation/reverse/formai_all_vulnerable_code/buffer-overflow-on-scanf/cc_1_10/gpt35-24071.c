//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: grateful
// Thank you for choosing our Elevator Simulation Program!

#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_FLOORS 10
#define MIN_FLOORS 1

// Define global variables
int current_floor = 1;
int num_floors = 0;

void print_menu() {
    printf("\nElevator Simulation\n");
    printf("-----------------------\n");
    printf("Current floor: %d\n", current_floor);
    printf("Choose an option:\n");
    printf("1. Go up\n");
    printf("2. Go down\n");
    printf("3. Change number of floors\n");
    printf("4. Exit program\n");
}

void go_up() {
    if (current_floor < num_floors) {
        current_floor++;
        printf("\nGoing up to floor %d\n", current_floor);
    } else {
        printf("\nYou are already on the top floor!\n");
    }
}

void go_down() {
    if (current_floor > 1) {
        current_floor--;
        printf("\nGoing down to floor %d\n", current_floor);
    } else {
        printf("\nYou are already on the ground floor!\n");
    }
}

void change_num_floors() {
    int new_num_floors;
    do {
        printf("\nEnter new number of floors (%d-%d): ", MIN_FLOORS, MAX_FLOORS);
        scanf("%d", &new_num_floors);
        if (new_num_floors < MIN_FLOORS || new_num_floors > MAX_FLOORS) {
            printf("Invalid input!\n");
        }
    } while (new_num_floors < MIN_FLOORS || new_num_floors > MAX_FLOORS);
    
    current_floor = 1;
    num_floors = new_num_floors;
    printf("\nNumber of floors changed to %d. You are now on the ground floor.\n", num_floors);
}

int main() {
    // Initialize variables
    num_floors = MAX_FLOORS;
    
    // Welcome user and display menu
    printf("Welcome to the Elevator Simulation Program!\n");
    print_menu();
    
    // Loop until user chooses to exit
    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                go_up();
                break;
            case 2:
                go_down();
                break;
            case 3:
                change_num_floors();
                break;
            case 4:
                printf("\nThank you for using our program!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
        
        if (choice != 4) {
            print_menu();
        }
    } while (choice != 4);
    
    return 0;
}