//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

int graph[MAX][MAX]; // adjacency matrix representation of the graph

void *runner(void *param); // thread runner function

int main() {
    int i, j, k;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0; // initialize all elements to 0
        }
    }

    pthread_t threads[n]; // array of thread IDs
    int ids[n]; // array to store thread IDs

    for (i = 0; i < n; i++) {
        ids[i] = i; // assign thread ID to each node
        pthread_create(&threads[i], NULL, runner, &ids[i]); // create a new thread for each node
    }

    for (i = 0; i < n; i++) {
        pthread_join(threads[i], NULL); // wait for each thread to finish
    }

    return 0;
}

void *runner(void *param) {
    int id = *((int *) param); // get the thread ID
    int i, j;

    for (i = 0; i < MAX; i++) {
        if (i!= id) { // don't connect the node to itself
            graph[id][i] = 1; // set the element to 1 to indicate a connection
            graph[i][id] = 1;
        }
    }

    return NULL;
}