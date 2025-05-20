//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

int main() {
    int current_floor = 1;
    int selected_floor;
    int elevator_direction = 0; // 0 for stationary, 1 for going up, -1 for going down
    int num_passengers = 0;
    int passengers[MAX_PASSENGERS];
    int i;
    
    printf("Welcome to the Elevator Simulation!\n\n");
    
    while (1) { // Main program loop
        
        // Print current state
        printf("Current Floor: %d\n", current_floor);
        printf("Passengers: %d\n", num_passengers);
        printf("Selected Floor: ");
        if (num_passengers == 0) {
            printf("N/A\n");
        } else {
            for (i = 0; i < num_passengers; i++) {
                printf("%d ", passengers[i]);
            }
            printf("\n");
        }
        
        // Get input
        printf("Enter selected floor (0 for exit): ");
        scanf("%d", &selected_floor);
        
        if (selected_floor == 0) {
            break; // Exit program
        } else if (selected_floor == current_floor) {
            printf("Elevator already at selected floor!\n\n");
        } else if (selected_floor < 1 || selected_floor > MAX_FLOORS) {
            printf("Invalid floor selected!\n\n");
        } else {
            // Determine direction
            if (selected_floor > current_floor) {
                elevator_direction = 1;
            } else {
                elevator_direction = -1;
            }
            
            // Add passenger
            if (num_passengers < MAX_PASSENGERS) {
                passengers[num_passengers] = selected_floor;
                num_passengers++;
                printf("Passenger added!\n\n");
            } else {
                printf("Elevator already has maximum number of passengers!\n\n");
            }
        }
        
        // Move elevator
        if (elevator_direction == 1) {
            current_floor++;
        } else if (elevator_direction == -1) {
            current_floor--;
        }
        
    }
    
    printf("Goodbye!\n");
    return 0;
}