//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 100000
#define INF 999999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m, k, *cluster;

void read_graph() {
    FILE *fp = fopen("graph.txt", "r");
    fscanf(fp, "%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fscanf(fp, "%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {u, v, w};
    }
    fclose(fp);
}

void k_means() {
    srand(time(NULL));
    int c = rand() % n;
    cluster[c] = 1;
    for (int i = 0; i < n; i++) {
        if (i == c) continue;
        cluster[i] = 0;
    }
    int iter = 0;
    while (iter < 100) {
        iter++;
        int changed = 0;
        for (int i = 0; i < n; i++) {
            if (cluster[i] == 0) continue;
            int min_dist = INF;
            int c_min = -1;
            for (int j = 0; j < n; j++) {
                if (cluster[j] == 1) {
                    int dist = edges[i].w;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        dist += edges[k].w;
                    }
                    if (dist < min_dist) {
                        min_dist = dist;
                        c_min = j;
                    }
                }
            }
            if (c_min!= -1) {
                cluster[i] = 0;
                cluster[c_min] = 1;
                changed = 1;
            }
        }
        if (!changed) break;
    }
}

void write_clusters(char *filename) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", cluster[i]);
    }
    fclose(fp);
}

int main() {
    read_graph();
    k_means();
    write_clusters("clusters.txt");
    return 0;
}