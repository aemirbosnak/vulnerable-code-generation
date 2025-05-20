//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 5

int current_floor = 1;
bool elevator_moving = false;

void print_building(int);
void print_elevator(int);
void move_elevator(int);

int main() {

    int num_floors;

    // Get number of floors from user and ensure it is within limits
    do {
        printf("Enter number of floors in the building (between %d and %d): ", MIN_FLOORS, MAX_FLOORS);
        scanf("%d", &num_floors);
        fflush(stdin);  // Clear input buffer
    } while(num_floors < MIN_FLOORS || num_floors > MAX_FLOORS);

    // Seed random number generator
    srand(time(NULL));

    // Run elevator simulation until user exits
    int choice;
    do {
        printf("\nCurrent Floor: %d\n", current_floor);
        print_building(num_floors);

        printf("Enter 1 to move elevator, 2 to exit: ");
        scanf("%d", &choice);
        fflush(stdin);  // Clear input buffer

        if(choice == 1) {
            int target_floor;
            do {
                printf("Enter target floor (between 1 and %d): ", num_floors);
                scanf("%d", &target_floor);
                fflush(stdin);  // Clear input buffer
            } while(target_floor < 1 || target_floor > num_floors);

            // Check if elevator needs to move
            if(target_floor != current_floor) {
                move_elevator(target_floor);
            } else {
                printf("Elevator is already on target floor\n");
            }
        } else if(choice != 2) {
            printf("Invalid choice\n");
        }
    } while(choice != 2);

    return 0;
}

void print_building(int num_floors) {
    for(int i=num_floors; i>=1; i--) {
        print_elevator(i);
        printf("\n");
    }
}

void print_elevator(int floor) {
    printf("+");
    if(floor == current_floor && elevator_moving) {
        printf("*");
    } else {
        printf(" ");
    }
    printf("+");
}

void move_elevator(int target_floor) {
    printf("Elevator moving from floor %d to floor %d\n", current_floor, target_floor);

    // Randomly determine time taken to move elevator
    int time_taken = rand() % 5 + 1; // Random number between 1 and 5
    for(int i=1; i<=time_taken; i++) {
        printf(".");
        fflush(stdout);  // Ensure dots are printed immediately
        sleep(1);
    }

    elevator_moving = false;
    current_floor = target_floor;
    printf("\nElevator has arrived at floor %d\n", current_floor);
}