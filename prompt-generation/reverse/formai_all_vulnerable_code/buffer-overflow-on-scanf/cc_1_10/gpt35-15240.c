//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NODES 10

int adj_matrix[MAX_NODES][MAX_NODES]; // adjacency matrix to represent graph
int colors[MAX_NODES]; // array to store colors of each node
int num_threads; // number of threads to be used
int num_nodes; // number of nodes in the graph

void* colorGraph(void* tid);

int main() {
    pthread_t threads[MAX_NODES]; // thread array to hold thread IDs
    int i, j;
    
    printf("Enter the number of threads to be used: ");
    scanf("%d", &num_threads);
    
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);
    
    // getting input for adjacency matrix
    for(i=0; i<num_nodes; i++) {
        printf("Enter connections for node %d (1 if connected, 0 if not):\n", i+1);
        for(j=0; j<num_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    
    // creating threads
    for(i=0; i<num_threads; i++) {
        pthread_create(&threads[i], NULL, colorGraph, (void*)i);
    }
    
    // waiting for threads to finish
    for(i=0; i<num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // printing the colors of each node
    printf("Colors of each node:\n");
    for(i=0; i<num_nodes; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
    
    return 0;
}

void* colorGraph(void* tid) {
    int thread_id = (int)tid;
    int i, j, k, c;
    int start_node = thread_id * num_nodes / num_threads; // starting node for this thread
    int end_node = (thread_id+1) * num_nodes / num_threads; // ending node for this thread
    
    // checking colors of neighboring nodes and assigning color to current node
    for(i=start_node; i<end_node; i++) {
        c = 1;
        for(j=0; j<num_nodes; j++) {
            if(adj_matrix[i][j] && colors[j] == c) {
                c++;
                j = -1;
            }
        }
        colors[i] = c;
    }
    
    pthread_exit(NULL);
}