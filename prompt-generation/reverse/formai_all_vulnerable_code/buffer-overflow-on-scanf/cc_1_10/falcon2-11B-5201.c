//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA 1000

struct data_t {
    int x;
    int y;
};

int data[MAX_DATA];
int data_count;
int cluster_count;

int find_nearest_cluster(int x, int y) {
    int min_distance = 100000;
    int min_cluster = 0;
    for (int i = 0; i < cluster_count; i++) {
        int distance = sqrt((x - data[i * 2 + 0]) * (x - data[i * 2 + 0]) + (y - data[i * 2 + 1]) * (y - data[i * 2 + 1]));
        if (distance < min_distance) {
            min_distance = distance;
            min_cluster = i;
        }
    }
    return min_cluster;
}

void merge_clusters(int cluster_index, int data_index) {
    int i, j;
    for (i = 0; i < data_count; i++) {
        if (data[i * 2 + 0] == data_index) {
            data[i * 2 + 0] = cluster_index;
            data[i * 2 + 1] = cluster_index;
        }
    }
    data_count += data_index;
    data_index = 0;
    cluster_count--;
}

void assign_cluster(int x, int y) {
    int cluster_index = find_nearest_cluster(x, y);
    data[data_count * 2 + 0] = x;
    data[data_count * 2 + 1] = y;
    merge_clusters(cluster_index, data_count);
}

int main() {
    printf("Enter the number of data points: ");
    int num_data;
    scanf("%d", &num_data);

    for (int i = 0; i < num_data; i++) {
        printf("Enter the coordinates of data point %d: ", i + 1);
        scanf("%d %d", &data[i * 2 + 0], &data[i * 2 + 1]);
    }

    printf("Enter the number of clusters: ");
    int num_clusters;
    scanf("%d", &num_clusters);

    cluster_count = num_clusters;
    data_count = num_data;

    printf("Clustering algorithm output:\n");
    for (int i = 0; i < num_data; i++) {
        assign_cluster(data[i * 2 + 0], data[i * 2 + 1]);
    }

    printf("\n");
    for (int i = 0; i < cluster_count; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < data_count; j++) {
            printf("(%d, %d) ", data[j * 2 + 0], data[j * 2 + 1]);
        }
        printf("\n");
    }

    return 0;
}