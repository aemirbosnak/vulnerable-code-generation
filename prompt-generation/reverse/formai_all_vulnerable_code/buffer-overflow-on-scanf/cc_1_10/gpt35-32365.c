//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void init_graph(int vertices){
    for(int i=0;i<vertices;i++){
        visited[i]=0;
        for(int j=0;j<vertices;j++){
            graph[i][j]=0;
        }
    }
}

void add_edge(int s, int d){
    graph[s][d]=1;
}

void dfs(int current_vertex, int vertices){
    visited[current_vertex]=1;
    printf("%d ",current_vertex);
    for(int i=0;i<vertices;i++){
        if(graph[current_vertex][i]==1 && visited[i]==0){
            dfs(i,vertices);
        }
    }
}

void print_graph(int vertices){
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int vertices,edges;
    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);

    init_graph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d",&edges);

    int s,d;
    printf("Enter the source and destination vertices of each edge:\n");
    for(int i=0;i<edges;i++){
        scanf("%d %d",&s,&d);
        add_edge(s,d);
    }

    printf("The adjacency matrix of the graph is:\n");
    print_graph(vertices);

    printf("Depth first traversal of the graph starting from vertex 0:\n");
    dfs(0,vertices);

    return 0;
}