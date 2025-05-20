//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int floor = 1; 
    int dir = 1; 
    int max_floor = 5; 
    int min_floor = 1;
    int num_people = 0; 

    printf("Welcome to the Fun Elevator Simulator!\n\n");

    while (1) {
        printf("You are on floor %d. There are %d people in the elevator.\n", floor, num_people); 
        printf("Would you like to go up or down? (1 for up, -1 for down): "); 

        scanf("%d", &dir); 

        if (dir < -1 || dir > 1) {
            printf("Invalid direction. Please choose either 1 or -1.\n\n"); 
            continue; 
        }

        floor = floor + dir; 

        if (floor > max_floor) {
            floor = max_floor; 
        }

        if (floor < min_floor) {
            floor = min_floor; 
        }

        printf("Ding! The elevator has arrived at floor %d.\n", floor); 

        printf("Would you like to get on the elevator? (1 for yes, 0 for no): "); 

        int choice; 
        scanf("%d", &choice); 

        if (choice == 1) {
            num_people = num_people + 1; 
            printf("You have boarded the elevator! There are now %d people in the elevator.\n\n", num_people); 
        } else {
            printf("You have chosen not to board the elevator. The elevator will continue to the next floor.\n\n"); 
        }

        printf("Would you like to get off the elevator? (1 for yes, 0 for no): ");
        scanf("%d", &choice); 

        if (choice == 1) {
            num_people = num_people - 1; 
            printf("You have left the elevator. There are now %d people in the elevator.\n\n", num_people); 
        } else {
            printf("You have chosen not to leave the elevator. The elevator will continue to the next floor.\n\n"); 
        }
    }

    return 0; 
}