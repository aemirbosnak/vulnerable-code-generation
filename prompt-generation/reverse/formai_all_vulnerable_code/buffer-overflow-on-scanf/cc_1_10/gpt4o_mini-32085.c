//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int num_vertices;
pthread_mutex_t mutex;

typedef struct {
    int vertex;
    int num_colors;
} ThreadData;

void *color_vertex(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int vertex = data->vertex;
    int num_colors = data->num_colors;

    // Check available colors
    int available[MAX_COLORS] = {0};
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color[i] != -1) {
            available[color[i]] = 1; // Color is not available
        }
    }

    // Find the first available color
    for (int c = 0; c < num_colors; c++) {
        if (!available[c]) {
            pthread_mutex_lock(&mutex);
            color[vertex] = c;
            pthread_mutex_unlock(&mutex);
            break;
        }
    }

    free(data);
    return NULL;
}

void create_graph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void print_color_assignment() {
    printf("Vertex Colors:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int main() {
    pthread_t threads[MAX_VERTICES];
    pthread_mutex_init(&mutex, NULL);
    create_graph();

    // Initialize all vertices with -1 (no color)
    for (int i = 0; i < num_vertices; i++) {
        color[i] = -1;
    }

    int num_colors = MAX_COLORS;

    // Create threads for each vertex
    for (int i = 0; i < num_vertices; i++) {
        ThreadData *data = (ThreadData *)malloc(sizeof(ThreadData));
        data->vertex = i;
        data->num_colors = num_colors;

        if (pthread_create(&threads[i], NULL, color_vertex, data) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < num_vertices; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the color assignment
    print_color_assignment();

    pthread_mutex_destroy(&mutex);
    return 0;
}