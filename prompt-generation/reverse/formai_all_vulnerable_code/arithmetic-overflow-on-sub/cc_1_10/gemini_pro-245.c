//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    int n;
    point *points;
} cluster;

double distance(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

cluster *create_cluster(int n) {
    cluster *c = malloc(sizeof(cluster));
    c->n = n;
    c->points = malloc(n * sizeof(point));
    return c;
}

void free_cluster(cluster *c) {
    free(c->points);
    free(c);
}

void add_point(cluster *c, point p) {
    c->points[c->n++] = p;
}

double cluster_distance(cluster *a, cluster *b) {
    double min_distance = INFINITY;
    for (int i = 0; i < a->n; i++) {
        for (int j = 0; j < b->n; j++) {
            double d = distance(a->points[i], b->points[j]);
            if (d < min_distance) {
                min_distance = d;
            }
        }
    }
    return min_distance;
}

cluster *merge_clusters(cluster *a, cluster *b) {
    cluster *c = create_cluster(a->n + b->n);
    for (int i = 0; i < a->n; i++) {
        add_point(c, a->points[i]);
    }
    for (int i = 0; i < b->n; i++) {
        add_point(c, b->points[i]);
    }
    return c;
}

cluster *cluster_points(point *points, int n, double threshold) {
    cluster **clusters = malloc(n * sizeof(cluster *));
    for (int i = 0; i < n; i++) {
        clusters[i] = create_cluster(1);
        add_point(clusters[i], points[i]);
    }

    while (1) {
        double min_distance = INFINITY;
        cluster *a = NULL;
        cluster *b = NULL;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = cluster_distance(clusters[i], clusters[j]);
                if (d < min_distance) {
                    min_distance = d;
                    a = clusters[i];
                    b = clusters[j];
                }
            }
        }

        if (min_distance > threshold) {
            break;
        }

        cluster *c = merge_clusters(a, b);
        for (int i = 0; i < n; i++) {
            if (clusters[i] == a || clusters[i] == b) {
                clusters[i] = c;
            }
        }
        n--;
    }

    cluster *root = clusters[0];
    for (int i = 1; i < n; i++) {
        free_cluster(clusters[i]);
    }
    free(clusters);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    point *points = malloc(n * sizeof(point));
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double threshold;
    scanf("%lf", &threshold);

    cluster *root = cluster_points(points, n, threshold);

    for (int i = 0; i < root->n; i++) {
        printf("%lf %lf\n", root->points[i].x, root->points[i].y);
    }

    free_cluster(root);
    free(points);
    return 0;
}