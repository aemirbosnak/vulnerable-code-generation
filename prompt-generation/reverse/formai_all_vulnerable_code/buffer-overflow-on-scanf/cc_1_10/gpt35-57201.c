//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <math.h>

struct Point {
    double x, y;
};

struct Polygon {
    int n;
    struct Point vertex[100];
};

double distance(struct Point a, struct Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double perimeter(struct Polygon p) {
    double sum = 0.0;
    for(int i = 0; i < p.n; i++) {
        int j = (i+1) % p.n;
        sum += distance(p.vertex[i], p.vertex[j]);
    }
    return sum;
}

double area(struct Polygon p) {
    double sum = 0.0;
    for(int i = 0; i < p.n; i++) {
        int j = (i+1) % p.n;
        sum += (p.vertex[i].x * p.vertex[j].y) - (p.vertex[i].y * p.vertex[j].x);
    }
    return fabs(0.5 * sum);
}

int main() {
    struct Polygon p;
    printf("Enter number of vertices: ");
    scanf("%d", &p.n);
    for(int i = 0; i < p.n; i++) {
        printf("Enter x and y co-ordinates for vertex %d: ", i+1);
        scanf("%lf %lf", &p.vertex[i].x, &p.vertex[i].y);
    }

    printf("Perimeter of polygon is: %lf\n", perimeter(p));
    printf("Area of polygon is: %lf\n", area(p));

    return 0;
}