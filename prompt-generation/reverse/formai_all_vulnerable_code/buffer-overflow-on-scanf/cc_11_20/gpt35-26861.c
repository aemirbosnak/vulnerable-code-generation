//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10 // Maximum number of floors in the building
#define MAX_ELEVATORS 3 // Maximum number of elevators in the building

/* Elevator struct */
typedef struct elevator {
    int current_floor; // Current floor of the elevator
    int target_floor; // Floor the elevator is moving to
    int occupied; // Indicates whether the elevator is occupied or not (1 = occupied, 0 = unoccupied)
} Elevator;

/* Function to simulate the elevator moving between floors */
void moveElevator(Elevator* e) {
    if (e->target_floor > e->current_floor) {
        printf("Elevator moving up...\n");
        while (e->current_floor < e->target_floor) {
            e->current_floor++;
            printf("Elevator at floor %d\n", e->current_floor);
        }
    }
    else if (e->target_floor < e->current_floor) {
        printf("Elevator moving down...\n");
        while (e->current_floor > e->target_floor) {
            e->current_floor--;
            printf("Elevator at floor %d\n", e->current_floor);
        }
    }
    printf("Elevator has reached its destination at floor %d\n", e->current_floor);
}

int main() {
    Elevator elevators[MAX_ELEVATORS]; // Array of elevators
    int selected_elevator = -1; // Currently selected elevator (initialized to -1 to indicate no elevator selected)
    int num_floors; // Number of floors in the building
    int num_elevators; // Number of elevators in the building
    int i, j; // Loop variables
    
    /* Get the number of floors in the building */
    do {
        printf("Enter the number of floors in the building (max %d): ", MAX_FLOORS);
        scanf("%d", &num_floors);
    } while (num_floors < 1 || num_floors > MAX_FLOORS);
    
    /* Get the number of elevators in the building */
    do {
        printf("Enter the number of elevators (max %d): ", MAX_ELEVATORS);
        scanf("%d", &num_elevators);
    } while (num_elevators < 1 || num_elevators > MAX_ELEVATORS);
    
    /* Initialize the elevators */
    for (i = 0; i < num_elevators; i++) {
        elevators[i].current_floor = 0;
        elevators[i].target_floor = 0;
        elevators[i].occupied = 0;
    }
    
    /* Main loop */
    while (1) {
        /* Print the current status of the elevators */
        printf("\nCurrent elevator status:\n");
        for (i = 0; i < num_elevators; i++) {
            printf("Elevator %d: ", i+1);
            if (elevators[i].occupied) {
                printf("occupied (moving from floor %d to floor %d)", elevators[i].current_floor, elevators[i].target_floor);
            }
            else {
                printf("unoccupied (at floor %d)", elevators[i].current_floor);
            }
            printf("\n");
        }
        
        /* Get the user's choice of action */
        printf("\nChoose an action:\n");
        printf("1. Call elevator\n");
        printf("2. Select elevator\n");
        printf("3. Move elevator\n");
        printf("4. Exit program\n");
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
        case 1: // Call elevator
            printf("\nCall elevator to which floor? (1-%d): ", num_floors);
            int floor;
            scanf("%d", &floor);
            
            /* Find the nearest unoccupied elevator */
            int min_distance = num_floors; // Initialize to maximum possible distance
            for (i = 0; i < num_elevators; i++) {
                if (!elevators[i].occupied) {
                    int distance = abs(floor - elevators[i].current_floor);
                    if (distance < min_distance) {
                        selected_elevator = i;
                        min_distance = distance;
                    }
                }
            }
            
            if (selected_elevator == -1) {
                printf("All elevators are occupied at the moment. Please try again later.\n");
            }
            else {
                printf("Elevator %d has been selected to move to floor %d\n", selected_elevator+1, floor);
                elevators[selected_elevator].target_floor = floor;
                elevators[selected_elevator].occupied = 1;
            }
            break;
        case 2: // Select elevator
            printf("\nSelect which elevator? (1-%d): ", num_elevators);
            int elevator;
            scanf("%d", &elevator);
            if (elevator < 1 || elevator > num_elevators) {
                printf("Invalid elevator number. Please try again.\n");
            }
            else if (!elevators[elevator-1].occupied) {
                printf("Elevator %d is currently unoccupied and cannot be selected.\n", elevator);
            }
            else {
                selected_elevator = elevator - 1;
                printf("Elevator %d has been selected.\n", elevator);
            }
            break;
        case 3: // Move elevator
            if (selected_elevator == -1) {
                printf("\nNo elevator selected. Please select an elevator first.\n");
            }
            else if (!elevators[selected_elevator].occupied) {
                printf("\nSelected elevator is unoccupied. Please select an occupied elevator.\n");
            }
            else {
                moveElevator(&elevators[selected_elevator]);
                elevators[selected_elevator].occupied = 0;
                selected_elevator = -1;
            }
            break;
        case 4: // Exit program
            printf("\nExiting program...\n");
            return 0;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
}