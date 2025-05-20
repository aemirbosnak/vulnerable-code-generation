//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 10 // Size of the grid
#define MAX_STEPS 100 // Maximum steps robot can take

typedef struct {
    int x, y; // Robot's position
} Robot;

void initialize_robot(Robot *robot) {
    robot->x = GRID_SIZE / 2; // Start in the middle of the grid
    robot->y = GRID_SIZE / 2;
}

void display_grid(Robot robot) {
    system("clear"); // Clear the terminal for a fresh display
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == robot.y && j == robot.x)
                printf("R "); // Display the Robot
            else
                printf(". "); // Empty space
        }
        printf("\n");
    }
}

void move_robot(Robot *robot, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (robot->y > 0) robot->y--;
            break;
        case 's': // Move down
            if (robot->y < GRID_SIZE - 1) robot->y++;
            break;
        case 'a': // Move left
            if (robot->x > 0) robot->x--;
            break;
        case 'd': // Move right
            if (robot->x < GRID_SIZE - 1) robot->x++;
            break;
        default:
            printf("Invalid move! Use 'w', 's', 'a', or 'd'.\n");
            break;
    }
}

void random_move(Robot *robot) {
    int r = rand() % 4; // Generate a random number between 0-3
    switch (r) {
        case 0:
            move_robot(robot, 'w');
            break;
        case 1:
            move_robot(robot, 's');
            break;
        case 2:
            move_robot(robot, 'a');
            break;
        case 3:
            move_robot(robot, 'd');
            break;
    }
}

int main() {
    Robot robot;
    char user_input;
    int step_count = 0;

    srand(time(NULL)); // Seed for random function
    initialize_robot(&robot); // Initialize robot's position

    while (step_count < MAX_STEPS) {
        display_grid(robot); // Display the current grid
        printf("Step %d - Enter your move (w/a/s/d): ", step_count + 1);
        if (scanf(" %c", &user_input) != 1) {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        move_robot(&robot, user_input); // Move based on user's input

        // Optional: Robot will also do a random move after the user's move
        random_move(&robot);

        step_count++;
        usleep(500000); // Wait for half a second
    }

    display_grid(robot); // Final display of robot's position
    printf("Maximum steps reached. Robot's final position: (%d, %d)\n", robot.x, robot.y);
    return 0;
}