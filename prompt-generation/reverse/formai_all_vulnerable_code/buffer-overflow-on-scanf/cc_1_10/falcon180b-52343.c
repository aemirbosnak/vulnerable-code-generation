//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
// Remote Control Vehicle Simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define SPEED 5
#define DELAY 50000 // 50ms delay

void draw_map(char map[WIDTH][HEIGHT]);
void move_vehicle(int *x, int *y, int direction);

int main() {
    char map[WIDTH][HEIGHT];
    int x = 0, y = 0;
    int direction = 0;

    srand(time(NULL));

    // Initialize map
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            map[i][j] = rand() % 2; // 0 for wall, 1 for open space
        }
    }

    // Draw map
    draw_map(map);

    // Start simulation
    while (1) {
        if (map[x][y] == 0) {
            printf("Vehicle hit a wall, game over.\n");
            break;
        }
        printf("Current position: (%d, %d)\n", x, y);
        int input;
        scanf("%d", &input);
        move_vehicle(&x, &y, input);
        draw_map(map);
        usleep(DELAY);
    }

    return 0;
}

void draw_map(char map[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (map[i][j] == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move_vehicle(int *x, int *y, int direction) {
    switch (direction) {
        case 0:
            (*y)--;
            break;
        case 1:
            (*x)++;
            break;
        case 2:
            (*y)++;
            break;
        case 3:
            (*x)--;
            break;
    }
}