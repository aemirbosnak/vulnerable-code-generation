//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int graph[50][50];
int colors[50];
int num_color = 0;

void *color_graph(void *args){
    int vertex = *(int *)args;

    int i;
    for(i=0;i<num_color;i++){
        int flag = 0;
        int j;

        for(j=0;j<50;j++){
            if(graph[vertex][j]==1 && colors[j] == i){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            colors[vertex] = i;
            pthread_exit(NULL);
        }
    }
}

int main(){
    int num_vertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertex);

    int i, j;

    printf("Enter the adjacency matrix: \n");

    for(i=0;i<num_vertex;i++){
        for(j=0;j<num_vertex;j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &num_color);

    pthread_t tid[num_vertex];
    int v[num_vertex];

    for(i=0;i<num_vertex;i++){
        v[i] = i;
        pthread_create(&tid[i], NULL, color_graph, &v[i]);
    }

    for(i=0;i<num_vertex;i++){
        pthread_join(tid[i], NULL);
    }

    printf("\nMinimum number of colors required: %d\n", num_color);

    printf("Vertex Color\n");

    for(i=0;i<num_vertex;i++){
        printf("%d\t%d\n", i, colors[i]);
    }

    return 0;
}