//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_FLOORS 10    // Define the number of floors
#define NUM_ELEVATORS 3  // Define the number of elevators

typedef struct elevator {
    int current_floor;
    bool is_moving;
    bool is_door_open;
} elevator_t;

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time
    elevator_t elevators[NUM_ELEVATORS];
    int floor_request;
    int elevator_choice;
    
    // Initialize all elevators to the first floor with closed doors
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 1;
        elevators[i].is_moving = false;
        elevators[i].is_door_open = false;
    }
    
    // Main loop
    while (true) {
        // Print out the current state of all elevators
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d is on floor %d, ", i + 1, elevators[i].current_floor);
            if (elevators[i].is_moving) {
                printf("is moving, ");
            } else {
                printf("is stationary, ");
            }
            if (elevators[i].is_door_open) {
                printf("and the door is open.\n");
            } else {
                printf("and the door is closed.\n");
            }
        }
        
        // Get the user's floor request
        printf("Which floor would you like to go to? ");
        scanf("%d", &floor_request);
        if (floor_request < 1 || floor_request > NUM_FLOORS) {
            printf("Invalid floor request.\n");
            continue;
        }
        
        // Determine which elevator to send based on proximity
        int closest_elevator = 0;
        int closest_distance = abs(elevators[0].current_floor - floor_request);
        for (int i = 1; i < NUM_ELEVATORS; i++) {
            int distance = abs(elevators[i].current_floor - floor_request);
            if (distance < closest_distance) {
                closest_elevator = i;
                closest_distance = distance;
            }
        }
        
        // Send the chosen elevator to the requested floor
        elevators[closest_elevator].is_moving = true;
        printf("Sending elevator %d to floor %d...\n", closest_elevator + 1, floor_request);
        while (elevators[closest_elevator].current_floor != floor_request) {
            if (elevators[closest_elevator].current_floor < floor_request) {
                elevators[closest_elevator].current_floor++;
            } else {
                elevators[closest_elevator].current_floor--;
            }
            printf("Elevator %d is now on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
            // Randomly open and close the elevator door while moving
            if (rand() % 10 == 0) {
                elevators[closest_elevator].is_door_open = true;
                printf("Elevator %d door opened on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
            }
            if (rand() % 10 == 0) {
                elevators[closest_elevator].is_door_open = false;
                printf("Elevator %d door closed on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
            }
            // Pause for a moment to simulate moving between floors
            printf("...\n");
            sleep(1);
        }
        elevators[closest_elevator].is_moving = false;
        elevators[closest_elevator].is_door_open = true;
        printf("Elevator %d has arrived at floor %d and the door has opened.\n", closest_elevator + 1, floor_request);
        printf("Would you like to enter this elevator? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("Which floor would you like to go to? ");
            scanf("%d", &floor_request);
            if (floor_request < 1 || floor_request > NUM_FLOORS) {
                printf("Invalid floor request.\n");
                continue;
            }
            elevators[closest_elevator].is_door_open = false;
            printf("Closing door of elevator %d...\n", closest_elevator + 1);
            while (!elevators[closest_elevator].is_door_open) {
                printf("...\n");
                sleep(1);
                // Randomly open and close the elevator door while waiting
                if (rand() % 10 == 0) {
                    elevators[closest_elevator].is_door_open = true;
                    printf("Elevator %d door opened on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
                }
            }
            while (elevators[closest_elevator].current_floor != floor_request) {
                if (elevators[closest_elevator].current_floor < floor_request) {
                    elevators[closest_elevator].current_floor++;
                } else {
                    elevators[closest_elevator].current_floor--;
                }
                printf("Elevator %d is now on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
                // Randomly open and close the elevator door while moving
                if (rand() % 10 == 0) {
                    elevators[closest_elevator].is_door_open = true;
                    printf("Elevator %d door opened on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
                }
                if (rand() % 10 == 0) {
                    elevators[closest_elevator].is_door_open = false;
                    printf("Elevator %d door closed on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
                }
                // Pause for a moment to simulate moving between floors
                printf("...\n");
                sleep(1);
            }
            elevators[closest_elevator].is_door_open = true;
            printf("Elevator %d has arrived at floor %d and the door has opened.\n", closest_elevator + 1, floor_request);
        } else {
            elevators[closest_elevator].is_door_open = false;
            printf("Closing door of elevator %d...\n", closest_elevator + 1);
            while (!elevators[closest_elevator].is_door_open) {
                printf("...\n");
                sleep(1);
                // Randomly open and close the elevator door while waiting
                if (rand() % 10 == 0) {
                    elevators[closest_elevator].is_door_open = true;
                    printf("Elevator %d door opened on floor %d.\n", closest_elevator + 1, elevators[closest_elevator].current_floor);
                }
            }
        }
    }
    
    return 0;
}