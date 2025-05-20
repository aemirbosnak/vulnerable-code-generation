//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

void initialize_position(Position* pos) {
    pos->x = GRID_SIZE / 2; // Start in the center of the grid
    pos->y = GRID_SIZE / 2;
}

void print_grid(Position* pos) {
    system("clear"); // Clear console (Linux equivalent of cls)
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (row == pos->y && col == pos->x) {
                printf("R "); // 'R' represents the Robot
            } else {
                printf(". "); // '.' represents free space
            }
        }
        printf("\n");
    }
}

void move_robot(Position* pos, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (pos->y > 0) {
                pos->y--;
            }
            break;
        case 's': // Move down
            if (pos->y < GRID_SIZE - 1) {
                pos->y++;
            }
            break;
        case 'a': // Move left
            if (pos->x > 0) {
                pos->x--;
            }
            break;
        case 'd': // Move right
            if (pos->x < GRID_SIZE - 1) {
                pos->x++;
            }
            break;
        default:
            printf("Invalid move. Use W, A, S, D to move.\n");
            break;
    }
}

int main() {
    Position robot_position;
    char command;

    initialize_position(&robot_position);

    printf("Welcome to the Robot Movement Simulator!\n");
    printf("Control the robot using W (up), S (down), A (left), D (right).\n");
    printf("Press Q to quit.\n");

    do {
        print_grid(&robot_position);
        printf("Enter your command: ");
        scanf(" %c", &command); // Notice the space before %c to consume newline

        if (command != 'q') {
            move_robot(&robot_position, command);
        }
    } while (command != 'q');

    printf("Exiting the Robot Movement Simulator. Goodbye!\n");
    return 0;
}