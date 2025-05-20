//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_NODES 6  // Number of nodes in the graph

// Graph structure, represented as an adjacency matrix
int graph[NUM_NODES][NUM_NODES] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0}
};

// Array to store colors assigned to nodes
int color[NUM_NODES];

// Maximum number of colors
int max_colors;

// Mutex for synchronization
pthread_mutex_t mutex;

// Function to check if a color can be assigned to a node
int is_safe(int node, int c) {
    for (int i = 0; i < NUM_NODES; i++) {
        if (graph[node][i] && color[i] == c) {
            return 0; // Not safe to assign color
        }
    }
    return 1; // Safe to assign color
}

// Function to assign colors to graph nodes
void *graph_coloring(void *arg) {
    int node = *(int *)arg;
    for (int c = 1; c <= max_colors; c++) {
        pthread_mutex_lock(&mutex);
        
        if (is_safe(node, c)) {
            color[node] = c; // Assign color
            pthread_mutex_unlock(&mutex);
            break; // Break if color assigned successfully
        }
        
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Function to start the graph coloring process
void start_coloring(int num_colors) {
    max_colors = num_colors;
    pthread_t threads[NUM_NODES];
    int node_indices[NUM_NODES];

    // Initialize colors to 0
    for (int i = 0; i < NUM_NODES; i++) {
        color[i] = 0;
        node_indices[i] = i; // Assign node indices
    }

    // Create threads for each node
    for (int i = 0; i < NUM_NODES; i++) {
        if (pthread_create(&threads[i], NULL, graph_coloring, (void *)&node_indices[i])) {
            fprintf(stderr, "Error: Unable to create thread\n");
            exit(1);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_NODES; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Function to print the color assignment
void print_colors() {
    printf("Node Color Assignments:\n");
    for (int i = 0; i < NUM_NODES; i++) {
        printf("Node %d: Color %d\n", i, color[i]);
    }
}

// Main function
int main() {
    int num_colors;

    pthread_mutex_init(&mutex, NULL);

    printf("Enter the maximum number of colors to use: ");
    scanf("%d", &num_colors);

    start_coloring(num_colors);

    print_colors();

    pthread_mutex_destroy(&mutex);
    return 0;
}