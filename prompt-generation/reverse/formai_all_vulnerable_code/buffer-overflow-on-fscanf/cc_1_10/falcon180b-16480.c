//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371.01
#define MAX_POINTS 1000
#define MIN_DISTANCE 1e-6

typedef struct {
    double lat;
    double lon;
} Point;

Point read_point(FILE *fp) {
    Point p;
    fscanf(fp, "%lf %lf", &p.lat, &p.lon);
    return p;
}

double distance(Point p1, Point p2) {
    double d = sin(p2.lat - p1.lat) * sin(p2.lat - p1.lat) + cos(p1.lat) * cos(p2.lat) * sin(p2.lon - p1.lon) * sin(p2.lon - p1.lon);
    d = acos(d);
    d = d * R;
    return d;
}

void write_point(FILE *fp, Point p) {
    fprintf(fp, "%lf %lf\n", p.lat, p.lon);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Point points[MAX_POINTS];
    int num_points = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fscanf(fp, "%lf %lf", &points[num_points].lat, &points[num_points].lon) == 2) {
        num_points++;
        if (num_points >= MAX_POINTS) {
            printf("Maximum number of points reached.\n");
            break;
        }
    }

    fclose(fp);

    int i, j;
    for (i = 0; i < num_points; i++) {
        for (j = i + 1; j < num_points; j++) {
            double d = distance(points[i], points[j]);
            if (d > MIN_DISTANCE) {
                printf("Distance between point %d and point %d: %.2lf km\n", i, j, d);
            }
        }
    }

    return 0;
}