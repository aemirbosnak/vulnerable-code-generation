//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 8

int current_floor = 0;  // The current floor of the elevator
int current_passengers = 0; // The number of passengers currently in the elevator
int target_floor = 0;  // The floor the elevator is currently heading towards
bool going_up = true;  // If the elevator is going up, set to true

// Prototype for our function that will move the elevator
void move_elevator(void);

int main(void) {
    // Delcare variables
    char input;
    int passengers_waiting[MAX_FLOORS] = {0};
    bool program_running = true;
    
    // Start while loop so the program runs continuously
    while (program_running) {
        printf("CURRENT FLOOR: %d\n", current_floor);  // Print current floor
        printf("TARGET FLOOR: %d\n", target_floor);   // Print target floor
        
        // Print out the number of passengers waiting on each floor
        for (int i = 0; i < MAX_FLOORS; i++) {
            printf("PASSENGERS WAITING ON FLOOR %d: %d\n", i, passengers_waiting[i]);
        }
        
        // Prompt user to enter passengers
        printf("ENTER THE NUMBER OF PASSENGERS TO ADD TO THE ELEVATOR: ");
        scanf(" %c", &input);
        
        // Handle user input
        switch(input) {
            case '1':
                // Add one passenger to the elevator
                if (current_passengers < ELEVATOR_CAPACITY) {
                    current_passengers++;
                } else {
                    printf("THE ELEVATOR IS FULL!\n");
                }
                break;
            case '2':
                // Add five passengers to the elevator
                if (current_passengers + 5 <= ELEVATOR_CAPACITY) {
                    current_passengers += 5;
                } else {
                    printf("THE ELEVATOR IS FULL!\n");
                }
                break;
            case 'q':
                // Quit the program
                printf("GOODBYE!\n");
                program_running = false;
                break;
            default:
                printf("INVALID INPUT!\n");
                break;
        }
        
        // Move the elevator
        move_elevator();
        
        // Add passengers to the floor the elevator just arrived at
        passengers_waiting[current_floor] += current_passengers;
        current_passengers = 0;
    }
    
    // Return success
    return 0;
}

void move_elevator(void) {
    // If elevator is going up, check if it has reached the top floor
    if (going_up) {
        if (current_floor == MAX_FLOORS - 1) {
            going_up = false;
            target_floor--;
        } else {
            target_floor++;
        }
    // If elevator is going down, check if it has reached the bottom floor
    } else {
        if (current_floor == 0) {
            going_up = true;
            target_floor++;
        } else {
            target_floor--;
        }
    }
    
    // Update current floor
    current_floor = target_floor;
}