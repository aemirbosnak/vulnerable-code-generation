//FormAI DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

//Structure for Graph
struct Graph{
    int V; //Number of Vertices
    int E; //Number of Edges
    int** adjMatrix; //Adjacency Matrix
};

//Creates adjacency Matrix
int** createMat(int V){
    int i,j;
    int **arr = (int**)malloc(V*sizeof(int*));
    for(i=0;i<V;i++){
        arr[i] = (int*)malloc(V*sizeof(int));
        for(j=0;j<V;j++){
            arr[i][j] = 0; //Initializing all elements with 0
        }
    }
    return arr;
}

//Creates a new Graph
struct Graph* createGraph(int V){
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> V = V;
    graph -> E = 0;
    graph -> adjMatrix = createMat(V);

    return graph; //returning the pointer of the created graph
}

//Adds the Edge
void addEdge(struct Graph* graph, int src, int dest){
    graph -> adjMatrix[src][dest] = 1;
    graph -> adjMatrix[dest][src] = 1; //Undirected Graph
    graph -> E++;
}

//For Printing the Graph
void printGraph(struct Graph* graph){
    int i,j;
    printf("\nAdjacency Matrix:\n\n");
    for(i=0;i<graph->V;i++){
        for(j=0;j<graph->V;j++){
            printf("%d ",graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int V;
    printf("Enter the number of Vertices:\n");
    scanf("%d",&V);

    struct Graph* graph = createGraph(V);

    int choice = 1;
    while(choice != 0){
        printf("\nEnter your choice:\n");
        printf("1. Add an Edge\n");
        printf("2. Print the Graph\n");
        printf("0. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                int src, dest;
                printf("\nEnter the source Vertex:\n");
                scanf("%d",&src);
                printf("\nEnter the destination Vertex:\n");
                scanf("%d",&dest);
                addEdge(graph,src,dest); //Adding the Edge
                break;
            }
            case 2: {
                printGraph(graph); //Printing the Graph
                break;
            }
            case 0: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nInvalid choice!!!\n");
            }
        }
    }
    return 0;
}