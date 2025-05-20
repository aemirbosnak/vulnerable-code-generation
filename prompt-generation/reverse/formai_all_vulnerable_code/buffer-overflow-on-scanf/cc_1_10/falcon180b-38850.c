//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define ROBOT_SIZE 3

int maze[SIZE][SIZE];
int robot_x, robot_y;

void generate_maze() {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    robot_x = 0;
    robot_y = 0;
}

void draw_maze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
    printf("Robot: ");
    for (int i = 0; i < ROBOT_SIZE; i++) {
        printf("# ");
    }
    printf("\n");
}

void move_robot(int dx, int dy) {
    int new_x = robot_x + dx;
    int new_y = robot_y + dy;
    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE && maze[new_x][new_y] == 0) {
        robot_x = new_x;
        robot_y = new_y;
    }
}

int main() {
    generate_maze();
    int running = 1;
    while (running) {
        draw_maze();
        char command;
        printf("Enter command (w/a/s/d): ");
        scanf(" %c", &command);
        switch (command) {
            case 'w':
                move_robot(0, -1);
                break;
            case 'a':
                move_robot(-1, 0);
                break;
            case's':
                move_robot(0, 1);
                break;
            case 'd':
                move_robot(1, 0);
                break;
            case 'q':
                running = 0;
                break;
            default:
                printf("Invalid command\n");
        }
    }
    return 0;
}