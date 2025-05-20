//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include<stdio.h>
#include<stdlib.h>

//structure for graph
struct graph{
    int vertex;
    int** edges;
};

//function to create graph
struct graph* createGraph(int V){
    int i, j;
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    G->vertex = V;
    G->edges = (int**)malloc(V * sizeof(int*));
    for(i=0;i<V;i++){
        G->edges[i] = (int*)malloc(V * sizeof(int));
        for(j=0;j<V;j++){
            if(i == j){
                G->edges[i][j] = 1;
            }
            else{
                G->edges[i][j] = 0;
            }
        }
    }
    return G;
}

//function to print graph
void printGraph(struct graph* G){
    int i,j;
    for(i=0;i<G->vertex;i++){
        printf("\nVertex %d: ",i+1);
        for(j=0;j<G->vertex;j++){
            printf("%d ",G->edges[i][j]);
        }
    }
}

//function to color the graph
void colorGraph(struct graph* G,int V,int m){
    int color[V];
    int i,j,c;
    for(i=0;i<V;i++){
        color[i] = 0;
    }
    for(i=0;i<V;i++){
        for(j=1;j<=m;j++){
            c = 1;
            for(int k=0;k<V;k++){
                if(G->edges[i][k] == 1 && color[k] == j){
                    c = 0;
                    break;
                }
            }
            if(c){
                color[i] = j;
                break;
            }
        }
    }
    printf("\n\nThe colors assigned to vertices are: ");
    for(i=0;i<V;i++){
        printf("Vertex %d : Color %d\n",i+1,color[i]);
    }
}

int main(){
    int V, E, i, j, v1, v2, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d",&E);
    struct graph* G = createGraph(V);
    printf("\nEnter the edges of the graph:\n");
    for(i=0;i<E;i++){
        printf("Enter the edge %d: ",i+1);
        scanf("%d %d",&v1,&v2);
        G->edges[v1-1][v2-1] = 1;
        G->edges[v2-1][v1-1] = 1;
    }
    printf("\n\nThe entered graph:");
    printGraph(G);
    printf("\n\nEnter the number of colors required: ");
    scanf("%d",&m);
    colorGraph(G,V,m);
    return 0;
}