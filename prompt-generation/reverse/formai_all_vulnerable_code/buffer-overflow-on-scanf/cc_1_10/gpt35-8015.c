//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: intelligent
#include <stdio.h>

#define MAX_ELEVATOR_FLOORS 10
#define ELEVATOR_SPEED 500 //milliseconds per floor
#define DOOR_OPEN_DELAY 2000 //milliseconds
#define DOOR_CLOSE_DELAY 1000 //milliseconds

char directions[2][10] = {"up", "down"};
int current_floor = 1; //initial floor
int target_floor;

void moveToTargetFloor(int target) {
    if (target < 1 || target > MAX_ELEVATOR_FLOORS) {
        printf("Invalid floor number! Please select a floor between 1 and %d.\n", MAX_ELEVATOR_FLOORS);
        return;
    }
    
    target_floor = target;
    int diff = target_floor - current_floor;
    int time_taken = diff * ELEVATOR_SPEED;
    
    if (diff == 0) {
        printf("You are already on floor %d. Choose another floor.\n", current_floor);
        return;
    } else if (diff > 0) {
        printf("Going %s to floor %d...\n", directions[0], target_floor);
    } else {
        printf("Going %s to floor %d...\n", directions[1], target_floor);
    }
    
    // simulate the elevator movement
    for (int i = 1; i <= diff; i++) {
        current_floor += (diff > 0 ? 1 : -1);
        printf("Floor %d\n", current_floor);
        usleep(ELEVATOR_SPEED * 1000);
    }
    
    // open the door and wait for some time
    printf("Doors opening...\n");
    usleep(DOOR_OPEN_DELAY * 1000);
    printf("Doors closing...\n");
    usleep(DOOR_CLOSE_DELAY * 1000);
    
    printf("Arrived at floor %d.\n", target_floor);
    target_floor = 0;
}

int main() {
    int floor_num;
    
    printf("Welcome to the elevator! You are currently on floor %d.\n", current_floor);
    
    while (1) {
        printf("Please enter the floor number (1 to %d) you want to go to or press 'q' to exit: ", MAX_ELEVATOR_FLOORS);
        char input[10];
        scanf("%s", input);
        
        if (input[0] == 'q') {
            break;
        } else {
            floor_num = atoi(input);
            moveToTargetFloor(floor_num);
        }
    }
    
    printf("Exiting the elevator. Thank you for using it!\n");
    return 0;
}