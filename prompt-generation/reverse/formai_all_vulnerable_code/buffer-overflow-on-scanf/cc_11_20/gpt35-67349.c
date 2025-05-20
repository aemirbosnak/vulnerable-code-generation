//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 1000
#define MIN_DISTANCE 0.001
#define INFINITY 1e5

int main()
{
    int n;
    double points[MAX_POINTS][2], centroids[MAX_POINTS][2];
    int membership[MAX_POINTS];
    int i, j, k;
    double min_distance, distance;
    double sum_x, sum_y;
    int num_points;
    int iterations = 0;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the points (x, y):\n");

    for(i = 0; i < n; i++)
    {
        scanf("%lf%lf", &points[i][0], &points[i][1]);
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    for(i = 0; i < k; i++)
    {
        centroids[i][0] = points[i][0];
        centroids[i][1] = points[i][1];
    }

    while(iterations < MAX_ITERATIONS)
    {
        for(i = 0; i < n; i++)
        {
            min_distance = INFINITY;

            for(j = 0; j < k; j++)
            {
                distance = sqrt(pow(points[i][0] - centroids[j][0], 2) +
                                pow(points[i][1] - centroids[j][1], 2));

                if(distance < min_distance)
                {
                    min_distance = distance;
                    membership[i] = j;
                }
            }
        }

        for(j = 0; j < k; j++)
        {
            num_points = 0;
            sum_x = 0;
            sum_y = 0;

            for(i = 0; i < n; i++)
            {
                if(membership[i] == j)
                {
                    num_points++;
                    sum_x += points[i][0];
                    sum_y += points[i][1];
                }
            }

            if(num_points > 0)
            {
                centroids[j][0] = sum_x / num_points;
                centroids[j][1] = sum_y / num_points;
            }
        }

        iterations++;

        if(min_distance < MIN_DISTANCE)
        {
            break;
        }
    }

    printf("Result:\n");

    for(i = 0; i < k; i++)
    {
        printf("Cluster %d: (", i+1);

        for(j = 0; j < n; j++)
        {
            if(membership[j] == i)
            {
                printf("(%lf,%lf)", points[j][0], points[j][1]);
            }
        }

        printf(")\n");
    }

    return 0;
}