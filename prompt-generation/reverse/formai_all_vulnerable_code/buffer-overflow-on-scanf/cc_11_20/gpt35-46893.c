//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FLOORS 10

int main(void)
{
    int elevator_pos = 0;
    int elevator_dir = 0;
    int current_floor = 0;
    int target_floor = 0;
    srand(time(0));
 
    printf("Welcome to the Happy Elevator Simulation!\n\n");

    while (1) {
        printf("Elevator is at floor %d.\n", current_floor);
 
        if (elevator_pos == current_floor) {
            printf("Elevator doors are now opening. Please enter.\n");
            elevator_dir = 0;
            scanf("%d", &target_floor);
            printf("Going to floor %d\n", target_floor);
            if (target_floor > current_floor) {
                elevator_dir = 1;
            } else if (target_floor < current_floor) {
                elevator_dir = -1;
            }
        }
 
        if (elevator_dir == 1) {
            current_floor++;
            elevator_pos++;
        } else if (elevator_dir == -1) {
            current_floor--;
            elevator_pos--;
        }
 
        if (current_floor == target_floor) {
            printf("Elevator doors are now opening. Please exit.\n");
            elevator_dir = 0;

            // Wait for a new destination
            int random_floor = rand() % FLOORS;
            while (random_floor == current_floor) {
                random_floor = rand() % FLOORS;
            }
            printf("Please choose a new destination. Going to floor %d\n", random_floor);
            if (random_floor > current_floor) {
                elevator_dir = 1;
            } else if (random_floor < current_floor) {
                elevator_dir = -1;
            }
            target_floor = random_floor;
        }
    }
    return 0;
}