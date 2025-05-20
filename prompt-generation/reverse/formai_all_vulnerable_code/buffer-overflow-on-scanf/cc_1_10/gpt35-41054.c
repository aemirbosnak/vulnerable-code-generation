//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 1000

// Structure to store co-ordinates of a vertex
typedef struct {
    double x, y;
} Point;

// Structure to store an edge
typedef struct {
    int u, v;
} Edge;

// Function to calculate distance between two points
double euclidean_distance(Point p1, Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
    return distance;
}

// Function to calculate cross product of two vectors
double cross_product(Point p1, Point p2, Point p3) {
    double v1_x = p2.x - p1.x;
    double v1_y = p2.y - p1.y;
    double v2_x = p3.x - p1.x;
    double v2_y = p3.y - p1.y;
    double cross_prod = v1_x * v2_y - v2_x * v1_y;
    return cross_prod;
}

// Function to check if a point lies inside a triangle
int point_in_triangle(Point p, Point v1, Point v2, Point v3) {
    double area1 = cross_product(v1, v2, p);
    double area2 = cross_product(v2, v3, p);
    double area3 = cross_product(v3, v1, p);
    if((area1 > 0 && area2 > 0 && area3 > 0) || (area1 < 0 && area2 < 0 && area3 < 0))
        return 1;
    return 0;
}

int main() {
    int n, m, i, j, k, u, v, w;
    Point vertices[MAX_VERTICES];
    Edge edges[MAX_EDGES];
    double distances[MAX_VERTICES][MAX_VERTICES];
    int in_triangle[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the co-ordinates of the vertices:\n");
    for(i = 0; i < n; i++)
       scanf("%lf %lf", &vertices[i].x, &vertices[i].y);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges:\n");
    for(i = 0; i < m; i++)
        scanf("%d %d", &edges[i].u, &edges[i].v);

    // Calculating distances between the vertices
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(i != j)
                distances[i][j] = euclidean_distance(vertices[i], vertices[j]);

    // Checking if a vertex lies inside a triangle
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < m; k++) {
                u = edges[k].u;
                v = edges[k].v;
                if(u != i && u != j && v != i && v != j && point_in_triangle(vertices[i], vertices[u], vertices[j], vertices[v]))
                    in_triangle[i][j] = 1;
            }

    // Printing the input
    printf("The input is:\n");
    printf("%d\n", n);
    for(i = 0; i < n; i++)
        printf("%lf %lf\n", vertices[i].x, vertices[i].y);
    printf("%d\n", m);
    for(i = 0; i < m; i++)
        printf("%d %d\n", edges[i].u, edges[i].v);

    // Printing the distances
    printf("The distances are:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%lf ", distances[i][j]);
        printf("\n");
    }

    // Printing if a vertex lies inside a triangle
    printf("If a vertex lies inside a triangle:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", in_triangle[i][j]);
        printf("\n");
    }

    return 0;
}