//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 5
#define WIDTH 5

void draw_grid(int height, int width) {
    int i, j;
    for (i = 0; i <= height + 1; i++) {
        printf("-");
        for (j = 0; j <= width + 1; j++) {
            if ((i == 0) || (i == height + 1) || (j == 0) || (j == width + 1)) {
                printf("+");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void draw_vehicle(int x, int y, int direction) {
    switch (direction) {
        case 0:
            printf("   /\\");
            break;
        case 1:
            printf("  /  \\");
            break;
        case 2:
            printf(" /    \\");
            break;
        case 3:
            printf("\\    /");
            break;
        case 4:
            printf("\\  /");
            break;
        case 5:
            printf(" \\/");
            break;
        default:
            printf("Invalid direction");
            break;
    }
    printf(" %d,%d", x, y);
}

int main() {
    int height, width;
    int vehicle_x, vehicle_y;
    int vehicle_direction;
    int input_direction;
    char input_buffer[10];
    srand(time(0));
    height = HEIGHT;
    width = WIDTH;
    vehicle_x = rand() % height;
    vehicle_y = rand() % width;
    vehicle_direction = rand() % 6;
    draw_grid(height, width);
    draw_vehicle(vehicle_x, vehicle_y, vehicle_direction);
    printf("\n");
    while (1) {
        printf("Enter direction (0-5): ");
        scanf("%s", input_buffer);
        input_direction = atoi(input_buffer);
        if (input_direction >= 0 && input_direction <= 5) {
            vehicle_direction = input_direction;
            draw_vehicle(vehicle_x, vehicle_y, vehicle_direction);
            if (vehicle_x < 0) {
                vehicle_x = height - 1;
            } else if (vehicle_x >= height) {
                vehicle_x = 0;
            }
            if (vehicle_y < 0) {
                vehicle_y = width - 1;
            } else if (vehicle_y >= width) {
                vehicle_y = 0;
            }
        } else {
            printf("Invalid direction\n");
        }
        draw_vehicle(vehicle_x, vehicle_y, vehicle_direction);
        printf("\n");
    }
    return 0;
}