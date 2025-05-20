//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define SPEED 4

// Define the remote control vehicle's position and direction
typedef struct {
    int x, y;
    int dx, dy;
} Vehicle;

// Initialize the remote control vehicle at the center of the screen
Vehicle init_vehicle() {
    Vehicle v = {WIDTH / 2, HEIGHT / 2, 0, 0};
    return v;
}

// Move the remote control vehicle in the given direction
void move_vehicle(Vehicle *v, int dx, int dy) {
    v->x += dx * SPEED;
    v->y += dy * SPEED;

    // Wrap around the screen
    if (v->x < 0) {
        v->x = WIDTH - 1;
    } else if (v->x >= WIDTH) {
        v->x = 0;
    }

    if (v->y < 0) {
        v->y = HEIGHT - 1;
    } else if (v->y >= HEIGHT) {
        v->y = 0;
    }
}

// Print the remote control vehicle on the screen
void draw_vehicle(Vehicle v) {
    printf("@");
}

// Print the remote control vehicle and the current time on the screen
void display_time(Vehicle v) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("\r%02d:%02d:%02d ", t->tm_hour, t->tm_min, t->tm_sec);
    draw_vehicle(v);
}

// Main function for the remote control vehicle simulation
int main() {
    srand(time(NULL));

    // Initialize the remote control vehicle
    Vehicle v = init_vehicle();

    // Loop until the user presses a key
    while (1) {
        // Move the remote control vehicle randomly
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        move_vehicle(&v, dx, dy);

        // Print the remote control vehicle and the current time
        display_time(v);

        // Wait for a random amount of time
        int delay = rand() % 100 + 50;
        usleep(delay * 1000);
    }

    return 0;
}