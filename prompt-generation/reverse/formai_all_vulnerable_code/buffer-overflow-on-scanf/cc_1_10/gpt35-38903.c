//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

struct point {
    double x, y;
};

int compute_turn(struct point p1, struct point p2, struct point p3) {
    double cross = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
    if (cross < 0) {
        return -1;  // Right turn
    } else if (cross > 0) {
        return 1;   // Left turn
    } else {
        return 0;   // Collinear
    }
}

double compute_distance(struct point p1, struct point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double compute_perimeter(struct point *points, int num_points) {
    double perimeter = 0;
    for (int i = 0; i < num_points; i++) {
        perimeter += compute_distance(points[i], points[(i+1)%num_points]);
    }
    return perimeter;
}

int compute_convex_hull(struct point *points, int num_points, struct point *hull) {
    int h = 0;
    // Find the leftmost point
    for (int i = 1; i < num_points; i++) {
        if (points[i].x < points[h].x) {
            h = i;
        }
    }
    int start = h;
    int idx = 0;
    do {
        hull[idx++] = points[h];
        int next = (h + 1) % num_points;
        for (int i = 0; i < num_points; i++) {
            if (compute_turn(points[h], points[next], points[i]) == -1) {
                next = i;
            }
        }
        h = next;
    } while (h != start);
    return idx;
}

int main() {
    struct point points[MAX_POINTS];
    int num_points;
    printf("Enter the number of points: ");
    if (scanf("%d", &num_points) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    if (num_points < 3 || num_points > MAX_POINTS) {
        printf("Invalid number of points!\n");
        return 1;
    }
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < num_points; i++) {
        if (scanf("%lf %lf", &points[i].x, &points[i].y) != 2) {
            printf("Invalid input!\n");
            return 1;
        }
    }
    struct point hull[MAX_POINTS];
    int num_hull_points = compute_convex_hull(points, num_points, hull);
    printf("Convex hull:\n");
    for (int i = 0; i < num_hull_points; i++) {
        printf("(%g, %g)\n", hull[i].x, hull[i].y);
    }
    printf("Perimeter: %g\n", compute_perimeter(hull, num_hull_points));
    return 0;
}