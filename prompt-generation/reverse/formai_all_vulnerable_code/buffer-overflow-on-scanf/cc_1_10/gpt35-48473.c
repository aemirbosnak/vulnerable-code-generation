//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5
#define MIN_FLOAT -100000

//Data structure to store the points
typedef struct Point {
    float x;
    float y;
} Point;

//Data structure to store a cluster
typedef struct Cluster {
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

//Returns the Euclidean distance between two points
float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

//Returns the index of the nearest cluster to a point
int get_nearest_cluster(Point p, Cluster clusters[], int num_clusters) {
    int index = 0;
    float min_distance = MIN_FLOAT;
    for(int i=0; i<num_clusters; i++) {
        float d = distance(p, clusters[i].centroid);
        if(min_distance < 0 || d < min_distance) {
            index = i;
            min_distance = d;
        }
    }
    return index;
}

int main() {
    int num_points, num_clusters, max_iterations;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];

    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    printf("Enter the coordinates of the points (use space to separate them):\n");
    for(int i=0; i<num_points; i++) {
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    //Initializing the clusters
    for(int i=0; i<num_clusters; i++) {
        clusters[i].centroid = points[i];
        clusters[i].num_points = 0;
    }

    //Running the algorithm
    int iteration = 0;
    while(iteration < max_iterations) {
        //Assignment step
        for(int i=0; i<num_points; i++) {
            int nearest_cluster = get_nearest_cluster(points[i], clusters, num_clusters);
            clusters[nearest_cluster].points[clusters[nearest_cluster].num_points++] = points[i];
        }

        //Update step
        for(int i=0; i<num_clusters; i++) {
            float sum_x = 0, sum_y = 0;
            for(int j=0; j<clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }

        iteration++;
    }

    //Printing the results
    printf("Final clusters:\n");
    for(int i=0; i<num_clusters; i++) {
        printf("Cluster %d\n", i+1);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points:\n");
        for(int j=0; j<clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}