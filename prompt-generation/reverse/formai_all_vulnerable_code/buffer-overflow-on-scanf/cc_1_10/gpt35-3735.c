//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include<stdio.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];

void dfs(int v){
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < MAX; i++){
        if(graph[v][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

int main(){
    int edges, u, v;    

    printf("How many edges? ");
    scanf("%d", &edges);

    //initialize graph
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    //add edges to graph
    printf("Enter edges:\n");
    for(int i = 0; i < edges; i++){
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    //print adjacency matrix
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    //call dfs
    printf("DFS Traversal: ");
    dfs(0);

    return 0;
}