//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 10
#define MAX_COMMANDS 50

typedef struct {
    int x;
    int y;
} Position;

void move_robot(Position *pos, const char *command) {
    if (strcmp(command, "UP") == 0) {
        if (pos->y < GRID_SIZE - 1) {
            pos->y++;
        } else {
            printf("Can't move up, reached the top edge!\n");
        }
    } else if (strcmp(command, "DOWN") == 0) {
        if (pos->y > 0) {
            pos->y--;
        } else {
            printf("Can't move down, reached the bottom edge!\n");
        }
    } else if (strcmp(command, "LEFT") == 0) {
        if (pos->x > 0) {
            pos->x--;
        } else {
            printf("Can't move left, reached the left edge!\n");
        }
    } else if (strcmp(command, "RIGHT") == 0) {
        if (pos->x < GRID_SIZE - 1) {
            pos->x++;
        } else {
            printf("Can't move right, reached the right edge!\n");
        }
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void print_position(const Position *pos) {
    printf("Robot is at position (%d, %d)\n", pos->x, pos->y);
}

int main() {
    Position robot = {0, 0}; // Start at the top left corner
    char commands[MAX_COMMANDS][10];
    int command_count = 0;

    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Enter commands (UP, DOWN, LEFT, RIGHT) or type 'exit' to quit:\n");

    // Input loop
    while (command_count < MAX_COMMANDS) {
        char command[10];
        printf("Enter command %d: ", command_count + 1);
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        strcpy(commands[command_count], command);
        command_count++;
    }

    // Execute commands
    for (int i = 0; i < command_count; i++) {
        move_robot(&robot, commands[i]);
        print_position(&robot);
    }

    printf("Thank you for using the Robot Movement Control Program!\n");
    return 0;
}