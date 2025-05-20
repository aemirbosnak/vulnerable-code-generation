//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

int n, m, start, end, u, v, w, i, j, k, min_dist, path[MAX_NODES];
int adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void init() {
    srand(time(NULL));
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            adj_matrix[i][j] = rand() % 10;
        }
    }
}

void a_star_search(int start, int end) {
    int open_list[MAX_NODES], close_list[MAX_NODES];
    int open_size = 0, close_size = 0;
    int curr_node = start;
    int curr_dist = 0;
    int next_node = -1;
    int next_dist = INF;

    open_list[open_size++] = start;
    visited[start] = 1;

    while (open_size > 0) {
        curr_dist = INF;
        for (i = 0; i < open_size; i++) {
            if (curr_dist > adj_matrix[curr_node][open_list[i]] + curr_dist) {
                curr_dist = adj_matrix[curr_node][open_list[i]] + curr_dist;
                curr_node = open_list[i];
            }
        }

        close_list[close_size++] = curr_node;
        open_list[--open_size] = curr_node;

        if (curr_node == end) {
            break;
        }

        for (i = 0; i < n; i++) {
            if (!visited[i] && adj_matrix[curr_node][i] > 0) {
                int new_dist = curr_dist + adj_matrix[curr_node][i];
                if (new_dist < visited[i]) {
                    visited[i] = new_dist;
                    next_node = i;
                    next_dist = new_dist;
                }
            }
        }
    }

    for (i = close_size - 1; i >= 0; i--) {
        path[k++] = close_list[i];
    }

    for (i = start; i!= end; i = path[--k]) {
        printf("%d ", i);
    }
    printf("%d\n", end);
}

int main() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the start node for edge %d: ", i);
        scanf("%d", &u);
        printf("Enter the end node for edge %d: ", i);
        scanf("%d", &v);
        printf("Enter the weight for edge %d: ", i);
        scanf("%d", &w);
        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }

    init();

    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the end node: ");
    scanf("%d", &end);

    a_star_search(start, end);

    return 0;
}