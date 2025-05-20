//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100       //maximum number of data points
#define K 5         //number of clusters
#define THRESHOLD 0.1   //convergence threshold

//data point structure
typedef struct Point {
    double x;
    double y;
} Point;

//cluster structure
typedef struct Cluster {
    double x;
    double y;
    int count;
    Point* points;
} Cluster;

//function to read data points from file
void read_points(Point* points, int* n) {
    FILE* fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    *n = 0;
    while(!feof(fp) && *n < N) {
        fscanf(fp, "%lf,%lf", &(points[*n].x), &(points[*n].y));
        (*n)++;
    }
    fclose(fp);
}

//function to initialize K clusters
void init_clusters(Cluster* clusters) {
    for(int i=0; i<K; i++) {
        clusters[i].x = (double)rand()/(double)RAND_MAX;
        clusters[i].y = (double)rand()/(double)RAND_MAX;
        clusters[i].count = 0;
        clusters[i].points = (Point*)malloc(N*sizeof(Point));
    }
}

//function to find closest cluster to a point
int closest_cluster(Cluster* clusters, Point point) {
    int min_index = 0;
    double min_dist = sqrt((point.x - clusters[0].x)*(point.x - clusters[0].x) + 
                           (point.y - clusters[0].y)*(point.y - clusters[0].y));
    for(int i=1; i<K; i++) {
        double dist = sqrt((point.x - clusters[i].x)*(point.x - clusters[i].x) +
                           (point.y - clusters[i].y)*(point.y - clusters[i].y));
        if(dist < min_dist) {
            min_index = i;
            min_dist = dist;
        }
    }
    return min_index;
}

//function to perform K-means clustering
void k_means(Point* points, Cluster* clusters, int n) {
    double old_x[K], old_y[K];
    int iter = 0;
    double diff = 1.0;
    while(diff > THRESHOLD && iter < 1000) {    //convergence criteria
        for(int i=0; i<K; i++) {
            old_x[i] = clusters[i].x;
            old_y[i] = clusters[i].y;
            clusters[i].count = 0;
        }
        for(int i=0; i<n; i++) {
            int index = closest_cluster(clusters, points[i]);
            clusters[index].points[clusters[index].count++] = points[i];
            clusters[index].x += points[i].x;
            clusters[index].y += points[i].y;
        }
        for(int i=0; i<K; i++) {
            if(clusters[i].count > 0) {
                clusters[i].x /= clusters[i].count;
                clusters[i].y /= clusters[i].count;
            }
        }
        diff = 0.0;
        for(int i=0; i<K; i++) {
            diff += sqrt((clusters[i].x - old_x[i])*(clusters[i].x - old_x[i]) + 
                         (clusters[i].y - old_y[i])*(clusters[i].y - old_y[i]));
        }
        iter++;
    }
    printf("Converged in %d iterations.\n", iter);
}

//function to print clusters
void print_clusters(Cluster* clusters) {
    for(int i=0; i<K; i++) {
        printf("Cluster %d (%d points):\n", i+1, clusters[i].count);
        for(int j=0; j<clusters[i].count; j++) {
            printf("\t(%lf,%lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\tCenter = (%lf,%lf)\n", clusters[i].x, clusters[i].y);
    }
}

int main() {
    Point points[N];
    int n;
    read_points(points, &n);
    Cluster clusters[K];
    init_clusters(clusters);
    k_means(points, clusters, n);
    print_clusters(clusters);
    return 0;
}