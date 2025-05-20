//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    point_t p1;
    point_t p2;
} line_t;


static const double EPS = 1e-9;

static unsigned int seed;

static point_t paranoid_point(void)
{
    point_t p;
    seed = (seed * 1103515245 + 12345) % (1 << 31);
    p.x = ((double) seed / (1 << 31)) * 1000000.0;
    seed = (seed * 1103515245 + 12345) % (1 << 31);
    p.y = ((double) seed / (1 << 31)) * 1000000.0;
    return p;
}

static line_t paranoid_line(void)
{
    line_t l;
    l.p1 = paranoid_point();
    l.p2 = paranoid_point();
    return l;
}

static double paranoid_double(void)
{
    seed = (seed * 1103515245 + 12345) % (1 << 31);
    return ((double) seed / (1 << 31)) * 1000000.0;
}

static int paranoid_int(void)
{
    seed = (seed * 1103515245 + 12345) % (1 << 31);
    return seed / (1 << 15);
}

static int paranoid_boolean(void)
{
    seed = (seed * 1103515245 + 12345) % (1 << 31);
    return (seed & 1);
}

static int paranoid_orientation(const line_t *l, const point_t *p)
{
    double dx1 = l->p1.x - p->x;
    double dy1 = l->p1.y - p->y;
    double dx2 = l->p2.x - p->x;
    double dy2 = l->p2.y - p->y;
    double cross = dx1 * dy2 - dx2 * dy1;
    if (fabs(cross) < EPS) {
        return 0;
    } else if (cross > 0) {
        return 1;
    } else {
        return -1;
    }
}

static int paranoid_is_intersecting(const line_t *l1, const line_t *l2)
{
    int o1 = paranoid_orientation(l1, &l2->p1);
    int o2 = paranoid_orientation(l1, &l2->p2);
    int o3 = paranoid_orientation(l2, &l1->p1);
    int o4 = paranoid_orientation(l2, &l1->p2);
    return (o1 * o2 < 0) && (o3 * o4 < 0);
}

static int paranoid_is_convex(const point_t *points, unsigned int n)
{
    unsigned int i;
    int orientation = paranoid_orientation(&(line_t) {points[n - 1], points[0]}, &points[1]);
    for (i = 2; i < n; i++) {
        int o = paranoid_orientation(&(line_t) {points[i - 1], points[i]}, &points[i + 1]);
        if (o != orientation) {
            return 0;
        }
    }
    return 1;
}

static double paranoid_area(const point_t *points, unsigned int n)
{
    unsigned int i;
    double area = 0;
    for (i = 0; i < n; i++) {
        area += points[i].x * points[(i + 1) % n].y - points[(i + 1) % n].x * points[i].y;
    }
    return fabs(area) / 2.0;
}

static point_t paranoid_centroid(const point_t *points, unsigned int n)
{
    unsigned int i;
    point_t centroid = {0, 0};
    double area = paranoid_area(points, n);
    for (i = 0; i < n; i++) {
        double sign = (i % 2 == 0) ? 1 : -1;
        centroid.x += (points[i].x * points[(i + 1) % n].y - points[(i + 1) % n].x * points[i].y) * sign / (6.0 * area);
        centroid.y += (points[i].y * points[(i + 1) % n].x - points[(i + 1) % n].y * points[i].x) * sign / (6.0 * area);
    }
    return centroid;
}

int main(void)
{
    unsigned int n = paranoid_int();
    if (n < 3 || n > 1000000) {
        printf("Invalid number of points: %u\n", n);
        return 1;
    }
    point_t points[n];
    unsigned int i;
    for (i = 0; i < n; i++) {
        points[i] = paranoid_point();
    }
    if (!paranoid_is_convex(points, n)) {
        printf("Points are not convex\n");
        return 1;
    }
    double area = paranoid_area(points, n);
    if (fabs(area) < EPS) {
        printf("Area is zero\n");
        return 1;
    }
    point_t centroid = paranoid_centroid(points, n);
    printf("Area: %lf\n", area);
    printf("Centroid: (%lf, %lf)\n", centroid.x, centroid.y);
    return 0;
}