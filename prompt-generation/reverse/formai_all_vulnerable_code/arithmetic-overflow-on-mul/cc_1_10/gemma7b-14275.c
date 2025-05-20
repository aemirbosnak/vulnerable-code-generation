//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void find_nearest_point(int x, int y, int **points, int num_points)
{
    int i;
    int min_distance = MAX;
    int nearest_point = -1;

    for (i = 0; i < num_points; i++)
    {
        int dx = x - points[i][0];
        int dy = y - points[i][1];
        int distance = sqrt(dx * dx + dy * dy);

        if (distance < min_distance)
        {
            min_distance = distance;
            nearest_point = i;
        }
    }

    printf("The nearest point to (%d, %d) is (%d, %d) with a distance of %.2lf\n", x, y, points[nearest_point][0], points[nearest_point][1], min_distance);
}

int main()
{
    int num_points = 5;
    int **points = (int **)malloc(num_points * sizeof(int *));
    points[0] = (int *)malloc(num_points * sizeof(int));
    points[1] = (int *)malloc(num_points * sizeof(int));

    points[0][0] = 1;
    points[0][1] = 1;
    points[1][0] = 2;
    points[1][1] = 2;
    points[2][0] = 3;
    points[2][1] = 3;
    points[3][0] = 4;
    points[3][1] = 4;
    points[4][0] = 5;
    points[4][1] = 5;

    find_nearest_point(2, 2, points, num_points);

    free(points[0]);
    free(points[1]);
    free(points);

    return 0;
}