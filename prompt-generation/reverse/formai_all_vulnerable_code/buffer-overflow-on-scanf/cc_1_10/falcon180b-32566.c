//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int speed;
    int direction;
} Vehicle;

void move(Vehicle *vehicle) {
    Point new_position = {
        vehicle->position.x + (vehicle->speed * vehicle->direction),
        vehicle->position.y
    };
    vehicle->position = new_position;
}

void turn(Vehicle *vehicle, int degrees) {
    int new_direction = (vehicle->direction + degrees) % 360;
    vehicle->direction = new_direction;
}

int main() {
    Vehicle car;
    car.position.x = 0;
    car.position.y = 0;
    car.speed = 10;
    car.direction = 0;

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move(&car);
                printf("Car moved forward\n");
                break;
            case 2:
                turn(&car, -90);
                printf("Car turned left\n");
                break;
            case 3:
                turn(&car, 90);
                printf("Car turned right\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(choice!= 4);

    return 0;
}