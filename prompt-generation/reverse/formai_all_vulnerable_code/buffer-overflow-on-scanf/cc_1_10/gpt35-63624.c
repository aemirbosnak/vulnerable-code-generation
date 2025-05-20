//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_DIMENSIONS 10

int numberOfPoints;
int numberOfClusters;
double points[MAX_POINTS][MAX_DIMENSIONS];
double centroids[MAX_POINTS][MAX_DIMENSIONS];
int clusterIndices[MAX_POINTS];

double squaredEuclideanDistance(double point1[], double point2[])
{
    int i;
    double distance = 0;
    for (i = 0; i < MAX_DIMENSIONS; i++)
    {
        distance += pow(point1[i] - point2[i], 2);
    }
    return distance;
}

void assignClusters()
{
    int i, j;
    double minDistance, distance;
    for (i = 0; i < numberOfPoints; i++)
    {
        minDistance = INFINITY;
        for (j = 0; j < numberOfClusters; j++)
        {
            distance = squaredEuclideanDistance(points[i], centroids[j]);
            if (distance < minDistance)
            {
                minDistance = distance;
                clusterIndices[i] = j;
            }
        }
    }
}

void updateCentroids()
{
    int i, j, count;
    double sum[MAX_DIMENSIONS];
    for (i = 0; i < numberOfClusters; i++)
    {
        count = 0;
        for (j = 0; j < MAX_DIMENSIONS; j++)
        {
            sum[j] = 0;
        }
        for (j = 0; j < numberOfPoints; j++)
        {
            if (i == clusterIndices[j])
            {
                count++;
                for (int k = 0; k < MAX_DIMENSIONS; k++)
                {
                    sum[k] += points[j][k];
                }
            }
        }
        for (j = 0; j < MAX_DIMENSIONS; j++)
        {
            centroids[i][j] = count ? sum[j] / count : centroids[i][j];
        }
    }
}

int main()
{
    printf("Enter number of points: ");
    scanf("%d", &numberOfPoints);

    int i, j;
    printf("Enter points:\n");
    for (i = 0; i < numberOfPoints; i++)
    {
        for (j = 0; j < MAX_DIMENSIONS; j++)
        {
            scanf("%lf", &points[i][j]);
        }
        clusterIndices[i] = -1;
    }

    printf("Enter number of clusters: ");
    scanf("%d", &numberOfClusters);

    if (numberOfClusters > numberOfPoints)
    {
        printf("Error: number of clusters cannot be greater than number of points.\n");
        return 1;
    }

    printf("Enter initial centroids:\n");
    for (i = 0; i < numberOfClusters; i++)
    {
        for (j = 0; j < MAX_DIMENSIONS; j++)
        {
            scanf("%lf", &centroids[i][j]);
        }
        clusterIndices[i] = i;
    }

    int iterations = 0;
    int maxIterations = 100;
    while (iterations < maxIterations)
    {
        assignClusters();
        updateCentroids();
        iterations++;
    }

    printf("Final clusters:\n");
    for (i = 0; i < numberOfPoints; i++)
    {
        printf("%d ", clusterIndices[i]);
    }
    printf("\n");

    return 0;
}