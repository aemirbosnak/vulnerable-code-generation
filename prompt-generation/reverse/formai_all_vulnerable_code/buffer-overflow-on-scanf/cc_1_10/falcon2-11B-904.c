//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int visited[MAX_ROWS][MAX_COLS];
int row, col, startx, starty, endx, endy;

void initialize_visited() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            visited[i][j] = 0;
        }
    }
}

void print_visited() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

void print_path() {
    if (row == endy && col == endx) {
        printf("Path found!\n");
    } else {
        printf("Move to (%d, %d)\n", row, col);
    }
}

void dijkstra_algorithm() {
    int current_node, min_distance = MAX_ROWS * MAX_COLS;
    int distance[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            distance[i][j] = -1;
        }
    }

    distance[startx][starty] = 0;
    initialize_visited();

    while (min_distance > 0) {
        current_node = -1;
        min_distance = MAX_ROWS * MAX_COLS;

        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                if (distance[i][j]!= -1 && distance[i][j] < min_distance &&!visited[i][j]) {
                    current_node = i * MAX_COLS + j;
                    min_distance = distance[i][j];
                }
            }
        }

        print_path();
        visited[current_node/MAX_COLS][current_node%MAX_COLS] = 1;

        for (int k = 0; k < MAX_ROWS; k++) {
            for (int l = 0; l < MAX_COLS; l++) {
                if (distance[k][l]!= -1 && visited[k][l] == 0) {
                    if (distance[k][l] + 1 < distance[current_node/MAX_COLS][current_node%MAX_COLS]) {
                        distance[k][l] = distance[current_node/MAX_COLS][current_node%MAX_COLS] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    int max_x, max_y;

    printf("Enter the maximum rows and columns: ");
    scanf("%d %d", &max_x, &max_y);

    printf("Enter the starting and ending coordinates: ");
    scanf("%d %d %d %d", &startx, &starty, &endx, &endy);

    initialize_visited();

    dijkstra_algorithm();

    return 0;
}