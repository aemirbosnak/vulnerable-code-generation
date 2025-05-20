//FormAI DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define movement options
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
} MoveOption;

// Define robot struct
typedef struct {
    int x;
    int y;
    MoveOption current_move;
    bool is_moving;
} Robot;

// Function to move the robot
void moveRobot(Robot *robot) {
    switch(robot->current_move) {
        case FORWARD:
            robot->y += 1;
            break;
        case BACKWARD:
            robot->y -= 1;
            break;
        case LEFT:
            robot->x -= 1;
            break;
        case RIGHT:
            robot->x += 1;
            break;
        case STOP:
            robot->is_moving = false;
            break;
        default:
            printf("Invalid move option!\n");
            break;
    }
}

int main() {
    // Initialize robot struct
    Robot robot = {
        .x = 0,
        .y = 0,
        .current_move = STOP,
        .is_moving = false
    };
    
    // Run a loop to take user input and move the robot accordingly
    while(true) {
        char input;
        printf("Enter 'f' for forward, 'b' for backward, 'l' for left, 'r' for right, 's' for stop: ");
        scanf("%c", &input);
        
        switch(input) {
            case 'f':
                robot.current_move = FORWARD;
                break;
            case 'b':
                robot.current_move = BACKWARD;
                break;
            case 'l':
                robot.current_move = LEFT;
                break;
            case 'r':
                robot.current_move = RIGHT;
                break;
            case 's':
                robot.current_move = STOP;
                break;
            default:
                printf("Invalid input!\n");
                continue;
        }
        
        robot.is_moving = true;
        
        while(robot.is_moving) {
            moveRobot(&robot);
            printf("Robot position: (%d, %d)\n", robot.x, robot.y);
        }
    }
    
    return 0;
}