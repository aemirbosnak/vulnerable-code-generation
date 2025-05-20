//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100   // maximum number of iterations
#define THRESHOLD 0.001 // minimum distance threshold for convergence

// global variables
int n;       // number of data points
int k;       // number of clusters
int dim;     // dimensionality of data
float **data; // data to be clustered

// prototypes
void initialize(float **centroids);
float distance(float *point, float *centroid);
void assign_clusters(float **centroids, int *cluster_assignments);
void update_centroids(float **centroids, int *cluster_assignments);
float objective_function(float **centroids, int *cluster_assignments);
void print_clusters(float **centroids, int *cluster_assignments);

void kmeans()
{
    // initialize centroids randomly
    float **centroids = malloc(k * sizeof(float *));
    for (int i = 0; i < k; i++)
    {
        centroids[i] = malloc(dim * sizeof(float));
    }
    initialize(centroids);

    // initialize cluster assignments to -1
    int *cluster_assignments = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cluster_assignments[i] = -1;
    }

    // run k-means algorithm
    int iter = 0;
    float prev_obj = objective_function(centroids, cluster_assignments);
    float curr_obj = prev_obj;
    while (iter < MAX_ITER && fabs(curr_obj - prev_obj) > THRESHOLD)
    {
        // assign data points to closest cluster
        assign_clusters(centroids, cluster_assignments);

        // update centroids
        update_centroids(centroids, cluster_assignments);

        // calculate objective function
        prev_obj = curr_obj;
        curr_obj = objective_function(centroids, cluster_assignments);

        // update iteration counter
        iter++;
    }

    // print final cluster assignments
    print_clusters(centroids, cluster_assignments);

    // free memory
    for (int i = 0; i < k; i++)
    {
        free(centroids[i]);
    }
    free(centroids);
    free(cluster_assignments);
}

void initialize(float **centroids)
{
    // randomly select k data points as initial centroids
    int *indices = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }
    for (int i = 0; i < k; i++)
    {
        int j = rand() % n;
        int temp = indices[j];
        indices[j] = indices[n-1];
        indices[n-1] = temp;
        for (int d = 0; d < dim; d++)
        {
            centroids[i][d] = data[temp][d];
        }
        n--;
    }
    free(indices);
}

float distance(float *point, float *centroid)
{
    float dist = 0.0;
    for (int d = 0; d < dim; d++)
    {
        dist += pow(point[d] - centroid[d], 2);
    }
    return sqrt(dist);
}

void assign_clusters(float **centroids, int *cluster_assignments)
{
    for (int i = 0; i < n; i++)
    {
        float min_dist = INFINITY;
        int min_cluster = -1;
        for (int j = 0; j < k; j++)
        {
            float dist = distance(data[i], centroids[j]);
            if (dist < min_dist)
            {
                min_dist = dist;
                min_cluster = j;
            }
        }
        cluster_assignments[i] = min_cluster;
    }
}

void update_centroids(float **centroids, int *cluster_assignments)
{
    int *counts = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        counts[i] = 0;
        for (int d = 0; d < dim; d++)
        {
            centroids[i][d] = 0.0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = cluster_assignments[i];
        counts[j]++;
        for (int d = 0; d < dim; d++)
        {
            centroids[j][d] += data[i][d];
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (counts[i] == 0)
        {
            // reinitialize empty clusters
            for (int d = 0; d < dim; d++)
            {
                centroids[i][d] = data[rand() % n][d];
            }
        }
        else
        {
            // update non-empty clusters
            for (int d = 0; d < dim; d++)
            {
                centroids[i][d] /= counts[i];
            }
        }
    }
    free(counts);
}

float objective_function(float **centroids, int *cluster_assignments)
{
    float obj = 0.0;
    for (int i = 0; i < n; i++)
    {
        int j = cluster_assignments[i];
        obj += pow(distance(data[i], centroids[j]), 2);
    }
    return obj;
}

void print_clusters(float **centroids, int *cluster_assignments)
{
    printf("Final cluster assignments:\n");
    for (int i = 0; i < k; i++)
    {
        printf("Cluster %d:", i);
        for (int j = 0; j < n; j++)
        {
            if (cluster_assignments[j] == i)
            {
                printf(" %d", j);
            }
        }
        printf("\nCentroid:");
        for (int d = 0; d < dim; d++)
        {
            printf(" %.3f", centroids[i][d]);
        }
        printf("\n");
    }
}

int main()
{
    // set random seed
    srand(0);

    // read data from file
    FILE *fp = fopen("data.txt", "r");
    fscanf(fp, "%d %d %d", &n, &k, &dim);
    data = malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(dim * sizeof(float));
        for (int d = 0; d < dim; d++)
        {
            fscanf(fp, "%f", &data[i][d]);
        }
    }
    fclose(fp);

    // run k-means algorithm
    kmeans();

    // free memory
    for (int i = 0; i < n; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}