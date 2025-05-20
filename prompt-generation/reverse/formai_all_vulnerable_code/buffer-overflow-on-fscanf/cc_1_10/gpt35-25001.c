//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000 //maximum number of data points
#define K 5 //number of clusters
#define D 2 //number of dimensions

int n; //number of data points
double data[N][D]; //data points
double centroids[K][D]; //cluster centroids
int labels[N]; //labels for each data point

double distance(double *x, double *y, int dim) {
    double sum = 0;
    for (int i = 0; i < dim; i++) {
        sum += pow(x[i] - y[i], 2);
    }
    return sqrt(sum);
}

void kmeans() {
    //initialize centroids randomly
    for (int i = 0; i < K; i++) {
        int rand_idx = rand() % n;
        for (int j = 0; j < D; j++) {
            centroids[i][j] = data[rand_idx][j];
        }
    }

    int iter = 0;
    int max_iter = 100;

    while (iter < max_iter) {
        //assign points to nearest centroid
        for (int i = 0; i < n; i++) {
            double min_dist = INFINITY;
            int min_idx;
            for (int j = 0; j < K; j++) {
                double dist = distance(data[i], centroids[j], D);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_idx = j;
                }
            }
            labels[i] = min_idx;
        }

        //compute new centroids
        double new_centroids[K][D] = {0};
        int cluster_sizes[K] = {0};
        for (int i = 0; i < n; i++) {
            int label = labels[i];
            for (int j = 0; j < D; j++) {
                new_centroids[label][j] += data[i][j];
            }
            cluster_sizes[label]++;
        }
        for (int i = 0; i < K; i++) {
            if (cluster_sizes[i] > 0) {
                for (int j = 0; j < D; j++) {
                    centroids[i][j] = new_centroids[i][j] / cluster_sizes[i];
                }
            }
        }

        iter++;
    }
}

int main() {
    //read data from file
    FILE *fp = fopen("data.txt", "r");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    n = 0;
    while (fscanf(fp, "%lf,%lf", &data[n][0], &data[n][1]) == 2) {
        n++;
    }

    fclose(fp);

    //run k-means
    kmeans();

    //print results
    for (int i = 0; i < K; i++) {
        printf("Cluster %d:\n", i+1);
        for (int j = 0; j < n; j++) {
            if (labels[j] == i) {
                printf("(%f,%f)\n", data[j][0], data[j][1]);
            }
        }
        printf("\n");
    }

    return 0;
}