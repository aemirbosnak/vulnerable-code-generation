//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 80
#define MAX_Y 50
#define SPEED 10

// Define the remote control keys
#define KEY_UP 'w'
#define KEY_DOWN's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_FORWARD 'f'
#define KEY_BACKWARD 'b'

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
    int speed;
} Vehicle;

void move_vehicle(Vehicle *vehicle, int key) {
    switch(key) {
        case KEY_UP:
            vehicle->y -= vehicle->speed;
            break;
        case KEY_DOWN:
            vehicle->y += vehicle->speed;
            break;
        case KEY_LEFT:
            vehicle->x -= vehicle->speed;
            break;
        case KEY_RIGHT:
            vehicle->x += vehicle->speed;
            break;
        case KEY_FORWARD:
            vehicle->dx = vehicle->speed;
            break;
        case KEY_BACKWARD:
            vehicle->dx = -vehicle->speed;
            break;
    }
}

int main() {
    srand(time(NULL));

    // Initialize the vehicle
    Vehicle vehicle = {
       .x = rand() % MAX_X,
       .y = rand() % MAX_Y,
       .dx = 0,
       .dy = 0,
       .speed = SPEED
    };

    // Simulate the remote control
    int key;
    while(1) {
        printf("Press a key: ");
        scanf("%c", &key);
        move_vehicle(&vehicle, key);

        // Move the vehicle
        vehicle.x += vehicle.dx;
        vehicle.y += vehicle.dy;

        // Wrap around the screen
        if(vehicle.x < 0) {
            vehicle.x = MAX_X - 1;
        } else if(vehicle.x >= MAX_X) {
            vehicle.x = 0;
        }
        if(vehicle.y < 0) {
            vehicle.y = MAX_Y - 1;
        } else if(vehicle.y >= MAX_Y) {
            vehicle.y = 0;
        }

        // Print the vehicle
        printf("\033[H\033[2J");
        for(int i = 0; i < MAX_Y; i++) {
            for(int j = 0; j < MAX_X; j++) {
                if(i == vehicle.y && j == vehicle.x) {
                    printf("\033[1;31mX\033[0m");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        fflush(stdout);

        // Exit on ESC key
        if(key == 27) {
            break;
        }
    }

    return 0;
}