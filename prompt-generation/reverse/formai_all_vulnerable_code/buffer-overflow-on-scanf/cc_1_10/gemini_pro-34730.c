//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
// Remote Control Vehicle Simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Vehicle struct
typedef struct vehicle {
    int x;  // X-coordinate
    int y;  // Y-coordinate
    int dx; // Change in X-coordinate
    int dy; // Change in Y-coordinate
} vehicle_t;

// Obstacle struct
typedef struct obstacle {
    int x;  // X-coordinate
    int y;  // Y-coordinate
    int w;  // Width
    int h;  // Height
} obstacle_t;

// Function to initialize the vehicle
void init_vehicle(vehicle_t *v) {
    v->x = 0;
    v->y = 0;
    v->dx = 0;
    v->dy = 0;
}

// Function to initialize an obstacle
void init_obstacle(obstacle_t *o, int x, int y, int w, int h) {
    o->x = x;
    o->y = y;
    o->w = w;
    o->h = h;
}

// Function to draw the vehicle
void draw_vehicle(vehicle_t *v) {
    printf("^");
}

// Function to draw an obstacle
void draw_obstacle(obstacle_t *o) {
    for (int i = 0; i < o->w; i++) {
        for (int j = 0; j < o->h; j++) {
            printf("#");
        }
        printf("\n");
    }
}

// Function to move the vehicle
void move_vehicle(vehicle_t *v) {
    v->x += v->dx;
    v->y += v->dy;
}

// Function to check if the vehicle has collided with an obstacle
int check_collision(vehicle_t *v, obstacle_t *o) {
    return (v->x >= o->x && v->x <= o->x + o->w &&
            v->y >= o->y && v->y <= o->y + o->h);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the vehicle
    vehicle_t vehicle;
    init_vehicle(&vehicle);

    // Initialize the obstacle
    obstacle_t obstacle;
    init_obstacle(&obstacle, 10, 10, 5, 5);

    // Main game loop
    while (1) {
        // Get the user's input
        char input;
        printf("Enter a command (w/a/s/d to move, q to quit): ");
        scanf(" %c", &input);

        // Update the vehicle's movement
        switch (input) {
            case 'w':
                vehicle.dy = -1;
                break;
            case 'a':
                vehicle.dx = -1;
                break;
            case 's':
                vehicle.dy = 1;
                break;
            case 'd':
                vehicle.dx = 1;
                break;
            case 'q':
                exit(0);
            default:
                break;
        }

        // Move the vehicle
        move_vehicle(&vehicle);

        // Check if the vehicle has collided with the obstacle
        if (check_collision(&vehicle, &obstacle)) {
            printf("Oops! You crashed into an obstacle!\n");
            break;
        }

        // Clear the screen
        system("clear");

        // Draw the vehicle and the obstacle
        draw_vehicle(&vehicle);
        draw_obstacle(&obstacle);

        // Pause for a bit
        usleep(100000);
    }

    return 0;
}