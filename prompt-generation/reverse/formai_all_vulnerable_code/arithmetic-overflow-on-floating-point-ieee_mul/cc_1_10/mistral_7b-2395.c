//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define CITY_SIZE 50
#define HEXAGON_SIDE_LENGTH sqrt(3.0 * pow(CITY_SIZE, 2) / 2.0)

typedef struct {
    double x, y;
} Point;

Point grid_points[CITY_SIZE * CITY_SIZE];
int grid_points_count = 0;

void generate_grid_points() {
    int i = 0;
    for (int x = 0; x < CITY_SIZE; x++) {
        for (int y = 0; y < CITY_SIZE; y++) {
            grid_points[i++] = (Point) {
                .x = x * HEXAGON_SIDE_LENGTH + HEXAGON_SIDE_LENGTH / 2.0,
                .y = y * HEXAGON_SIDE_LENGTH * sqrt(3.0) / 2.0
            };
        }
    }
    grid_points_count = i;
}

int find_nearest_neighbor_index(Point point) {
    int min_distance_index = 0;
    double min_distance = pow(HEXAGON_SIDE_LENGTH, 2);

    for (int i = 0; i < grid_points_count; i++) {
        double dx = grid_points[i].x - point.x;
        double dy = grid_points[i].y - point.y;
        double distance = pow(dx, 2) + pow(dy, 2);

        if (distance < min_distance) {
            min_distance = distance;
            min_distance_index = i;
        }
    }

    return min_distance_index;
}

int main() {
    srand(time(NULL));

    generate_grid_points();

    Point new_building;
    new_building.x = rand() % (CITY_SIZE * 2) + (CITY_SIZE * 2) / 2.0;
    new_building.y = rand() % (CITY_SIZE * 2) + (CITY_SIZE * 2) / 2.0;

    int nearest_neighbor_index = find_nearest_neighbor_index(new_building);

    printf("New building site at (%lf, %lf) has the nearest neighbor at (%lf, %lf)\n",
           new_building.x, new_building.y,
           grid_points[nearest_neighbor_index].x,
           grid_points[nearest_neighbor_index].y);

    return 0;
}