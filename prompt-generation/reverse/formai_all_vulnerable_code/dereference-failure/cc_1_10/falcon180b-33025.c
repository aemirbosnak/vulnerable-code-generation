//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int size;
} PointSet;

void generate_points(PointSet *set) {
    srand(time(NULL));
    set->points = malloc(MAX_SIZE * sizeof(Point));
    set->size = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        Point p = {rand() / (double)RAND_MAX, rand() / (double)RAND_MAX};
        set->points[set->size++] = p;
    }
}

void kmeans(PointSet *set, int k, Point *centers) {
    int *assignments = malloc(set->size * sizeof(int));
    for (int i = 0; i < set->size; i++) {
        assignments[i] = -1;
    }

    for (int i = 0; i < k; i++) {
        centers[i] = set->points[rand() % set->size];
    }

    for (int iter = 0; iter < 100; iter++) {
        for (int i = 0; i < set->size; i++) {
            double min_dist = INFINITY;
            int best_center = -1;

            for (int j = 0; j < k; j++) {
                double dist = sqrt(pow(set->points[i].x - centers[j].x, 2) + pow(set->points[i].y - centers[j].y, 2));

                if (dist < min_dist) {
                    min_dist = dist;
                    best_center = j;
                }
            }

            if (assignments[i]!= best_center) {
                assignments[i] = best_center;
                centers[best_center] = (Point){0, 0};

                for (int j = 0; j < set->size; j++) {
                    if (assignments[j] == best_center) {
                        centers[best_center].x += set->points[j].x;
                        centers[best_center].y += set->points[j].y;
                    }
                }

                centers[best_center].x /= (double)kmeans_count_points(best_center, assignments, set);
                centers[best_center].y /= (double)kmeans_count_points(best_center, assignments, set);
            }
        }
    }

    free(assignments);
}

int kmeans_count_points(int center, int *assignments, PointSet *set) {
    int count = 0;

    for (int i = 0; i < set->size; i++) {
        if (assignments[i] == center) {
            count++;
        }
    }

    return count;
}

void print_centers(Point centers[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Center %d: (%lf, %lf)\n", i, centers[i].x, centers[i].y);
    }
}

int main() {
    PointSet set;
    generate_points(&set);

    int k = 3;
    Point centers[k];

    kmeans(&set, k, centers);

    printf("Centers:\n");
    print_centers(centers, k);

    return 0;
}