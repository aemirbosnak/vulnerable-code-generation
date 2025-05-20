//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Create a list of floors
    int floors[] = {1, 2, 3, 4, 5};
    
    // Create a list of passengers
    int passengers[] = {2, 3, 5, 2, 1};
    
    // Set the current floor to the first floor
    int current_floor = 1;
    
    // Set the current elevator position to the first floor
    int elevator_position = 0;
    
    // Loop until all passengers have left the elevator
    while (passengers[0] > 0) {
        // Print the current floor and elevator position
        printf("Current floor: %d\n", current_floor);
        printf("Current elevator position: %d\n", elevator_position);
        
        // Move the elevator to the next floor
        if (elevator_position == (sizeof(floors) - 1)) {
            // If the elevator is at the top floor, wait for a passenger to arrive
            if (passengers[0] == 0) {
                printf("Waiting for a passenger to arrive...\n");
                sleep(1);
            } else {
                // If the elevator is not at the top floor, move it up
                elevator_position++;
            }
        } else {
            // If the elevator is not at the top floor, move it down
            elevator_position--;
        }
        
        // Move the elevator to the passenger's floor
        while (elevator_position!= passengers[0]) {
            printf("Moving to floor %d...\n", floors[elevator_position]);
            sleep(1);
            elevator_position++;
        }
        
        // Open the elevator doors
        printf("Opening doors...\n");
        
        // Move the passenger to the elevator
        passengers[0]--;
        printf("Passenger moved to elevator...\n");
        
        // Close the elevator doors
        printf("Closing doors...\n");
    }
    
    // Print a message indicating that all passengers have left the elevator
    printf("All passengers have left the elevator!\n");
    
    // Return a success status code
    return 0;
}