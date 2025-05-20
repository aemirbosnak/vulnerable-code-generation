//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define ROAD_CAPACITY 1000
#define TIME_INTERVAL 1000

void draw_road(int road[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (road[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_traffic(int road[ROWS][COLS]) {
    int i, j, k, count = 0;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (road[i][j] == 1) {
                road[i][j] = 2;
                count++;
            }
        }
    }
    printf("Generated %d vehicles\n", count);
}

void move_vehicles(int road[ROWS][COLS]) {
    int i, j, k, x, y;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (road[i][j] == 2) {
                x = i;
                y = j;
                while (road[x][y] == 2) {
                    x++;
                    y++;
                }
                if (road[x][y] == 1) {
                    road[x][y] = 2;
                    road[i][j] = 0;
                } else {
                    road[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int road[ROWS][COLS] = {{0}};
    int choice, x, y;

    printf("Enter the coordinates of the road (row col): ");
    scanf("%d %d", &x, &y);
    road[x][y] = 1;

    while (1) {
        printf("\n1. Generate traffic\n2. Move vehicles\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            generate_traffic(road);
            break;
        case 2:
            move_vehicles(road);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }

        draw_road(road);
        sleep(TIME_INTERVAL);
    }

    return 0;
}