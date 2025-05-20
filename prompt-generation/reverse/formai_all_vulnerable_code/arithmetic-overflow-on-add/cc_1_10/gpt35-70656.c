//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 20
#define MIN_FLOORS 5
#define ELEVATOR_CAPACITY 10

void print_status(int floor, int dir, bool people_in, int num_people) {
    printf("Floor: %d | Direction: %s | People in elevator: %s | Number of people: %d\n",
           floor, (dir == 1) ? "Up" : (dir == -1 ? "Down" : "Stopped"), (people_in ? "Yes" : "No"), num_people);
}

int main() {
    // Set up simulation parameters
    int num_floors = rand() % (MAX_FLOORS - MIN_FLOORS + 1) + MIN_FLOORS; // Random number of floors from 5-20
    int elevator_floor = rand() % num_floors + 1; // Starting floor for elevator
    int target_floor = 0;
    int direction = 0; // 1 for up, -1 for down, 0 for stopped
    bool people_inside = false;
    int num_people = 0;

    // Start simulation loop
    while(true) {
        // Print current status
        print_status(elevator_floor, direction, people_inside, num_people);

        // Check if anyone wants to get on the elevator
        if(!people_inside) {
            for(int i = 1; i <= num_floors; i++) {
                if(rand() % 2) { // Random chance of someone wanting to get on
                    printf("Someone wants to get on at floor %d\n", i);
                    if(i > elevator_floor) {
                        direction = 1;
                    }
                    else if(i < elevator_floor) {
                        direction = -1;
                    }
                    target_floor = i;
                    break;
                }
            }
        }

        // Check if anyone wants to get off the elevator
        if(people_inside) {
            if(elevator_floor == target_floor) {
                printf("Someone wants to get off at floor %d\n", elevator_floor);
                people_inside = false;
                num_people = 0;
                target_floor = 0;
                direction = 0;
                continue;
            }
        }

        // Move elevator
        if(direction == 1) { // Going up
            if(elevator_floor != num_floors) {
                elevator_floor++;
            }
            else { // Reached top floor, change direction
                direction = -1;
            }
        }
        else if(direction == -1) { // Going down
            if(elevator_floor != 1) {
                elevator_floor--;
            }
            else { // Reached bottom floor, change direction
                direction = 1;
            }
        }

        // Check if elevator should stop at current floor
        if(target_floor == elevator_floor) {
            printf("Stopping at floor %d\n", elevator_floor);
            people_inside = true;
            num_people = rand() % ELEVATOR_CAPACITY + 1; // Random number of people from 1 to 10
            if(rand() % 2) { // Random chance of going up or down
                direction = 1;
                target_floor = rand() % (num_floors - elevator_floor) + elevator_floor + 1; // Random floor above current floor
            }
            else {
                direction = -1;
                target_floor = rand() % elevator_floor + 1; // Random floor below current floor
            }
        }

        // Pause for 1 second
        sleep(1);
    }

    return 0;
}