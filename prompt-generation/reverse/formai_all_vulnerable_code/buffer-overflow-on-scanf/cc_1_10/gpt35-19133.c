//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

int nodeCount;

void generateGraph(int **graph){
    int i, j;
    for(i=0; i<nodeCount; i++) {
        for(j=0; j<nodeCount; j++) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = rand() % 2;
            }
        }
    }
}

void printGraph(int **graph) {
    printf("\nAdjacency Matrix:\n\n");
    int i,j;
    for(i=0;i<nodeCount;++i) {
        for(j=0;j<nodeCount;++j){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

}

int main(){
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodeCount);

    int **graph = malloc(nodeCount*sizeof(int*));
    int i;
    for(i=0; i<nodeCount; ++i) {
        graph[i] = malloc(nodeCount*sizeof(int));
    }

    generateGraph(graph);
    printGraph(graph);

    for(i=0; i<nodeCount; ++i) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}