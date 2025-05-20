//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 20
#define MAX_WIDTH 30
#define START_POS (MAX_HEIGHT/2) * MAX_WIDTH + (MAX_WIDTH/2)
#define END_POS (MAX_HEIGHT - 1) * MAX_WIDTH + (MAX_WIDTH - 1)

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

void print_maze(int maze[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int maze[MAX_HEIGHT][MAX_WIDTH] = {0};
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    print_maze(maze);

    int robot_x = START_POS, robot_y = START_POS, steps = 0;
    enum Direction dir = UP;

    while (robot_x!= END_POS || robot_y!= END_POS) {
        steps++;

        if (dir == UP && maze[robot_y - 1][robot_x] == 0) {
            robot_y--;
        } else if (dir == DOWN && maze[robot_y + 1][robot_x] == 0) {
            robot_y++;
        } else if (dir == LEFT && maze[robot_y][robot_x - 1] == 0) {
            robot_x--;
        } else if (dir == RIGHT && maze[robot_y][robot_x + 1] == 0) {
            robot_x++;
        }

        if (steps % 4 == 0) {
            dir = (dir + 1) % 4;
        }
    }

    printf("Robot reached the end in %d steps.\n", steps);
    return 0;
}