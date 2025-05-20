//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_SIZE 10
#define NUM_TREES 5

typedef enum {NORTH, EAST, SOUTH, WEST} direction_t;

typedef struct {
    int x;
    int y;
    direction_t direction;
} vehicle_t;

void print_map(vehicle_t vehicle, int trees[][2]) {
    printf(" ");
    for (int x = 0; x < MAP_SIZE; x++) {
        printf("_");
    }
    printf("\n");
    for (int y = 0; y < MAP_SIZE; y++) {
        printf("|");
        for (int x = 0; x < MAP_SIZE; x++) {
            bool is_tree = false;
            for (int i = 0; i < NUM_TREES; i++) {
                if (trees[i][0] == x && trees[i][1] == y) {
                    printf("T");
                    is_tree = true;
                    break;
                }
            }
            if (!is_tree && x == vehicle.x && y == vehicle.y) {
                switch(vehicle.direction) {
                    case NORTH:
                        printf("^");
                        break;
                    case EAST:
                        printf(">");
                        break;
                    case SOUTH:
                        printf("v");
                        break;
                    case WEST:
                        printf("<");
                        break;
                }
            } else if (!is_tree) {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf(" ");
    for (int x = 0; x < MAP_SIZE; x++) {
        printf("-");
    }
    printf("\n");
}

void move_forward(vehicle_t *vehicle) {
    switch(vehicle->direction) {
        case NORTH:
            if (vehicle->y > 0) {
                vehicle->y--;
            }
            break;
        case EAST:
            if (vehicle->x < MAP_SIZE - 1) {
                vehicle->x++;
            }
            break;
        case SOUTH:
            if (vehicle->y < MAP_SIZE - 1) {
                vehicle->y++;
            }
            break;
        case WEST:
            if (vehicle->x > 0) {
                vehicle->x--;
            }
            break;
    }
}

void turn_left(vehicle_t *vehicle) {
    switch(vehicle->direction) {
        case NORTH:
            vehicle->direction = WEST;
            break;
        case EAST:
            vehicle->direction = NORTH;
            break;
        case SOUTH:
            vehicle->direction = EAST;
            break;
        case WEST:
            vehicle->direction = SOUTH;
            break;
    }
}

void turn_right(vehicle_t *vehicle) {
    switch(vehicle->direction) {
        case NORTH:
            vehicle->direction = EAST;
            break;
        case EAST:
            vehicle->direction = SOUTH;
            break;
        case SOUTH:
            vehicle->direction = WEST;
            break;
        case WEST:
            vehicle->direction = NORTH;
            break;
    }
}

int main() {
    srand(time(NULL));
    vehicle_t vehicle = {0, 0, EAST};
    int trees[NUM_TREES][2];
    for (int i = 0; i < NUM_TREES; i++) {
        trees[i][0] = rand() % MAP_SIZE;
        trees[i][1] = rand() % MAP_SIZE;
    }
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Use 'f' to move forward, 'l' to turn left, 'r' to turn right,\n");
    printf("'q' to quit, and 'm' to show the map.\n");
    while(1) {
        char input;
        printf("Enter command: ");
        scanf(" %c", &input);
        if (input == 'f') {
            move_forward(&vehicle);
        } else if (input == 'l') {
            turn_left(&vehicle);
        } else if (input == 'r') {
            turn_right(&vehicle);
        } else if (input == 'q') {
            printf("Goodbye!\n");
            return 0;
        } else if (input == 'm') {
            print_map(vehicle, trees);
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}