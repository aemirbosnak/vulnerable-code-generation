//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Defining constants */
#define MAX_POINTS 100
#define CLUSTERS 3
#define E 0.0002

/* Structure definition for point */
typedef struct {
    float x;
    float y;
} point;

/* Function definition */
float distance(point a, point b);
int assign_cluster(point p, point c[]);
point find_mean(point points[], int size);
void reassign_centers(point points[], point center[]);
int check_convergence(point prev_centers[], point centers[]);

/* Main function */
int main() {
    point points[MAX_POINTS], center[CLUSTERS], prev_centers[CLUSTERS];
    int i, j, cluster_assigned[MAX_POINTS], iterations = 0, converged;

    /* Reading input data */
    printf("Enter x and y coordinates of points:\n");
    for(i = 0; i < MAX_POINTS; i++) {
        scanf("%f%f", &points[i].x, &points[i].y);
        if(points[i].x == -1 && points[i].y == -1) {
            /* End of input */
            break;
        }
    }

    /* Initializing random centers */
    for(i = 0; i < CLUSTERS; i++) {
        center[i].x = points[rand() % MAX_POINTS].x;
        center[i].y = points[rand() % MAX_POINTS].y;
    }

    /* Assigning clusters */
    do {
        /* Store previous centers */
        for(i = 0; i < CLUSTERS; i++) {
            prev_centers[i].x = center[i].x;
            prev_centers[i].y = center[i].y;
        }

        /* Assigning each point to nearest center */
        for(i = 0; i < MAX_POINTS; i++) {
            cluster_assigned[i] = assign_cluster(points[i], center);
        }

        /* Finding new centers */
        reassign_centers(points, center);

        /* Incrementing iterations */
        iterations++;

        /* Checking convergence */
        converged = check_convergence(prev_centers, center);

    } while(!converged);

    /* Displaying Results */
    for(i = 0; i < CLUSTERS; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Center: (%f, %f)\n", center[i].x, center[i].y);
        printf("Points:\n");
        for(j = 0; j < MAX_POINTS; j++) {
            if(cluster_assigned[j] == i) {
                printf("(%f, %f)\n", points[j].x, points[j].y);
            }
        }
        printf("\n");
    }

    printf("Total Iterations: %d\n", iterations);

    return 0;
}

/* Function to calculate distance between two points */
float distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

/* Function to assign each point to nearest center */
int assign_cluster(point p, point c[]) {
    int i, min_index;
    float min_dist = distance(p, c[0]), temp_dist;
    for(i = 1; i < CLUSTERS; i++) {
        temp_dist = distance(p, c[i]);
        if(temp_dist < min_dist) {
            min_index = i;
            min_dist = temp_dist;
        }
    }
    return min_index;
}

/* Function to find mean of all points in a cluster */
point find_mean(point points[], int size) {
    int i;
    point p, mean;
    float sum_x = 0, sum_y = 0;
    for(i = 0; i < size; i++) {
        sum_x += points[i].x;
        sum_y += points[i].y;
    }
    mean.x = sum_x / size;
    mean.y = sum_y / size;
    return mean;
}

/* Function to reassign centers */
void reassign_centers(point points[], point center[]) {
    point cluster[CLUSTERS][MAX_POINTS];
    int i, j, cluster_size[CLUSTERS] = {0};

    /* Assigning each point to its cluster */
    for(i = 0; i < MAX_POINTS; i++) {
        cluster[assign_cluster(points[i], center)][cluster_size[assign_cluster(points[i], center)]] = points[i];
        cluster_size[assign_cluster(points[i], center)]++;
    }

    /* Finding mean of each cluster */
    for(i = 0; i < CLUSTERS; i++) {
        if(cluster_size[i] > 0) {
            center[i] = find_mean(cluster[i], cluster_size[i]);
        }
    }
}

/* Function to check convergence */
int check_convergence(point prev_centers[], point centers[]) {
    int i;
    float total_dist = 0, diff;
    for(i = 0; i < CLUSTERS; i++) {
        total_dist += distance(prev_centers[i], centers[i]);
    }
    diff = fabs(total_dist);
    if(diff <= E) {
        return 1;
    }
    else {
        return 0;
    }
}