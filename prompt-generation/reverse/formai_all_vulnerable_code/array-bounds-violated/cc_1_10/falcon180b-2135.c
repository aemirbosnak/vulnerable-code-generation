//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define MAX_VERTEX 10
#define MAX_THREAD 4
#define MAX_COLOR 6

int graph[MAX_VERTEX][MAX_VERTEX];
int n;
int m;
int color[MAX_VERTEX];
int vertex_color[MAX_VERTEX];
int flag = 0;

void* thread_func(void* arg) {
    int thread_id = *(int*)arg;
    int start = thread_id * (n / MAX_THREAD);
    int end = (thread_id + 1) * (n / MAX_THREAD) - 1;
    if (thread_id == MAX_THREAD - 1)
        end = n - 1;

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < MAX_COLOR; j++) {
            if (color[j] == 0) {
                color[j] = 1;
                vertex_color[i] = j;
                if (graph[i][0]!= 0) {
                    graph[i][0] = 0;
                    flag = 1;
                }
                break;
            }
        }
        if (color[0] == 0) {
            printf("Graph is not colorable\n");
            pthread_exit(NULL);
        }
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges: ");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    pthread_t thread_id[MAX_THREAD];
    int rc;
    for (int i = 0; i < MAX_THREAD; i++) {
        rc = pthread_create(&thread_id[i], NULL, thread_func, (void*)i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_join(thread_id[i], NULL);
    }

    printf("Vertex\tColor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, vertex_color[i]);
    }

    return 0;
}