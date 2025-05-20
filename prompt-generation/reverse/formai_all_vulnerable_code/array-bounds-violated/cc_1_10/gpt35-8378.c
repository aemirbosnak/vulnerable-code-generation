//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NODES 50
#define MAX_EDGES 500
#define INF 999999

int graph[MAX_NODES][MAX_NODES];
int heuristic[MAX_NODES];
int n_nodes;
int n_edges;

int start_node, end_node;

int open_list[MAX_NODES];
int closed_list[MAX_NODES];
int parent[MAX_NODES];
int g_score[MAX_NODES];
int f_score[MAX_NODES];

int n_threads;

pthread_mutex_t open_list_mutex;
pthread_mutex_t closed_list_mutex;
pthread_mutex_t parent_mutex;
pthread_mutex_t g_score_mutex;
pthread_mutex_t f_score_mutex;

void set_heuristic() {
    // Set heuristic of all nodes to 0.
    for (int i = 0; i < n_nodes; i++) {
        heuristic[i] = 0;
    }
}

void set_graph() {
    // Set initial graph values to infinity.
    for (int i = 0; i < n_nodes; i++) {
        for (int j = 0; j < n_nodes; j++) {
            graph[i][j] = INF;
        }
    }
}

void add_edge(int u, int v, int w) {
    // Add an edge to the graph.
    graph[u][v] = w;
}

void init_lists() {
    // Initialize open and closed lists.
    for (int i = 0; i < n_nodes; i++) {
        open_list[i] = -1;
        closed_list[i] = -1;
    }
    open_list[start_node] = start_node;
}

int find_min_f() {
    // Find the node with minimum f score in the open list.
    int min_f_node = -1;
    int min_f_val = INF;
    for (int i = 0; i < n_nodes; i++) {
        if (open_list[i] != -1 && f_score[i] < min_f_val) {
            min_f_val = f_score[i];
            min_f_node = i;
        }
    }
    return min_f_node;
}

int reconstruct_path(int current) {
    // Reconstruct the path from start to end.
    int path[MAX_NODES];
    int path_len = 0;
    path[path_len++] = current;
    while (current != start_node) {
        current = parent[current];
        path[path_len++] = current;
    }
    printf("Path: ");
    for (int i = path_len - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
    return path_len;
}

void* process_node(void* thread_id) {
    // Perform A* search for each node in the open list.
    int id = *((int*) thread_id);
    while (1) {
        // Find the node with minimum f score in the open list.
        pthread_mutex_lock(&open_list_mutex);
        int current_node = find_min_f();
        if (current_node == -1) {
            // No node left in the open list.
            pthread_mutex_unlock(&open_list_mutex);
            break;
        }
        open_list[current_node] = -1;
        closed_list[current_node] = current_node;
        pthread_mutex_unlock(&open_list_mutex);

        if (current_node == end_node) {
            // End node found.
            reconstruct_path(current_node);
            break;
        }

        // Process neighbors.
        for (int i = 0; i < n_nodes; i++) {
            if (graph[current_node][i] != INF) {
                // Neighbor found.
                pthread_mutex_lock(&closed_list_mutex);
                if (closed_list[i] != -1) {
                    // Neighbor already in closed list.
                    pthread_mutex_unlock(&closed_list_mutex);
                    continue;
                }
                pthread_mutex_unlock(&closed_list_mutex);

                int tentative_g_score = g_score[current_node] + graph[current_node][i];

                pthread_mutex_lock(&open_list_mutex);
                if (open_list[i] == -1) {
                    // Neighbor not in open list.
                    open_list[i] = i;
                    pthread_mutex_unlock(&open_list_mutex);

                    pthread_mutex_lock(&g_score_mutex);
                    g_score[i] = tentative_g_score;
                    pthread_mutex_unlock(&g_score_mutex);

                    pthread_mutex_lock(&f_score_mutex);
                    f_score[i] = g_score[i] + heuristic[i];
                    pthread_mutex_unlock(&f_score_mutex);

                    pthread_mutex_lock(&parent_mutex);
                    parent[i] = current_node;
                    pthread_mutex_unlock(&parent_mutex);
                } else if (tentative_g_score < g_score[i]) {
                    // Better path found to neighbor.
                    pthread_mutex_unlock(&open_list_mutex);

                    pthread_mutex_lock(&g_score_mutex);
                    g_score[i] = tentative_g_score;
                    pthread_mutex_unlock(&g_score_mutex);

                    pthread_mutex_lock(&f_score_mutex);
                    f_score[i] = g_score[i] + heuristic[i];
                    pthread_mutex_unlock(&f_score_mutex);

                    pthread_mutex_lock(&parent_mutex);
                    parent[i] = current_node;
                    pthread_mutex_unlock(&parent_mutex);
                } else {
                    pthread_mutex_unlock(&open_list_mutex);
                }
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    // Set up A* search.
    scanf("%d %d", &n_nodes, &n_edges);
    scanf("%d %d", &start_node, &end_node);
    set_graph();
    for (int i = 0; i < n_edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    set_heuristic();

    init_lists();
    pthread_t threads[MAX_NODES];
    int thread_ids[MAX_NODES];
    for (int i = 0; i < n_nodes; i++) {
        thread_ids[i] = i;
    }
    for (int i = 0; i < n_threads; i++) {
        pthread_create(&threads[i], NULL, process_node, &thread_ids[i]);
    }
    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}