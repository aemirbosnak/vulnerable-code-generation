//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//cluster struct to store coordinates and cluster id
struct cluster {
    double x;
    double y;
    int cluster_id;
};

//function to calculate Euclidean distance between two points
double calculate_distance(struct cluster p1, struct cluster p2) {
    double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return distance;
}

//function to assign each point to nearest cluster
void assign_cluster(int n, int k, struct cluster* points, struct cluster* centroids) {
    double min_distance, distance;
    int i, j, nearest_cluster_id;
    for(i=0; i<n; i++) {
        min_distance = 999999;
        for(j=0; j<k; j++) {
            distance = calculate_distance(points[i], centroids[j]);
            if(distance<min_distance) {
                min_distance = distance;
                nearest_cluster_id = j+1;
            }
        }
        points[i].cluster_id = nearest_cluster_id;
    }
}

//function to update centroid coordinates
void update_centroids(int n, int k, struct cluster* points, struct cluster* centroids) {
    double sum_x, sum_y;
    int i, j, count;
    for(i=0; i<k; i++) {
        sum_x = 0;
        sum_y = 0;
        count = 0;
        for(j=0; j<n; j++) {
            if(points[j].cluster_id==i+1) {
                sum_x += points[j].x;
                sum_y += points[j].y;
                count++;
            }
        }
        centroids[i].x = sum_x/count;
        centroids[i].y = sum_y/count;
    }
}

//function to check if two sets of centroids are same
int check_convergence(int k, struct cluster* centroids, struct cluster* old_centroids) {
    int i, flag = 0;
    for(i=0; i<k; i++) {
        if(centroids[i].x!=old_centroids[i].x || centroids[i].y!=old_centroids[i].y) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {

    //number of points
    int n = 10;
    //number of clusters
    int k = 2;
    //maximum number of iterations
    int max_iterations = 10;

    //array to store points
    struct cluster points[10] = {{1,1,0}, {1,2,0}, {2,1,0}, {2,3,0}, {3,3,0}, {4,5,0}, {5,4,0}, {6,5,0}, {6,6,0}, {7,7,0}};

    //initialize centroids randomly
    struct cluster centroids[2] = {{1,1,1}, {7,7,2}};

    int i, j, flag = 1;

    //repeat until convergence or max iterations reached
    while(max_iterations--) {
        //assign each point to nearest cluster
        assign_cluster(n, k, points, centroids);
        //update centroid coordinates
        update_centroids(n, k, points, centroids);

        //convergence check
        struct cluster old_centroids[2];
        for(i=0; i<k; i++) {
            old_centroids[i].x = centroids[i].x;
            old_centroids[i].y = centroids[i].y;
        }
        if(check_convergence(k, centroids, old_centroids)==0) {
            flag = 0;
            break;
        }
    }

    //print points and their cluster ids
    for(i=0; i<n; i++) {
        printf("Point (%.0lf,%.0lf) belongs to Cluster %d\n", points[i].x, points[i].y, points[i].cluster_id);
    }

    return 0;
}