//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY '.'
#define WALL '#'
#define ROBOT 'R'
#define GOAL 'G'

typedef struct {
    int x, y;
} Point;

void print_maze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = WALL;
        }
    }
    
    maze[0][0] = ROBOT;
    maze[SIZE - 1][SIZE - 1] = GOAL;
    
    print_maze(maze);
    
    Point robot = {0, 0};
    Point goal = {SIZE - 1, SIZE - 1};
    
    while (robot.x!= goal.x || robot.y!= goal.y) {
        char command;
        printf("Enter command (L, R, U, D): ");
        scanf("%c", &command);
        
        switch (command) {
            case 'L':
                if (robot.x > 0 && maze[robot.x - 1][robot.y]!= WALL) {
                    robot.x--;
                }
                break;
            case 'R':
                if (robot.x < SIZE - 1 && maze[robot.x + 1][robot.y]!= WALL) {
                    robot.x++;
                }
                break;
            case 'U':
                if (robot.y > 0 && maze[robot.x][robot.y - 1]!= WALL) {
                    robot.y--;
                }
                break;
            case 'D':
                if (robot.y < SIZE - 1 && maze[robot.x][robot.y + 1]!= WALL) {
                    robot.y++;
                }
                break;
            default:
                printf("Invalid command\n");
        }
        
        print_maze(maze);
    }
    
    printf("Congratulations! You have reached the goal!\n");
    
    return 0;
}