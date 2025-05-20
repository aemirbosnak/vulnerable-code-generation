//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    int x;
    int y;
} point;

typedef struct cluster {
    int size;
    point* points;
} cluster;

int main() {
    point* points = NULL;
    int num_points = 0;
    FILE* fp_in = fopen("input.txt", "r");
    FILE* fp_out = fopen("output.txt", "w");

    if (fp_in == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    if (fp_out == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    while (fscanf(fp_in, "%d %d", &points[num_points].x, &points[num_points].y)!= EOF) {
        num_points++;
    }

    fclose(fp_in);

    printf("Read in %d points\n", num_points);

    point* centroids = (point*) malloc(num_points * sizeof(point));
    cluster* clusters = (cluster*) malloc(num_points * sizeof(cluster));

    for (int i = 0; i < num_points; i++) {
        clusters[i].size = 1;
        clusters[i].points = &points[i];
        centroids[i] = points[i];
    }

    int k = 3; // Number of clusters

    for (int iteration = 0; iteration < 1000; iteration++) {
        for (int i = 0; i < num_points; i++) {
            int min_dist = 100000;
            int min_index = -1;

            for (int j = 0; j < k; j++) {
                double dist = 0;

                for (int d = 0; d < 2; d++) {
                    dist += pow((centroids[j].x - points[i].x), 2) + pow((centroids[j].y - points[i].y), 2);
                }

                if (dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }

            if (clusters[i].points->x!= centroids[min_index].x || clusters[i].points->y!= centroids[min_index].y) {
                clusters[min_index].points->x = clusters[i].points->x;
                clusters[min_index].points->y = clusters[i].points->y;
                clusters[i].size = 0;
            }
        }

        for (int i = 0; i < num_points; i++) {
            clusters[i].size++;
        }

        for (int i = 0; i < k; i++) {
            double sum_x = 0;
            double sum_y = 0;

            for (int j = 0; j < clusters[i].size; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }

            centroids[i].x = sum_x / clusters[i].size;
            centroids[i].y = sum_y / clusters[i].size;
        }
    }

    for (int i = 0; i < num_points; i++) {
        if (clusters[i].points->x!= centroids[0].x && clusters[i].points->x!= centroids[1].x && clusters[i].points->x!= centroids[2].x) {
            clusters[0].points->x = clusters[i].points->x;
            clusters[0].points->y = clusters[i].points->y;
            clusters[i].size = 0;
        }

        if (clusters[i].points->x!= centroids[1].x && clusters[i].points->x!= centroids[2].x && clusters[i].points->x!= centroids[0].x) {
            clusters[1].points->x = clusters[i].points->x;
            clusters[1].points->y = clusters[i].points->y;
            clusters[i].size = 0;
        }

        if (clusters[i].points->x!= centroids[2].x && clusters[i].points->x!= centroids[0].x && clusters[i].points->x!= centroids[1].x) {
            clusters[2].points->x = clusters[i].points->x;
            clusters[2].points->y = clusters[i].points->y;
            clusters[i].size = 0;
        }
    }

    for (int i = 0; i < num_points; i++) {
        if (clusters[i].size == 0) {
            clusters[0].points->x = centroids[0].x;
            clusters[0].points->y = centroids[0].y;
            clusters[i].size = 1;
        }
    }

    for (int i = 0; i < num_points; i++) {
        printf("%d %d\n", clusters[i].points->x, clusters[i].points->y);
    }

    fclose(fp_out);
    free(centroids);
    free(clusters);

    return 0;
}