//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
bool check_floor(int current_floor, int target_floor, bool going_up);
void simulate_elevator(int current_floor, int target_floor, bool going_up);

int main()
{
    // initialize variables
    int current_floor = 1;
    int target_floor;
    bool going_up;

    // get user input for target floor
    printf("Welcome to the Elevator Simulator! \n");
    printf("What floor would you like to go to? (1-10): ");
    scanf("%d", &target_floor);

    // ask user for direction
    if (target_floor > current_floor) {
        printf("Going up! \n");
        going_up = true;
    } else {
        printf("Going down! \n");
        going_up = false;
    }

    // simulate elevator
    simulate_elevator(current_floor, target_floor, going_up);

    printf("Arrived at floor %d! Have a nice day. \n", target_floor);

    return 0;
}

// function to check if elevator needs to stop at floor
bool check_floor(int current_floor, int target_floor, bool going_up)
{
    if (going_up && current_floor <= target_floor) {
        return true;
    } else if (!going_up && current_floor >= target_floor) {
        return true;
    } else {
        return false;
    }
}

// function to simulate elevator movement between floors
void simulate_elevator(int current_floor, int target_floor, bool going_up)
{
    printf("Elevator is on floor %d! \n", current_floor);

    while (current_floor != target_floor) {
        if (check_floor(current_floor, target_floor, going_up)) {
            printf("Stopping at floor %d. \n", current_floor);
        }

        if (going_up) {
            current_floor++;
        } else {
            current_floor--;
        }
    }
}