//FormAI DATASET v1.0 Category: Data mining ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_POINTS 1000
#define MAX_ITERATIONS 100
#define MAX_DISTANCE 100000000

typedef struct {
    float x, y;
} Point;

int n, k;
Point points[MAX_POINTS];
Point medoids[MAX_POINTS];
int clusters[MAX_POINTS];

float euclidean_distance(Point p, Point q) {
    float x_diff = p.x - q.x;
    float y_diff = p.y - q.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int assign_clusters() {
    int i, j;
    float min_distance, distance;
    int cluster_id;
    int modified = 0;

    for (i = 0; i < n; i++) {
        min_distance = MAX_DISTANCE;
        for (j = 0; j < k; j++) {
            distance = euclidean_distance(points[i], medoids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_id = j;
            }
        }
        if (clusters[i] != cluster_id) {
            clusters[i] = cluster_id;
            modified = 1;
        }
    }

    return modified;
}

void compute_medoids() {
    int i, j, l;
    float min_sum_distance, sum_distance, distance;
    Point new_medoids[k];
    Point cluster_points[k][n];
    
    for (i = 0; i < k; i++) {
        min_sum_distance = MAX_DISTANCE;
        for (j = 0; j < n; j++) {
            if (clusters[j] == i) {
                sum_distance = 0;
                for (l = 0; l < n; l++) {
                    if (clusters[l] == i) {
                        distance = euclidean_distance(points[j], points[l]);
                        sum_distance += distance;
                    }
                }
                if (sum_distance < min_sum_distance) {
                    new_medoids[i] = points[j];
                    min_sum_distance = sum_distance;
                }
            }
        }
    }

    for (i = 0; i < k; i++) {
        medoids[i] = new_medoids[i];
    }
}

void print_clusters() {
    int i, j;
    for (i = 0; i < k; i++) {
        printf("Cluster %d: ", i);
        for (j = 0; j < n; j++) {
            if (clusters[j] == i) {
                printf("(%f,%f) ", points[j].x, points[j].y);
            }
        }
        printf("\n");
    }
}

int main() {
    int i;
    char filename[50];
    FILE *file_pointer;

    printf("Enter the file name (CSV format): ");
    scanf("%s", filename);

    file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    i = 0;
    while (fscanf(file_pointer, "%f,%f", &points[i].x, &points[i].y) != EOF) {
        i++;
    }
    n = i;

    fclose(file_pointer);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        medoids[i] = points[i];
    }

    int iteration;
    for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        printf("\nIteration %d:\n", iteration);
        if (!assign_clusters()) {
            break;
        }
        compute_medoids();
        print_clusters();
    }

    return 0;
}