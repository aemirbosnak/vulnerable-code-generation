//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    char symbol;
} Vehicle;

Vehicle vehicle = { { 0, 0 }, 'V' };
char grid[WIDTH][HEIGHT];

void init_grid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = ' ';
        }
    }
}

void draw_grid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void update_vehicle_position(char command) {
    switch (command) {
        case 'w':
            vehicle.position.y--;
            break;
        case 'a':
            vehicle.position.x--;
            break;
        case 's':
            vehicle.position.y++;
            break;
        case 'd':
            vehicle.position.x++;
            break;
    }
}

int main() {
    srand(time(NULL));

    init_grid();
    while (1) {
        char command = getchar();
        update_vehicle_position(command);

        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                grid[i][j] = ' ';
            }
        }
        grid[vehicle.position.y][vehicle.position.x] = vehicle.symbol;
        draw_grid();
        usleep(100000);
    }

    return 0;
}