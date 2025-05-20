//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 100
#define MAX_ROBOTS 10

typedef struct {
    int x, y;
    int moves_left;
    int direction;
} Robot;

void move_robot(Robot *r) {
    if (r->direction == 0) {
        r->x++;
    } else if (r->direction == 1) {
        r->y++;
    } else if (r->direction == 2) {
        r->x--;
    } else {
        r->y--;
    }
    r->moves_left--;
}

int check_collision(int x, int y, Robot robots[], int num_robots) {
    for (int i = 0; i < num_robots; i++) {
        if (robots[i].x == x && robots[i].y == y) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int num_robots;
    printf("Enter the number of robots: ");
    scanf("%d", &num_robots);

    Robot robots[MAX_ROBOTS];
    for (int i = 0; i < num_robots; i++) {
        robots[i].x = rand() % 10;
        robots[i].y = rand() % 10;
        robots[i].moves_left = rand() % 50 + 1;
        robots[i].direction = rand() % 4;
    }

    int moves = 0;
    while (moves < MAX_MOVES) {
        for (int i = 0; i < num_robots; i++) {
            if (robots[i].moves_left > 0) {
                int dx = 0, dy = 0;
                if (robots[i].direction == 0) {
                    dx = 1;
                } else if (robots[i].direction == 1) {
                    dy = 1;
                } else if (robots[i].direction == 2) {
                    dx = -1;
                } else {
                    dy = -1;
                }

                int new_x = robots[i].x + dx;
                int new_y = robots[i].y + dy;

                if (check_collision(new_x, new_y, robots, num_robots)) {
                    robots[i].moves_left--;
                } else {
                    robots[i].x = new_x;
                    robots[i].y = new_y;
                    moves++;
                }
            }
        }
    }

    printf("Total moves: %d\n", moves);

    return 0;
}