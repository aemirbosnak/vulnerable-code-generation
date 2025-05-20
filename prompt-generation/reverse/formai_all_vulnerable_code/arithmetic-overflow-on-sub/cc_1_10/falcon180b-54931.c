//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

typedef struct {
    int x;
    int y;
} Point;

void draw_grid(int width, int height) {
    for (int i = 0; i <= height; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i <= width; i++) {
        printf("|");
    }
    printf("\n");
}

void draw_vehicle(Point vehicle) {
    printf("O");
}

void move_vehicle(Point *vehicle, char direction) {
    switch (direction) {
        case UP:
            vehicle->y--;
            break;
        case DOWN:
            vehicle->y++;
            break;
        case LEFT:
            vehicle->x--;
            break;
        case RIGHT:
            vehicle->x++;
            break;
    }
}

int main() {
    int width, height;
    printf("Enter the width of the grid: ");
    scanf("%d", &width);
    printf("Enter the height of the grid: ");
    scanf("%d", &height);

    Point vehicle = {0, 0};
    Point target = {width - 1, height - 1};

    draw_grid(width, height);
    draw_vehicle(vehicle);

    int x = 0, y = 0;
    char direction;

    while (vehicle.x!= target.x || vehicle.y!= target.y) {
        printf("Enter the direction of the vehicle (up, down, left, right): ");
        scanf(" %c", &direction);
        move_vehicle(&vehicle, direction);

        if (vehicle.x < 0 || vehicle.x >= width || vehicle.y < 0 || vehicle.y >= height) {
            printf("Vehicle crashed!\n");
            return 0;
        }

        draw_grid(width, height);
        draw_vehicle(vehicle);

        if (vehicle.x == target.x && vehicle.y == target.y) {
            printf("Vehicle reached the target!\n");
        }
    }

    return 0;
}