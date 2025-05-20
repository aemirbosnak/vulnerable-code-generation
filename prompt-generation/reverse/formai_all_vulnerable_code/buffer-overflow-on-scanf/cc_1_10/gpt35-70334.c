//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DATA_POINTS 100
#define MAX_CLUSTER_POINTS 10
#define THRESHOLD 0.001

struct Point {
    double x;
    double y;
};

struct Cluster {
    struct Point center;
    struct Point data_points[MAX_DATA_POINTS];
    int num_points;
};

int num_clusters;
struct Cluster clusters[MAX_CLUSTER_POINTS];

double euclidean_distance(struct Point a, struct Point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

bool is_same_cluster(struct Cluster a, struct Cluster b) {
    if (a.num_points != b.num_points) {
        return false;
    }
    for (int i = 0; i < a.num_points; i++) {
        bool found = false;
        for (int j = 0; j < b.num_points; j++) {
            if (a.data_points[i].x == b.data_points[j].x && a.data_points[i].y == b.data_points[j].y) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool cluster_data_points() {
    bool finished = true;
    for (int i = 0; i < num_clusters; i++) {
        int num_points = clusters[i].num_points;
        for (int j = 0; j < num_points; j++) {
            struct Point point = clusters[i].data_points[j];
            double min_distance = euclidean_distance(point, clusters[i].center);
            int min_index = i;
            for (int k = 0; k < num_clusters; k++) {
                double distance = euclidean_distance(point, clusters[k].center);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_index = k;
                }
            }
            if (min_index != i) {
                clusters[min_index].data_points[clusters[min_index].num_points++] = point;
                clusters[i].num_points--;
                clusters[i].data_points[j] = clusters[i].data_points[num_points - 1];
                j--;
                num_points--;
                finished = false;
            }
        }
    }
    return finished;
}

void update_center(struct Cluster *cluster) {
    int num_points = cluster->num_points;
    double x_sum = 0.0;
    double y_sum = 0.0;
    for (int i = 0; i < num_points; i++) {
        struct Point point = cluster->data_points[i];
        x_sum += point.x;
        y_sum += point.y;
    }
    cluster->center.x = x_sum / num_points;
    cluster->center.y = y_sum / num_points;
}

void k_means_clustering() {
    // initialize cluster centers to some data points
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].center = clusters[i].data_points[rand() % (clusters[i].num_points)];
    }
    bool finished = false;
    while (!finished) {
        finished = cluster_data_points();
        for (int i = 0; i < num_clusters; i++) {
            update_center(&clusters[i]);
        }
    }
}

int main() {
    printf("Enter the number of data points: ");
    int num_points;
    scanf("%d", &num_points);

    printf("Enter the data points as (x,y) coordinates:\n");
    for (int i = 0; i < num_points; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        int j = rand() % num_clusters;
        while (clusters[j].num_points == MAX_DATA_POINTS) {
            j = (j + 1) % num_clusters;
        }
        clusters[j].data_points[clusters[j].num_points++] = (struct Point){x, y};
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    k_means_clustering();

    printf("The data points have been clustered as follows:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d center: (%.2lf, %.2lf)\n", i+1, clusters[i].center.x, clusters[i].center.y);
        printf("Data points in Cluster %d:\n", i+1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%.2lf, %.2lf)\n", clusters[i].data_points[j].x, clusters[i].data_points[j].y);
        }
        printf("\n");
    }
    return 0;
}