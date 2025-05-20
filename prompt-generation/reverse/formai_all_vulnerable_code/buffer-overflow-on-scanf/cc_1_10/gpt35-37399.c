//FormAI DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants to represent Robot movement
#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3

// Define Robot structure
typedef struct {
    int x;
    int y;
} Robot;

// Define function to move Robot
void move(Robot *robot, int direction) {
    switch (direction) {
        case FORWARD:
            robot->y++;
            break;
        case BACKWARD:
            robot->y--;
            break;
        case LEFT:
            robot->x--;
            break;
        case RIGHT:
            robot->x++;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Create Robot at starting position (0,0)
    Robot robot = {0, 0};
    
    // Get user input for number of moves
    int num_moves;
    printf("How many moves should the Robot make? ");
    scanf("%d", &num_moves);
    
    // Create moves array to hold num_moves random directions
    int moves[num_moves];
    for (int i = 0; i < num_moves; i++) {
        moves[i] = rand() % 4;  // Assign random direction
    }
    
    // Move Robot based on moves array
    printf("Starting position: (%d,%d)\n", robot.x, robot.y);
    for (int i = 0; i < num_moves; i++) {
        move(&robot, moves[i]);
        printf("Move %d: (%d,%d)\n", i+1, robot.x, robot.y);
    }
    
    return 0;
}