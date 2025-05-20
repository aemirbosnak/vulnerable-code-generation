//FormAI DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 1
#define RIGHT -1

int xPos, yPos;
int facing; // 1 for North, -1 for South
bool on = true;

void moveForward() {
    if(facing == 1) yPos++;
    else yPos--;
    printf("Robot moved forward to (%d,%d)\n", xPos, yPos);
}

void moveBackward() {
    if(facing == 1) yPos--;
    else yPos++;
    printf("Robot moved backward to (%d,%d)\n", xPos, yPos);
}

void turnLeft() {
    facing *= LEFT;
    printf("Robot turned left to face %s\n", facing == 1 ? "North" : "South");
}

void turnRight() {
    facing *= RIGHT;
    printf("Robot turned right to face %s\n", facing == 1 ? "North" : "South");
}

int main() {
    xPos = yPos = 0;
    facing = 1; // Start facing North
    
    while(on) {
        int choice;
        printf("-------------------\n");
        printf("Robot at (%d,%d), facing %s\n", xPos, yPos, facing == 1 ? "North" : "South");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Turn off\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                moveForward();
                break;
            case 2:
                moveBackward();
                break;
            case 3:
                turnLeft();
                break;
            case 4:
                turnRight();
                break;
            case 5:
                printf("Robot turned off\n");
                on = false;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}