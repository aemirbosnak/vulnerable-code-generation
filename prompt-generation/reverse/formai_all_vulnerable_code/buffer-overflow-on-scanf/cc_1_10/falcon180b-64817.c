//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define SPEED 5

// Define the remote control vehicle
typedef struct {
    char symbol;
    int x, y;
    int speed;
} Vehicle;

// Initialize the remote control vehicle
void init_vehicle(Vehicle *v) {
    v->symbol = '@';
    v->x = 0;
    v->y = 0;
    v->speed = SPEED;
}

// Print the remote control vehicle
void print_vehicle(Vehicle v) {
    printf("%c", v.symbol);
}

// Move the remote control vehicle forward
void move_forward(Vehicle *v) {
    v->x += v->speed;
}

// Turn the remote control vehicle left
void turn_left(Vehicle *v) {
    v->y -= v->speed;
}

// Turn the remote control vehicle right
void turn_right(Vehicle *v) {
    v->y += v->speed;
}

// Main function to simulate the remote control vehicle
int main() {
    srand(time(NULL));

    // Initialize the remote control vehicle
    Vehicle vehicle;
    init_vehicle(&vehicle);

    // Simulate the remote control vehicle
    int key;
    while (1) {
        // Print the current position of the remote control vehicle
        printf("\n");
        for (int i = 0; i < vehicle.y; i++) {
            printf(" ");
        }
        for (int i = 0; i < vehicle.x; i++) {
            printf("*");
        }
        printf("\n");

        // Get the user input
        scanf("%d", &key);

        // Move the remote control vehicle based on the user input
        switch (key) {
            case 'w':
                move_forward(&vehicle);
                break;
            case 'a':
                turn_left(&vehicle);
                break;
            case's':
                move_forward(&vehicle);
                break;
            case 'd':
                turn_right(&vehicle);
                break;
            default:
                break;
        }

        // Check if the remote control vehicle has reached the end of the screen
        if (vehicle.x >= WIDTH || vehicle.y >= HEIGHT) {
            printf("The remote control vehicle has reached the end of the screen.\n");
            break;
        }
    }

    return 0;
}