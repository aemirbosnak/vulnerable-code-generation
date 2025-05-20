//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    int car_id;
    Coord pos;
    int speed;
    int prev_pos_x;
    int prev_pos_y;
    int prev_speed;
} Car;

Car cars[100];

void simulate_traffic_flow(int num_steps) {
    int i, j, k;
    int row, col;
    int car_id;
    int speed;

    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                row = j;
                col = k;
                car_id = 0;
                speed = 0;

                for (car_id = 0; car_id < 100; car_id++) {
                    if (cars[car_id].pos.x == row && cars[car_id].pos.y == col) {
                        speed = cars[car_id].speed;
                    }
                }

                if (speed == 0) {
                    for (car_id = 0; car_id < 100; car_id++) {
                        if (cars[car_id].prev_pos_x == row && cars[car_id].prev_pos_y == col) {
                            cars[car_id].speed = 0;
                        }
                    }
                } else {
                    for (car_id = 0; car_id < 100; car_id++) {
                        if (cars[car_id].pos.x == row && cars[car_id].pos.y == col) {
                            cars[car_id].speed = speed;
                        }
                    }
                }
            }
        }

        // Update car positions
        for (car_id = 0; car_id < 100; car_id++) {
            if (cars[car_id].speed!= 0) {
                cars[car_id].pos.x += cars[car_id].speed;
                cars[car_id].prev_pos_x = cars[car_id].pos.x;
                cars[car_id].prev_pos_y = cars[car_id].pos.y;
                cars[car_id].prev_speed = cars[car_id].speed;
            }
        }
    }
}

int main() {
    int i;
    int num_cars;
    int num_steps;

    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    for (i = 0; i < num_cars; i++) {
        printf("Enter the x and y coordinates of car %d: ", i + 1);
        scanf("%d %d", &cars[i].pos.x, &cars[i].pos.y);
    }

    printf("Enter the speed of each car: ");
    for (i = 0; i < num_cars; i++) {
        scanf("%d", &cars[i].speed);
    }

    printf("Enter the number of time steps: ");
    scanf("%d", &num_steps);

    simulate_traffic_flow(num_steps);

    printf("Simulation complete!\n");

    return 0;
}