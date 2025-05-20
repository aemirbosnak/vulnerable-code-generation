//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 20
#define MAX_THREADS 5

int num_vertices;
int graph[MAX_VERTICES][MAX_VERTICES];
pthread_mutex_t lock; // mutex lock for thread safety

// function to generate random graph
void generate_graph() {
    int i, j;
    for(i = 0; i < num_vertices; i++) {
        for(j = 0; j < num_vertices; j++) {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = rand() % 2; // random value either 0 or 1
        }
    }
}

// function for edges count
void* edges_count(void* rank) {
    long int rank_id = (long int) rank;
    int i, j;
    int count = 0;
    
    // lock the thread for safety
    pthread_mutex_lock(&lock);
    printf("Thread %ld is counting edges...\n", rank_id);
    
    // count the number of edges
    for(i = 0; i < num_vertices; i++) {
        for(j = 0; j < num_vertices; j++) {
            if(graph[i][j] == 1)
                count++;
        }
    }
    
    // print the edge count calculated by each thread
    printf("Thread %ld has counted %d edges.\n", rank_id, count);
    
    // unlock the thread
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    srand(time(NULL)); // set seed for random number generator
    
    // get number of vertices from user
    printf("Enter the number of vertices in your graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);
    
    // check for invalid input
    if(num_vertices < 1 || num_vertices > MAX_VERTICES) {
        printf("Error: invalid input for number of vertices.\n");
        return 1;
    }
    
    // generate random graph
    generate_graph();
    
    // print the generated graph
    printf("\nYour generated graph:\n");
    int i, j;
    for(i = 0; i < num_vertices; i++) {
        for(j = 0; j < num_vertices; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    
    // initialize threads array
    pthread_t threads[MAX_THREADS];
    
    // create threads
    long int rank;
    for(rank = 0; rank < MAX_THREADS; rank++)
        pthread_create(&threads[rank], NULL, edges_count, (void*)rank);
    
    // join threads
    for(rank = 0; rank < MAX_THREADS; rank++)
        pthread_join(threads[rank], NULL);
        
    // destroy mutex lock
    pthread_mutex_destroy(&lock);
    
    return 0;
}