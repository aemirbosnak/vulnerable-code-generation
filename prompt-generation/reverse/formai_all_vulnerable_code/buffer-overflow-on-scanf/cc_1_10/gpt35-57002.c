//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct
{
    double x;
    double y;
} Point;

typedef struct
{
    Point points[MAX_POINTS];
    int count;
} Polygon;

double distance(Point p1, Point p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double perimeter(Polygon *polygon)
{
    double perimeter = 0.0, dist;
    int i;

    for (i = 1; i < polygon->count; i++)
    {
        dist = distance(polygon->points[i-1], polygon->points[i]);
        perimeter += dist;
    }

    dist = distance(polygon->points[i-1], polygon->points[0]);
    perimeter += dist;
    return perimeter;
}

double area(Polygon *polygon)
{
    double area = 0.0;
    int i;

    for (i = 0; i < polygon->count; i++)
    {
        int j = (i + 1) % polygon->count;
        area += polygon->points[i].x * polygon->points[j].y - polygon->points[j].x * polygon->points[i].y;
    }

    return 0.5 * fabs(area);
}

int main()
{
    Polygon polygon;
    int i, n;

    printf("Enter number of points in polygon: ");
    scanf("%d", &n);

    if (n > MAX_POINTS)
    {
        printf("Error: too many points\n");
        return 1;
    }

    polygon.count = n;

    for (i = 0; i < n; i++)
    {
        printf("Enter x coordinate of point %d: ", i+1);
        scanf("%lf", &polygon.points[i].x);

        printf("Enter y coordinate of point %d: ", i+1);
        scanf("%lf", &polygon.points[i].y);
    }

    printf("Perimeter of polygon is: %lf\n", perimeter(&polygon));
    printf("Area of polygon is: %lf\n", area(&polygon));

    return 0;
}