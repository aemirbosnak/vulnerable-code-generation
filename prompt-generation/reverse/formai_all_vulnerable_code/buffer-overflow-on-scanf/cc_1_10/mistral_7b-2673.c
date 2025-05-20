//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p1, p2;
    double distance;
} Segment;

double DistancePointSegment(Point p, Segment s) {
    double p1_p2_len_sq = pow(s.p2.x - s.p1.x, 2.0) + pow(s.p2.y - s.p1.y, 2.0);
    double t = pow((pow(p.x - s.p1.x, 2.0) + pow(p.y - s.p1.y, 2.0) - p1_p2_len_sq / 2.0), 0.5);
    double d = sqrt(p1_p2_len_sq * (1.0 - t * t));
    return d;
}

void FindClosestSegmentPoint(Point points[], int num_points, Segment seg[], int seg_num, Point closest_point) {
    double min_dist = INFINITY;

    for (int i = 0; i < num_points; i++) {
        double dist = DistancePointSegment(points[i], seg[0]);
        if (dist < min_dist) {
            min_dist = dist;
            closest_point = points[i];
        }
    }

    printf("Closest point to segment [%g, %g] to %d points is [%g, %g]\n", seg[0].p1.x, seg[0].p1.y, num_points, closest_point.x, closest_point.y);
}

int main() {
    Point points[MAX_POINTS];
    Segment segments[MAX_POINTS / 2];

    int num_points = 0, seg_num = 0;

    while (1) {
        printf("Enter point coordinates (x y) or 'q' to quit: ");
        scanf("%lf %lf", &points[num_points].x, &points[num_points].y);
        if (points[num_points].x == -1 && points[num_points].y == -1) {
            break;
        }
        num_points++;

        if (num_points > 1) {
            printf("Enter segment endpoints (x1 y1 x2 y2): ");
            scanf("%lf %lf %lf %lf", &segments[seg_num].p1.x, &segments[seg_num].p1.y, &segments[seg_num].p2.x, &segments[seg_num].p2.y);
            seg_num++;
        }
    }

    Point closest_point;
    FindClosestSegmentPoint(points, num_points, segments, seg_num, closest_point);

    return 0;
}