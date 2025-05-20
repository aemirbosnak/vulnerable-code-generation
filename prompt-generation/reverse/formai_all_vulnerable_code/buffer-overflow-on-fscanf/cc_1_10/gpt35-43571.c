//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Struct to store data points
typedef struct data_point {
    double x;
    double y;
} DataPoint;

//Struct to store cluster attributes
typedef struct cluster {
    DataPoint centroid;
    DataPoint *points;
    int num_points;
} Cluster;

//Function to read a file of data points
DataPoint *read_file(char *filename, int *num_points) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", num_points);
    DataPoint *data = (DataPoint *)malloc(*num_points * sizeof(DataPoint));
    for (int i = 0; i < *num_points; i++) {
        fscanf(file, "%lf,%lf", &(data[i].x), &(data[i].y));
    }

    fclose(file);
    return data;
}

//Function to randomly initialize k clusters
Cluster *init_clusters(DataPoint *data, int num_points, int k) {
    Cluster *clusters = (Cluster *)malloc(k * sizeof(Cluster));
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = data[rand() % num_points];
        clusters[i].points = NULL;
        clusters[i].num_points = 0;
    }
    return clusters;
}

//Function to calculate the Euclidean distance between two data points
double distance(DataPoint a, DataPoint b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

//Function to assign each data point to its nearest cluster
void assign_points(Cluster *clusters, DataPoint *data, int num_points, int k) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster;
        for (int j = 0; j < k; j++) {
            double d = distance(data[i], clusters[j].centroid);
            if (d < min_distance) {
                min_distance = d;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points = (DataPoint *)realloc(clusters[closest_cluster].points, (clusters[closest_cluster].num_points + 1) * sizeof(DataPoint));
        clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = data[i];
    }
}

//Function to update cluster centroids to the mean of the points assigned to it
void update_centroids(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        double sum_x = 0, sum_y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].num_points;
        clusters[i].centroid.y = sum_y / clusters[i].num_points;
        free(clusters[i].points);
        clusters[i].points = NULL;
        clusters[i].num_points = 0;
    }
}

//Function to check if two sets of clusters are equal
int equal_clusters(Cluster *a, Cluster *b, int k) {
    for (int i = 0; i < k; i++) {
        if (a[i].centroid.x != b[i].centroid.x || a[i].centroid.y != b[i].centroid.y) {
            return 0;
        }
    }
    return 1;
}

//Function to print the clusters
void print_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: (%.2lf,%.2lf)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("\t(%.2lf,%.2lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

//Main function
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <k>\n", argv[0]);
        return 0;
    }

    int num_points;
    DataPoint *data = read_file(argv[1], &num_points);
    int k = atoi(argv[2]);

    Cluster *clusters = init_clusters(data, num_points, k);

    int iter = 0;
    do {
        assign_points(clusters, data, num_points, k);
        Cluster *prev_clusters = (Cluster *)malloc(k * sizeof(Cluster));
        memcpy(prev_clusters, clusters, k * sizeof(Cluster));
        update_centroids(clusters, k);
        iter++;
        if (equal_clusters(prev_clusters, clusters, k)) {
            break;
        }
        free(prev_clusters);
    } while (1);

    printf("Converged after %d iterations\n", iter);
    print_clusters(clusters, k);

    free(clusters);
    free(data);

    return 0;
}