//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X_MAX 50
#define Y_MAX 20
#define SPEED 2

typedef struct {
    int x, y;
} position;

position vehicle;

void print_position(position vehicle) {
    printf("Position: (%d, %d)\n", vehicle.x, vehicle.y);
}

void move_forward(position *vehicle) {
    vehicle->x += SPEED;
    if (vehicle->x > X_MAX) {
        vehicle->x -= X_MAX;
        vehicle->y += SPEED;
    }
}

void move_backward(position *vehicle) {
    position temp;
    temp = *vehicle;
    temp.x -= SPEED;
    if (temp.x < 0) {
        temp.x += X_MAX;
        temp.y -= SPEED;
    }
    *vehicle = temp;
}

void move_left(position *vehicle) {
    vehicle->y -= SPEED;
}

void move_right(position *vehicle) {
    vehicle->y += SPEED;
}

int main() {
    int choice;

    srand(time(NULL));
    vehicle.x = rand() % X_MAX + 1;
    vehicle.y = rand() % Y_MAX + 1;

    printf("Remote Control Vehicle Simulation\n");
    printf("Position: (%d, %d)\n", vehicle.x, vehicle.y);

    while (1) {
        print_position(vehicle);
        printf("Choose an action:\n1. Move forward\n2. Move backward\n3. Move left\n4. Move right\n5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_forward(&vehicle);
                break;
            case 2:
                move_backward(&vehicle);
                break;
            case 3:
                move_left(&vehicle);
                break;
            case 4:
                move_right(&vehicle);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}