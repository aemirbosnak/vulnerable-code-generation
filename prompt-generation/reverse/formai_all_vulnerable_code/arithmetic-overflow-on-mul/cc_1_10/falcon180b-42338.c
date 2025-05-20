//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TIME_SPEED 1.0
#define TIME_MIN 0.0
#define TIME_MAX 1.0
#define TIME_DIM 4
#define TIME_NUM 8

double time_matrix[TIME_DIM][TIME_NUM];
int time_index;

void init_time_matrix() {
    for (int i = 0; i < TIME_DIM; i++) {
        for (int j = 0; j < TIME_NUM; j++) {
            time_matrix[i][j] = (double) rand() / RAND_MAX;
        }
    }
    time_index = 0;
}

void print_time_matrix() {
    for (int i = 0; i < TIME_DIM; i++) {
        for (int j = 0; j < TIME_NUM; j++) {
            printf("%f ", time_matrix[i][j]);
        }
        printf("\n");
    }
}

void time_travel(int direction, int distance) {
    int new_index = time_index + direction * distance;
    if (new_index < 0) {
        new_index = TIME_NUM - 1;
    } else if (new_index >= TIME_NUM) {
        new_index = 0;
    }
    time_index = new_index;
}

int main() {
    srand(time(NULL));
    init_time_matrix();
    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Print time matrix\n");
        printf("2. Time travel\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_time_matrix();
                break;
            case 2:
                printf("Enter direction (1 for forward, -1 for backward): ");
                int direction;
                scanf("%d", &direction);
                printf("Enter distance: ");
                int distance;
                scanf("%d", &distance);
                time_travel(direction, distance);
                printf("Current time: %d\n", time_index);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}