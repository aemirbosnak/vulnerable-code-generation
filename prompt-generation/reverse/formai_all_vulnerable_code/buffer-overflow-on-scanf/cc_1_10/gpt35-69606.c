//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define INF 0x3f3f3f3f

struct point {
    double x, y;
};

struct edge {
    int to, w;
};

struct graph {
    struct edge edges[MAX_N][MAX_N];
    int n;
};

struct dijkstra_result {
    int prev[MAX_N];
    int dist[MAX_N];
};

struct point get_point(void) {
    struct point p;
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

double get_distance(struct point a, struct point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int get_nearest_point(struct point p, int n, struct point points[]) {
    int index = 0;
    double min_distance = INF;
    for (int i = 0; i < n; i++) {
        double distance = get_distance(p, points[i]);
        if (distance < min_distance) {
            index = i;
            min_distance = distance;
        }
    }
    return index;
}

struct graph build_graph(int n, struct point points[]) {
    struct graph g;
    g.n = n;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double distance = get_distance(points[i], points[j]);
            int w = (int)(distance * 10);
            g.edges[i][j] = (struct edge){j, w};
            g.edges[j][i] = (struct edge){i, w};
        }
    }
    return g;
}

struct dijkstra_result dijkstra(struct graph g, int start) {
    struct dijkstra_result result;
    int n = g.n;
    int visited[n];
    for (int i = 0; i < n; i++) {
        result.dist[i] = INF;
        visited[i] = 0;
    }
    result.dist[start] = 0;
    for (int i = 0; i < n; i++) {
        int min_index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (min_index == -1 || result.dist[j] < result.dist[min_index])) {
                min_index = j;
            }
        }
        if (result.dist[min_index] == INF) {
            break;
        }
        visited[min_index] = 1;
        for (int j = 0; j < n; j++) {
            int new_dist = result.dist[min_index] + g.edges[min_index][j].w;
            if (g.edges[min_index][j].w > 0 && new_dist < result.dist[j]) {
                result.dist[j] = new_dist;
                result.prev[j] = min_index;
            }
        }
    }
    return result;
}

void print_route(struct dijkstra_result result, int start, int end) {
    printf("Navigation route:\n");

    int current = end;
    int path[MAX_N];
    int path_length = 0;
    do {
        path[path_length++] = current;
        current = result.prev[current];
    } while (current != start);
    path[path_length++] = current;

    for (int i = path_length - 1; i > 0; i--) {
        printf("%d -> %d (%d.%d km)\n", path[i], path[i-1], result.dist[path[i]]/10, result.dist[path[i]]%10);
    }
}

int main(void) {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct point points[n];
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        points[i] = get_point();
    }

    int start_index, end_index;
    printf("Enter the starting point: ");
    start_index = get_nearest_point(get_point(), n, points);
    printf("Enter the ending point: ");
    end_index = get_nearest_point(get_point(), n, points);

    struct graph g = build_graph(n, points);

    struct dijkstra_result result = dijkstra(g, start_index);

    print_route(result, start_index, end_index);

    return 0;
}