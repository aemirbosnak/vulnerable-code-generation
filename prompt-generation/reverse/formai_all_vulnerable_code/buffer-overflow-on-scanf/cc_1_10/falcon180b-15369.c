//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROBOTS 10
#define MAX_COMMANDS 100

struct Robot {
    int id;
    int x;
    int y;
    int dir;
};

struct Command {
    int robot_id;
    int command;
};

int main() {
    int num_robots, num_commands;
    scanf("%d %d", &num_robots, &num_commands);

    struct Robot *robots = malloc(sizeof(struct Robot) * num_robots);
    srand(time(NULL));
    for (int i = 0; i < num_robots; i++) {
        robots[i].id = i;
        robots[i].x = rand() % 100;
        robots[i].y = rand() % 100;
        robots[i].dir = rand() % 4;
    }

    struct Command *commands = malloc(sizeof(struct Command) * num_commands);
    for (int i = 0; i < num_commands; i++) {
        scanf("%d %d", &commands[i].robot_id, &commands[i].command);
    }

    for (int i = 0; i < num_commands; i++) {
        int robot_id = commands[i].robot_id;
        int command = commands[i].command;

        switch (command) {
            case 0:
                printf("Robot %d stopped.\n", robot_id);
                break;
            case 1:
                printf("Robot %d moved forward.\n", robot_id);
                break;
            case 2:
                printf("Robot %d turned left.\n", robot_id);
                break;
            case 3:
                printf("Robot %d turned right.\n", robot_id);
                break;
            default:
                printf("Invalid command for robot %d.\n", robot_id);
        }
    }

    free(robots);
    free(commands);

    return 0;
}