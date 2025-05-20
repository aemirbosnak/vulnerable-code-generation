//FormAI DATASET v1.0 Category: Robot movement control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function declaration */
void move_forward();
void move_backward();
void move_left();
void move_right();
void stop_moving();
bool verify_direction(char direction);

/* Main function */
int main() {
    char movement; // Variable to store the direction of movement
    printf("Enter the direction of robot movement (f/b/l/r): ");
    scanf("%c", &movement);
    
    // Verify the direction of movement and call the respective function
    if(verify_direction(movement)) {
        switch(movement) {
            case 'f':
                move_forward();
                break;
            case 'b':
                move_backward();
                break;
            case 'l':
                move_left();
                break;
            case 'r':
                move_right();
                break;
            default:
                printf("Invalid direction!\n");
                stop_moving();
                break;
        }
    } else {
        printf("Invalid direction!\n");
        stop_moving();
    }
    return 0;
}

/* Function definition */
void move_forward() {
    printf("Moving forward...");
}

void move_backward() {
    printf("Moving backward...");
}

void move_left() {
    printf("Moving left...");
}

void move_right() {
    printf("Moving right...");
}

void stop_moving() {
    printf("Stopping the robot movement...");
}

bool verify_direction(char direction) {
    char valid_directions[] = {'f', 'b', 'l', 'r'}; // Valid directions
    
    for(int i=0; i<4; i++) {
        if(valid_directions[i] == direction) {
            return true;
        }
    }
    return false;
}