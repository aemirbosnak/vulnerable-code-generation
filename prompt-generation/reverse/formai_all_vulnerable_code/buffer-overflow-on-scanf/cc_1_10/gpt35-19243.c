//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NODES 100
#define MAX_COLORS 10

struct node {
    int id;
    int color;
};

int num_nodes, num_edges, num_colors;
struct node graph[MAX_NODES];
int adjacency_matrix[MAX_NODES][MAX_NODES];
pthread_t threads[MAX_NODES];
pthread_mutex_t mutex[MAX_NODES];

void* color_graph(void* arg) {
    int i, node_id = *((int*) arg);
    for (i = 1; i <= num_colors; i++) {
        int j, conflict = 0;
        pthread_mutex_lock(&mutex[node_id]);
        graph[node_id].color = i;
        for (j = 0; j < num_nodes; j++) {
            if (adjacency_matrix[node_id][j] && graph[node_id].color == graph[j].color) {
                conflict = 1;
                break;
            }
        }
        pthread_mutex_unlock(&mutex[node_id]);
        if (!conflict) {
            break;
        }
    }
    return NULL;
}

int main(int argc, char** argv) {
    int i, j;
    scanf("%d %d %d", &num_nodes, &num_edges, &num_colors);
    for (i = 0; i < num_nodes; i++) {
        graph[i].id = i;
        graph[i].color = 0;
        pthread_mutex_init(&mutex[i], NULL);
        pthread_create(&threads[i], NULL, color_graph, (void*) &graph[i].id);
    }
    for (i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjacency_matrix[u][v] = adjacency_matrix[v][u] = 1;
    }
    for (i = 0; i < num_nodes; i++) {
        pthread_join(threads[i], NULL);
    }
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d colored with %d\n", graph[i].id, graph[i].color);
    }
    return 0;
}