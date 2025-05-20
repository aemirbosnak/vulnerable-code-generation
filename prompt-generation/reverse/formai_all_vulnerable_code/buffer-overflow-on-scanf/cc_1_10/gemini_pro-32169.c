//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct {
    int16_t x;
    int16_t y;
} point_t;

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction_t;

typedef struct {
    point_t position;
    direction_t direction;
} robot_t;

void print_map(char map[MAP_WIDTH][MAP_HEIGHT]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

bool is_valid_move(char map[MAP_WIDTH][MAP_HEIGHT], point_t point) {
    return point.x >= 0 && point.x < MAP_WIDTH && point.y >= 0 && point.y < MAP_HEIGHT && map[point.x][point.y] != '#';
}

void move_robot(char map[MAP_WIDTH][MAP_HEIGHT], robot_t *robot) {
    point_t next_position;
    switch (robot->direction) {
        case NORTH:
            next_position.x = robot->position.x;
            next_position.y = robot->position.y - 1;
            break;
        case EAST:
            next_position.x = robot->position.x + 1;
            next_position.y = robot->position.y;
            break;
        case SOUTH:
            next_position.x = robot->position.x;
            next_position.y = robot->position.y + 1;
            break;
        case WEST:
            next_position.x = robot->position.x - 1;
            next_position.y = robot->position.y;
            break;
    }
    if (is_valid_move(map, next_position)) {
        robot->position = next_position;
    }
}

void turn_robot(robot_t *robot, bool clockwise) {
    if (clockwise) {
        robot->direction = (robot->direction + 1) % 4;
    } else {
        robot->direction = (robot->direction + 3) % 4;
    }
}

int main() {
    char map[MAP_WIDTH][MAP_HEIGHT] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    robot_t robot = {
        .position = {5, 5},
        .direction = NORTH
    };

    print_map(map);
    printf("\n");

    char command;
    while (true) {
        printf("Enter a command (w/a/s/d/q): ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                move_robot(map, &robot);
                break;
            case 'a':
                turn_robot(&robot, false);
                break;
            case 's':
                move_robot(map, &robot);
                break;
            case 'd':
                turn_robot(&robot, true);
                break;
            case 'q':
                exit(0);
                break;
        }

        print_map(map);
        printf("\n");
    }

    return 0;
}