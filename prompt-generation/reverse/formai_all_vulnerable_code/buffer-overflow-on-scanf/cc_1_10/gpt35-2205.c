//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10

// Define struct for elevator
typedef struct {
    int current_floor;
    int destination;
    bool moving;
} Elevator;

// Function to check if elevator is moving up or down
bool isMovingUp(Elevator e) {
    return e.destination > e.current_floor;
}

// Function to check if elevator is at the top floor
bool isAtTopFloor(Elevator e) {
    return e.current_floor == FLOORS;
}

// Function to check if elevator is at the bottom floor
bool isAtBottomFloor(Elevator e) {
    return e.current_floor == 1;
}

int main() {
    Elevator e = {1, 1, false};
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Elevator Simulation Program!\n\n");
    
    while (true) {
        // Display elevator information
        printf("Current Floor: %d\n", e.current_floor);
        if (e.moving) {
            printf("Destination: %d (Moving %s)\n\n", e.destination, isMovingUp(e) ? "Up" : "Down");
        } else {
            printf("Destination: None (Stopped)\n\n");
        }
        
        // Get input from user
        printf("Enter a floor number (1-%d) or enter 0 to quit: ", FLOORS);
        int floor;
        scanf("%d", &floor);
        
        if (floor == 0) {
            printf("Thank you for using the Elevator Simulation Program!\n");
            break; // Exit the program
        } else if (floor < 1 || floor > FLOORS) {
            printf("Invalid floor number. Please try again.\n\n");
            continue; // Start the loop again
        } else if (floor == e.current_floor) {
            printf("You are already on floor %d!\n\n", floor);
        } else {
            e.destination = floor;
            e.moving = true;
            
            // Send elevator to destination floor
            while (e.current_floor != e.destination) {
                if (isMovingUp(e)) {
                    e.current_floor++;
                } else {
                    e.current_floor--;
                }
                
                printf("Elevator moving to floor %d...\n\n", e.current_floor);
                // Add some delay to simulate elevator movement
                int delay = rand() % 5 + 1;
                for (int i = 0; i < delay; i++) {
                    printf(".");
                    fflush(stdout); // Flush stdout to display the dots immediately
                    sleep(1); // Add 1 second delay
                }
                printf("\n");
            }
            
            printf("You have arrived at your destination floor %d!\n\n", floor);
            e.moving = false;
        }
    }
    
    return 0;
}