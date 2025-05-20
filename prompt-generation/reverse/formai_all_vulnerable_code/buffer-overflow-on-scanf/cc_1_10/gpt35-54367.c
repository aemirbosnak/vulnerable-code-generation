//FormAI DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>

// Function to move the robot forward
int forward(int distance) {
    printf("Moving the robot forward by %d units!\n", distance);
    return 1;
}

// Function to turn the robot left
int left(int angle) {
    printf("Turning the robot left by %d degrees!\n", angle);
    return 1;
}

// Function to turn the robot right
int right(int angle) {
    printf("Turning the robot right by %d degrees!\n", angle);
    return 1;
}

int main() {
    int command, distance, angle;
    
    while(1) {
        printf("Enter command (1: Forward, 2: Left, 3: Right, 4: Exit): ");
        scanf("%d", &command);
        
        if(command == 1) {
            printf("Enter distance: ");
            scanf("%d", &distance);
            if(forward(distance)) {
                printf("Robot moved forward by %d units\n", distance);
            }
        }
        else if(command == 2) {
            printf("Enter angle: ");
            scanf("%d", &angle);
            if(left(angle)) {
                printf("Robot turned left by %d degrees\n", angle);
            }
        }
        else if(command == 3) {
            printf("Enter angle: ");
            scanf("%d", &angle);
            if(right(angle)) {
                printf("Robot turned right by %d degrees\n", angle);
            }
        }
        else if(command == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid command! Try again...\n");
        }
    }
    
    return 0;
}