//MISTRAL-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_CARS 50
#define TIME_STEP 100

typedef struct {
    int x, y;
} car_t;

car_t cars[MAX_CARS];
int cars_count = 0;
int grid[ROWS][COLS];

void init_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

void print_grid() {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void move_cars() {
    int i, j;
    for (i = 0; i < cars_count; i++) {
        car_t *car = &cars[i];
        int dx = car->x < COLS - 1 ? 1 : 0;
        int dy = car->y < ROWS - 1 ? 1 : 0;

        if (grid[car->y + dy][car->x + dx] == 0) {
            car->x += dx;
            car->y += dy;
            grid[car->y][car->x] = 0;
            grid[car->y + dy][car->x + dx] = 1;
        }
    }
}

void add_car(int x, int y) {
    if (cars_count < MAX_CARS && grid[y][x] == 0) {
        cars[cars_count++] = (car_t){ x, y };
        grid[y][x] = 1;
    }
}

void random_event() {
    int x, y;
    if (rand() % 10 < 5) { // 50% chance of adding a car
        x = rand() % COLS;
        y = rand() % ROWS;
        add_car(x, y);
    } else { // 50% chance of removing a car
        if (cars_count > 0) {
            cars_count--;
            int i = rand() % cars_count;
            car_t *car = &cars[i];
            grid[car->y][car->x] = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    init_grid();

    for (int i = 0; i < TIME_STEP; i++) {
        move_cars();
        random_event();
        if (i % 10 == 0) {
            printf("Step %d:\n", i);
            print_grid();
            printf("\n");
        }
    }

    return 0;
}