//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point center;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

void print_header() {
    printf("#############################\n");
    printf("#   K-Means Clustering      #\n");
    printf("#############################\n\n");
}

double euclidean_distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a.coordinates[i] - b.coordinates[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], int k, Point points[], int n) {
    for (int i = 0; i < k; i++) {
        clusters[i].center = points[i];  // Initialize cluster center with the first k points
        clusters[i].point_count = 0;      // Reset point count for each cluster
    }
}

int assign_points_to_clusters(Cluster clusters[], int k, Point points[], int n) {
    int changed = 0;
    for (int i = 0; i < n; i++) {
        int closest_cluster = 0;
        double closest_distance = euclidean_distance(points[i], clusters[0].center);
        
        for (int j = 1; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].center);
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_cluster = j;
            }
        }
        
        if (clusters[closest_cluster].point_count < MAX_POINTS) {
            clusters[closest_cluster].points[clusters[closest_cluster].point_count++] = points[i];
            changed = 1; // Indicates a point was assigned to a cluster
        }
    }
    return changed;
}

void update_cluster_centers(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].point_count == 0) continue;

        for (int j = 0; j < DIMENSIONS; j++) {
            double sum = 0.0;
            for (int p = 0; p < clusters[i].point_count; p++) {
                sum += clusters[i].points[p].coordinates[j];
            }
            clusters[i].center.coordinates[j] = sum / clusters[i].point_count;  // Update the center
        }
    }
}

void display_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d - Center: (%.2f, %.2f) | Points: ", i + 1, clusters[i].center.coordinates[0], clusters[i].center.coordinates[1]);
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("(%f, %f) ", clusters[i].points[j].coordinates[0], clusters[i].points[j].coordinates[1]);
        }
        printf("\n");
    }
}

int main() {
    print_header();

    int k, n, iterations = 0;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];

    printf("Enter the number of points: ");
    scanf("%d", &n);
    
    printf("Enter the number of clusters: ");
    scanf("%d", &k);
    
    if (k > MAX_CLUSTERS || n > MAX_POINTS) {
        printf("Exceeds max limit for points or clusters!\n");
        return 1;
    }

    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    initialize_clusters(clusters, k, points, n);
    
    int changed;
    do {
        for (int i = 0; i < k; i++) {
            clusters[i].point_count = 0;  // Reset point counts before each iteration
        }

        changed = assign_points_to_clusters(clusters, k, points, n);
        update_cluster_centers(clusters, k);
        iterations++;
    } while (changed);

    printf("\nFinal Clusters after %d iterations:\n", iterations);
    display_clusters(clusters, k);

    return 0;
}