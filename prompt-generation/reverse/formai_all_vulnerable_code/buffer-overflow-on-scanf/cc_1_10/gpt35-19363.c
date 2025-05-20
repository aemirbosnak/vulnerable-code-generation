//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
// This program demonstrates the geometric algorithm for calculating the convex hull of a set of points on a plane.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} point;

// Helper function to calculate the cross product of two vectors.
double cross_product(point a, point b, point c) {
    double area = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    return area;
}

// Comparison function for sorting points.
int compare_points(const void* p1, const void* p2) {
    point** pp1 = (point**) p1;
    point** pp2 = (point**) p2;
    point* p1p = *pp1;
    point* p2p = *pp2;
    
    double cp = cross_product(*p1p, *p2p, (point){0,0});
    if (cp > 0) return -1;
    else if (cp < 0) return 1;
    else return 0;
}

int main() {
    // Read in the number of points.
    int num_points;
    scanf("%d", &num_points);
    
    // Read in the points.
    point* points = malloc(sizeof(point)*num_points);
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &(points[i].x), &(points[i].y));
    }
    
    // Sort points counterclockwise.
    point** point_ptrs = malloc(sizeof(point*)*num_points);
    for (int i = 0; i < num_points; i++) {
        point_ptrs[i] = &(points[i]);
    }
    qsort(point_ptrs, num_points, sizeof(point*), compare_points);
    
    // Find the convex hull using Graham's scan.
    int stack_size = 0;
    point* stack = malloc(sizeof(point)*num_points);
    for (int i = 0; i < num_points; i++) {
        while (stack_size >= 2 && cross_product(stack[stack_size-2], stack[stack_size-1], *(point_ptrs[i])) <= 0) {
            stack_size--;
        }
        stack[stack_size] = *(point_ptrs[i]);
        stack_size++;
    }
    
    // Print the convex hull.
    printf("%d\n", stack_size);
    for (int i = 0; i < stack_size; i++) {
        printf("%.2lf %.2lf\n", stack[i].x, stack[i].y);
    }
    
    // Free memory.
    free(points);
    free(point_ptrs);
    free(stack);
    
    return 0;
}