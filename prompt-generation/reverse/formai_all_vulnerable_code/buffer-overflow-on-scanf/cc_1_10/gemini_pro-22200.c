//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the grid
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Define the possible directions of movement
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Define the maximum speed of the vehicle
#define MAX_SPEED 5

// Define the maximum number of obstacles
#define MAX_OBSTACLES 10

// Define the structure of an obstacle
typedef struct {
    int x;
    int y;
} Obstacle;

// Define the structure of the vehicle
typedef struct {
    int x;
    int y;
    int direction;
    int speed;
} Vehicle;

// Create the grid
char grid[GRID_WIDTH][GRID_HEIGHT];

// Create the vehicle
Vehicle vehicle;

// Create the obstacles
Obstacle obstacles[MAX_OBSTACLES];

// Initialize the grid
void init_grid() {
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            grid[i][j] = ' ';
        }
    }
}

// Initialize the vehicle
void init_vehicle() {
    vehicle.x = GRID_WIDTH / 2;
    vehicle.y = GRID_HEIGHT / 2;
    vehicle.direction = UP;
    vehicle.speed = 0;
}

// Initialize the obstacles
void init_obstacles() {
    srand(time(NULL));
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].x = rand() % GRID_WIDTH;
        obstacles[i].y = rand() % GRID_HEIGHT;
    }
}

// Draw the grid
void draw_grid() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (vehicle.x == j && vehicle.y == i) {
                printf("V");
            } else if (grid[j][i] == 'O') {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Move the vehicle
void move_vehicle() {
    // Check if the vehicle is at the edge of the grid
    if (vehicle.x == 0 && vehicle.direction == LEFT) {
        vehicle.direction = RIGHT;
    } else if (vehicle.x == GRID_WIDTH - 1 && vehicle.direction == RIGHT) {
        vehicle.direction = LEFT;
    } else if (vehicle.y == 0 && vehicle.direction == UP) {
        vehicle.direction = DOWN;
    } else if (vehicle.y == GRID_HEIGHT - 1 && vehicle.direction == DOWN) {
        vehicle.direction = UP;
    }

    // Check if the vehicle is about to hit an obstacle
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (vehicle.x == obstacles[i].x && vehicle.y == obstacles[i].y) {
            vehicle.speed = 0;
        }
    }

    // Move the vehicle
    switch (vehicle.direction) {
        case UP:
            vehicle.y--;
            break;
        case DOWN:
            vehicle.y++;
            break;
        case LEFT:
            vehicle.x--;
            break;
        case RIGHT:
            vehicle.x++;
            break;
    }
}

// Handle user input
void handle_input() {
    char input;
    printf("Enter a command (w, a, s, d, q): ");
    scanf(" %c", &input);

    switch (input) {
        case 'w':
            vehicle.direction = UP;
            vehicle.speed++;
            if (vehicle.speed > MAX_SPEED) {
                vehicle.speed = MAX_SPEED;
            }
            break;
        case 'a':
            vehicle.direction = LEFT;
            vehicle.speed++;
            if (vehicle.speed > MAX_SPEED) {
                vehicle.speed = MAX_SPEED;
            }
            break;
        case 's':
            vehicle.direction = DOWN;
            vehicle.speed++;
            if (vehicle.speed > MAX_SPEED) {
                vehicle.speed = MAX_SPEED;
            }
            break;
        case 'd':
            vehicle.direction = RIGHT;
            vehicle.speed++;
            if (vehicle.speed > MAX_SPEED) {
                vehicle.speed = MAX_SPEED;
            }
            break;
        case 'q':
            exit(0);
            break;
    }
}

// Main game loop
void game_loop() {
    while (1) {
        // Handle user input
        handle_input();

        // Move the vehicle
        move_vehicle();

        // Draw the grid
        draw_grid();
    }
}

int main() {
    // Initialize the grid
    init_grid();

    // Initialize the vehicle
    init_vehicle();

    // Initialize the obstacles
    init_obstacles();

    // Start the game loop
    game_loop();

    return 0;
}