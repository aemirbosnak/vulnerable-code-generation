//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
    char direction; // 'N', 'E', 'S', 'W'
} Vehicle;

void initialize_vehicle(Vehicle* vehicle) {
    vehicle->x = GRID_SIZE / 2;
    vehicle->y = GRID_SIZE / 2;
    vehicle->direction = 'N'; // Start facing North
}

void display_grid(Vehicle* vehicle) {
    system("clear"); // Clear the console (Linux specific)
    
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == vehicle->y && j == vehicle->x) {
                printf("V "); // Vehicle representation
            } else {
                printf(". "); // Empty space
            }
        }
        printf("\n");
    }
    
    printf("Vehicle is facing: %c\n", vehicle->direction);
}

void move_forward(Vehicle* vehicle) {
    switch(vehicle->direction) {
        case 'N': vehicle->y = (vehicle->y - 1 + GRID_SIZE) % GRID_SIZE; break;
        case 'E': vehicle->x = (vehicle->x + 1) % GRID_SIZE; break;
        case 'S': vehicle->y = (vehicle->y + 1) % GRID_SIZE; break;
        case 'W': vehicle->x = (vehicle->x - 1 + GRID_SIZE) % GRID_SIZE; break;
    }
}

void move_backward(Vehicle* vehicle) {
    switch(vehicle->direction) {
        case 'N': vehicle->y = (vehicle->y + 1) % GRID_SIZE; break;
        case 'E': vehicle->x = (vehicle->x - 1 + GRID_SIZE) % GRID_SIZE; break;
        case 'S': vehicle->y = (vehicle->y - 1 + GRID_SIZE) % GRID_SIZE; break;
        case 'W': vehicle->x = (vehicle->x + 1) % GRID_SIZE; break;
    }
}

void turn_left(Vehicle* vehicle) {
    switch(vehicle->direction) {
        case 'N': vehicle->direction = 'W'; break;
        case 'E': vehicle->direction = 'N'; break;
        case 'S': vehicle->direction = 'E'; break;
        case 'W': vehicle->direction = 'S'; break;
    }
}

void turn_right(Vehicle* vehicle) {
    switch(vehicle->direction) {
        case 'N': vehicle->direction = 'E'; break;
        case 'E': vehicle->direction = 'S'; break;
        case 'S': vehicle->direction = 'W'; break;
        case 'W': vehicle->direction = 'N'; break;
    }
}

int main() {
    Vehicle vehicle;
    char command;
    
    initialize_vehicle(&vehicle);
    
    while (1) {
        display_grid(&vehicle);
        
        printf("Enter command (w: forward, s: backward, a: left, d: right, q: quit): ");
        scanf(" %c", &command);
        
        switch(command) {
            case 'w':
                move_forward(&vehicle);
                break;
            case 's':
                move_backward(&vehicle);
                break;
            case 'a':
                turn_left(&vehicle);
                break;
            case 'd':
                turn_right(&vehicle);
                break;
            case 'q':
                printf("Exiting simulation.\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
        }
        
        usleep(500000); // Pause for half a second
    }
    
    return 0;
}