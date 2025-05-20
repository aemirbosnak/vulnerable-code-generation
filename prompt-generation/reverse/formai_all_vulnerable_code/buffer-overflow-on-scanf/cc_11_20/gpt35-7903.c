//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>

#define NUM_FLOORS 10   // total number of floors
#define NUM_ELEVATORS 3 // total number of elevators

int main() {
    int current_floor[NUM_ELEVATORS] = {1, 1, 1}; // initialize each elevator at the first floor
    int direction[NUM_ELEVATORS] = {1, 1, 1};     // initialize each elevator to move up

    printf("Welcome to the Elevator Simulation!\n");

    while(1) {  // infinite loop
        // display current status of each elevator
        printf("\nElevator Status:\n");
        for(int i=0; i<NUM_ELEVATORS; i++) {
            printf("Elevator %d - Floor %d - Moving ", i+1, current_floor[i]);
            if(direction[i] == 1) {
                printf("Up\n");
            } else {
                printf("Down\n");
            }
        }

        // prompt user for input
        printf("\nEnter a floor number to call an elevator (1 - %d): ", NUM_FLOORS);
        int floor_num;
        scanf("%d", &floor_num);

        if(floor_num < 1 || floor_num > NUM_FLOORS) { // handle invalid input
            printf("Invalid floor number. Please enter a number between 1 and %d.\n", NUM_FLOORS);
            continue;
        }

        // find the closest elevator to the requested floor
        int closest_elevator = 0;
        int min_distance = abs(floor_num - current_floor[closest_elevator]);
        for(int i=1; i<NUM_ELEVATORS; i++) {
            int distance = abs(floor_num - current_floor[i]);
            if(distance < min_distance) {
                closest_elevator = i;
                min_distance = distance;
            }
        }

        // move the selected elevator to the requested floor
        while(current_floor[closest_elevator] != floor_num) {
            current_floor[closest_elevator] += direction[closest_elevator];
            if(current_floor[closest_elevator] == 1 || current_floor[closest_elevator] == NUM_FLOORS) {
                direction[closest_elevator] *= -1; // change direction if elevator reaches top or bottom floor
            }
            printf("\nElevator %d - Floor %d - Moving ", closest_elevator+1, current_floor[closest_elevator]);
            if(direction[closest_elevator] == 1) {
                printf("Up\n");
            } else {
                printf("Down\n");
            }
        }

        printf("\nElevator %d - Floor %d - Doors Opening\n", closest_elevator+1, current_floor[closest_elevator]);
        printf("Enter the elevator and press the desired floor number (1 - %d): ", NUM_FLOORS);
        int desired_floor;
        scanf("%d", &desired_floor);

        if(desired_floor < 1 || desired_floor > NUM_FLOORS) { // handle invalid input
            printf("Invalid floor number. Please enter a number between 1 and %d.\n", NUM_FLOORS);
            continue;
        }

        while(current_floor[closest_elevator] != desired_floor) {
            current_floor[closest_elevator] += direction[closest_elevator];
            if(current_floor[closest_elevator] == 1 || current_floor[closest_elevator] == NUM_FLOORS) {
                direction[closest_elevator] *= -1; // change direction if elevator reaches top or bottom floor
            }
            printf("\nElevator %d - Floor %d - Moving ", closest_elevator+1, current_floor[closest_elevator]);
            if(direction[closest_elevator] == 1) {
                printf("Up\n");
            } else {
                printf("Down\n");
            }
        }

        printf("\nElevator %d - Floor %d - Doors Opening\n", closest_elevator+1, current_floor[closest_elevator]);
        printf("You have arrived at floor %d. Thank you for choosing our elevator service!\n", desired_floor);
    }

    return 0;
}