//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>

// function to move 1 unit forward
void move_forward(int steps) {
    if (steps <= 0) { // base case
        return;
    }
    printf("Moving forward 1 unit...\n");
    move_forward(steps - 1); // recursive call
}

// function to turn robot to the left by 90 degrees
void turn_left(int angle) {
    if (angle <= 0) { // base case
        return;
    }
    printf("Turning left 90 degrees...\n");
    turn_left(angle - 90); // recursive call
}

// function to turn robot to the right by 90 degrees
void turn_right(int angle) {
    if (angle <= 0) { // base case
        return;
    }
    printf("Turning right 90 degrees...\n");
    turn_right(angle - 90); // recursive call
}

// function to move the robot in a recursive pattern
void move_in_pattern(int n) {
    if (n <= 0) { // base case
        return;
    }
    move_forward(n); // move forward n units
    turn_left(90);   // turn left by 90 degrees
    move_in_pattern(n-1); // recursive call with n-1 units
    turn_right(180);  // turn right by 180 degrees
    move_in_pattern(n-1); // recursive call with n-1 units
    turn_left(90);   // turn left by 90 degrees
    move_forward(n); // move forward n units
}

// main function
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Moving robot in a recursive pattern...\n");
    move_in_pattern(n);
    printf("Done!\n");
    return 0;
}