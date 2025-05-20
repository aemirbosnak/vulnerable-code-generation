//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include<stdio.h>

//maximum size of graph
#define MAX 20
//defining the graph structure with array
struct Graph{
    int V;
    int E;
    int adj[MAX][MAX];
};

//function to insert edge
void insertEdge(struct Graph *G, int u, int v){
    if(u >= G->V || v >= G->V){
        printf("Invalid vertex\n");
    }
    else{
        G->adj[u][v] = 1;
        G->adj[v][u] = 1;
        G->E++;
    }
}

//function to create graph
struct Graph createGraph(){
    struct Graph G;
    printf("Enter number of vertices: ");
    scanf("%d", &G.V);
    G.E = 0;
    for(int i=0; i<G.V; i++){
        for(int j=0; j<G.V; j++){
            G.adj[i][j] = 0;
        }
    }
    int moreEdges = 1;
    while(moreEdges){
        int u, v;
        printf("Enter edge to be inserted: ");
        scanf("%d %d", &u, &v);
        insertEdge(&G, u, v);
        printf("Add more edges? (1 for yes, 0 for no): ");
        scanf("%d", &moreEdges);
    }
    return G;
}

//function to display graph
void displayGraph(struct Graph G){
    printf("Number of vertices: %d\n", G.V);
    printf("Number of edges: %d\n", G.E);
    printf("Adjcancy matrix:\n");
    for(int i=0; i<G.V; i++){
        for(int j=0; j<G.V; j++){
            printf("%d ", G.adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct Graph G = createGraph();
    displayGraph(G);
    return 0;
}