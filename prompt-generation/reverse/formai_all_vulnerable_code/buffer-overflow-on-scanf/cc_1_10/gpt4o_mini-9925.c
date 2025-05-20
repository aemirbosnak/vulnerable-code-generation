//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Robot;

void initialize_robot(Robot *robot) {
    robot->x = GRID_SIZE / 2;
    robot->y = GRID_SIZE / 2;
}

void display_grid(Robot *robot) {
    system("clear"); // clear the console
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (robot->x == j && robot->y == i) {
                printf("R "); // R represents the robot
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("Robot position: (%d, %d)\n", robot->x, robot->y);
}

void move_robot(Robot *robot, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (robot->y > 0) {
                robot->y--;
            }
            break;
        case 's': // Move down
            if (robot->y < GRID_SIZE - 1) {
                robot->y++;
            }
            break;
        case 'a': // Move left
            if (robot->x > 0) {
                robot->x--;
            }
            break;
        case 'd': // Move right
            if (robot->x < GRID_SIZE - 1) {
                robot->x++;
            }
            break;
        default:
            printf("Invalid move. Use 'w', 'a', 's', 'd' to move the robot.\n");
            break;
    }
}

void print_instructions() {
    printf("Control the robot with the following keys:\n");
    printf("W - Move Up\n");
    printf("A - Move Left\n");
    printf("S - Move Down\n");
    printf("D - Move Right\n");
    printf("Q - Quit\n");
}

int main() {
    Robot robot;
    char command;

    initialize_robot(&robot);
    print_instructions();

    while (1) {
        display_grid(&robot);
        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'q' || command == 'Q') {
            printf("Exiting...\n");
            break;
        }

        move_robot(&robot, command);
    }

    return 0;
}