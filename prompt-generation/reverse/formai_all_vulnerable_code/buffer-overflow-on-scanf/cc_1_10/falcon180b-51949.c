//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROBOTS 10
#define MAX_COMMANDS 50

// Robot structure
typedef struct {
    int x, y;
    int dir; // 0 = up, 1 = right, 2 = down, 3 = left
    int speed;
} Robot;

// Command structure
typedef struct {
    int type; // 0 = move, 1 = turn
    int data; // for move: distance in pixels, for turn: angle in degrees
} Command;

// Global variables
Robot robots[MAX_ROBOTS];
Command commands[MAX_COMMANDS];
int num_robots, num_commands;

// Functions
void init_robot(Robot *r) {
    r->x = rand() % 800 + 1;
    r->y = rand() % 600 + 1;
    r->dir = rand() % 4;
    r->speed = rand() % 6 + 1;
}

void draw_robot(Robot r) {
    int x = r.x, y = r.y;
    int c = (r.dir + 2) % 4; // convert direction to cardinal direction
    switch (c) {
        case 0: // up
            printf("\\");
            break;
        case 1: // right
            printf(">");
            break;
        case 2: // down
            printf("/");
            break;
        case 3: // left
            printf("<");
            break;
    }
}

void move_robot(Robot *r, int dx, int dy) {
    r->x += dx;
    r->y += dy;
}

void turn_robot(Robot *r, int angle) {
    int c = (r->dir + angle + 4) % 4; // convert angle to cardinal direction
    r->dir = c;
}

int main() {
    srand(time(0));

    printf("Enter number of robots: ");
    scanf("%d", &num_robots);

    for (int i = 0; i < num_robots; i++) {
        init_robot(&robots[i]);
        draw_robot(robots[i]);
    }

    while (1) {
        printf("\nEnter command (move distance, turn angle): ");
        scanf("%d %d", &commands[num_commands].type, &commands[num_commands].data);
        num_commands++;

        if (num_commands == MAX_COMMANDS) {
            printf("Too many commands, exiting...\n");
            return 0;
        }
    }

    return 0;
}