//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>

// function to take input from the user for controlling the drone
void take_input(int *direction, int *speed) {
    printf("\nEnter the direction you want to move the drone (1 - Up, 2 - Down, 3 - Left, 4 - Right): ");
    scanf("%d", direction);
    printf("\nEnter the speed at which you want to move the drone (0 - 10): ");
    scanf("%d", speed);
}

// function to move the drone up
void up(int speed) {
    printf("\nMoving the drone up with speed %d", speed);
}

// function to move the drone down
void down(int speed) {
    printf("\nMoving the drone down with speed %d", speed);
}

// function to move the drone left
void left(int speed) {
    printf("\nMoving the drone left with speed %d", speed);
}

// function to move the drone right
void right(int speed) {
    printf("\nMoving the drone right with speed %d", speed);
}

// main function
int main() {
    int direction, speed;
    
    // infinite loop for continuous control of the drone
    while(1) {
        take_input(&direction, &speed);
        
        // switch statement to perform the appropriate action based on the user input
        switch(direction) {
            case 1:
                up(speed);
                break;
            case 2:
                down(speed);
                break;
            case 3:
                left(speed);
                break;
            case 4:
                right(speed);
                break;
            default:
                printf("\nInvalid direction input! Please try again.");
        }
    }
    
    return 0;
}