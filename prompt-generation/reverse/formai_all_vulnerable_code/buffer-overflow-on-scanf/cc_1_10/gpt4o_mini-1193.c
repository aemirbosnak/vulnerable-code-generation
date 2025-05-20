//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <time.h>   // For randomness

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Position;

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void print_grid(char grid[GRID_SIZE][GRID_SIZE], Position robot) {
    system("clear"); // Clear the terminal
    grid[robot.x][robot.y] = 'R'; // Indicate robot position
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    grid[robot.x][robot.y] = '.'; // Reset position for future prints
}

void move_robot(Position *robot, char direction) {
    switch (direction) {
        case 'u': // move up
            if (robot->x > 0) robot->x--;
            break;
        case 'd': // move down
            if (robot->x < GRID_SIZE - 1) robot->x++;
            break;
        case 'l': // move left
            if (robot->y > 0) robot->y--;
            break;
        case 'r': // move right
            if (robot->y < GRID_SIZE - 1) robot->y++;
            break;
        default:
            printf("Invalid direction! Use 'u', 'd', 'l', or 'r'.\n");
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position robot = {0, 0}; // Starting position at the top left corner
    char direction;
    int moves = 20;

    initialize_grid(grid);
    
    printf("Welcome to the Robot Movement Control.\n");
    printf("The robot can move in the following directions:\n");
    printf("u: up, d: down, l: left, r: right\n");
    printf("You have %d moves to control the robot.\n\n", moves);

    while (moves > 0) {
        print_grid(grid, robot);
        printf("Moves left: %d\n", moves);
        printf("Enter your direction (u, d, l, r): ");
        scanf(" %c", &direction);

        move_robot(&robot, direction);
        moves--;

        // Simulate some randomness in robot's movement neutrality
        if (rand() % 5 == 0) {
            int random_move = rand() % 4;
            switch (random_move) {
                case 0: move_robot(&robot, 'u'); break;
                case 1: move_robot(&robot, 'd'); break;
                case 2: move_robot(&robot, 'l'); break;
                case 3: move_robot(&robot, 'r'); break;
            }
        }

        sleep(1); // Pause for 1 second between moves
    }

    printf("Game over! The robot has finished its movement.\n");
    return 0;
}