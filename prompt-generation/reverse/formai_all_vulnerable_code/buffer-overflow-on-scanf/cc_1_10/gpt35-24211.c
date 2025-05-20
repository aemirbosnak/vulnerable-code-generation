//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<pthread.h>

int n, m;
int matrix[100][100];
int visited[100];
int start_point;
int result[100];

void* thread_start(void* arg){
    int current_min = __INT_MAX__;
    int current_min_idx;
    int current_start = *(int*)arg;
    int i;

    for(i = 1; i<=n; i++){
        if(matrix[current_start][i] < current_min && !visited[i]){
            current_min = matrix[current_start][i];
            current_min_idx = i;
        }
    }
    visited[current_min_idx] = 1;
    result[current_start] = current_min_idx;
}

int main(){

    //take input
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the number of edges:");
    scanf("%d", &m);

    //initialize the graph
    int i, j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            matrix[i][j] = __INT_MAX__;
        }
    }

    //take edges input
    int src, dest, wt;
    for(i=0; i<m; i++){
        printf("\nEnter edge %d (Source, Destination, Weight):", i+1);
        scanf("%d", &src);
        scanf("%d", &dest);
        scanf("%d", &wt);

        matrix[src][dest] = wt;
        matrix[dest][src] = wt;
    }

    //initialize the visited array
    for(i=1; i<=n; i++){
        visited[i] = 0;
    }

    //start from random node
    printf("\nEnter random start node:");
    scanf("%d", &start_point);

    visited[start_point] = 1;
    result[0] = start_point;

    //start threads
    pthread_t threads[n-1];
    int rc;
    for(i=0; i<n-1; i++){
        rc = pthread_create(&threads[i], NULL, thread_start, (void*)&(result[i]));
        if(rc){
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    //join threads
    for(i=0; i<n-1; i++){
        rc = pthread_join(threads[i], NULL);
        if(rc){
            printf("Error joining thread %d\n", i);
            exit(-1);
        }
    }

    //print result
    printf("\n\nResulting path is: %d", start_point);
    for(i=0; i<n-1; i++){
        printf(" -> %d", result[i]);
    }
    printf("\n\n");
    return 0;
}