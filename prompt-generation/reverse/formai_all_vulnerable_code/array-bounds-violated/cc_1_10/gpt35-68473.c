//FormAI DATASET v1.0 Category: Robot movement control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVES 1000

typedef struct {
    int x;
    int y;
    char direction;
} Robot;

void execute_move(Robot *robot, char move) {
    if (move == 'F') {
        switch (robot->direction) {
            case 'N':
                robot->y += 1;
                break;
            case 'E':
                robot->x += 1;
                break;
            case 'S':
                robot->y -= 1;
                break;
            case 'W':
                robot->x -= 1;
                break;
        }
    } else if (move == 'L') {
        switch (robot->direction) {
            case 'N':
                robot->direction = 'W';
                break;
            case 'E':
                robot->direction = 'N';
                break;
            case 'S':
                robot->direction = 'E';
                break;
            case 'W':
                robot->direction = 'S';
                break;
        }
    } else if (move == 'R') {
        switch (robot->direction) {
            case 'N':
                robot->direction = 'E';
                break;
            case 'E':
                robot->direction = 'S';
                break;
            case 'S':
                robot->direction = 'W';
                break;
            case 'W':
                robot->direction = 'N';
                break;
        }
    }
}

int main() {
    Robot robot = {0, 0, 'N'};
    char moves[MAX_MOVES];
    
    printf("Enter robot commands: ");
    fgets(moves, MAX_MOVES, stdin);
    int n = strlen(moves);
    if (moves[n-1] == '\n') {
        moves[n-1] = '\0';
    }
    
    for (int i = 0; i < strlen(moves); i++) {
        execute_move(&robot, moves[i]);
    }
    
    printf("Final position: (%d, %d, %c)\n", robot.x, robot.y, robot.direction);
    
    return 0;
}