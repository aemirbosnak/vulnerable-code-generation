//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100
#define INF 9999

typedef struct {
    int id;
    double x, y;
} Point;

double euclidean_distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void swap(Point* a, Point* b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

void kmeans(Point data[], int k, int iter, Point centroids[]) {
    int i, j, c;
    int changed = 1;
    while (changed && iter--) {
        changed = 0;
        for (i = 0; i < k; i++) {
            centroids[i].x = 0;
            centroids[i].y = 0;
        }
        for (i = 0; i < k; i++) {
            for (j = 0; j < MAX; j++) {
                if (data[j].id == i) {
                    centroids[i].x += data[j].x;
                    centroids[i].y += data[j].y;
                    break;
                }
            }
        }
        for (i = 0; i < MAX; i++) {
            c = -1;
            double min_dist = INF;
            for (j = 0; j < k; j++) {
                double dist = euclidean_distance(data[i], centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    c = j;
                }
            }
            if (c!= data[i].id) {
                data[i].id = c;
                changed = 1;
            }
        }
    }
}

int main() {
    int i, j, k;
    Point data[MAX];
    Point centroids[MAX];

    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    for (i = 0; i < MAX; i++) {
        fscanf(fp, "%d %lf %lf", &data[i].id, &data[i].x, &data[i].y);
    }

    kmeans(data, 3, 10, centroids);

    for (i = 0; i < k; i++) {
        for (j = 0; j < MAX; j++) {
            if (data[j].id == i) {
                printf("Cluster %d: (%lf, %lf)\n", i, data[j].x, data[j].y);
            }
        }
    }

    return 0;
}