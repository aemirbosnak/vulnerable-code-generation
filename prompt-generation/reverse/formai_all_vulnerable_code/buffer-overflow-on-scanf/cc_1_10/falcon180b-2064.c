//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000
#define INF 1000000

struct edge{
    int src, dest, weight;
};

struct edge graph[MAX][MAX];
int dist[MAX];
int parent[MAX];

void init(){
    int i, j;
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            graph[i][j].src = -1;
            graph[i][j].dest = -1;
            graph[i][j].weight = INF;
        }
    }
}

void addedge(int src, int dest, int weight){
    graph[src][dest].src = src;
    graph[src][dest].dest = dest;
    graph[src][dest].weight = weight;
}

void dijkstra(int src){
    int i, u, v;
    for(i=0; i<MAX; i++){
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;
    int sptset[MAX];
    int count = 0;
    sptset[count++] = src;

    while(count > 0){
        int u = sptset[--count];

        int k = -1;
        for(i=0; i<MAX; i++){
            if(!sptset[i] && dist[u]!= INF && dist[u]+graph[u][i].weight < dist[i]){
                dist[i] = dist[u] + graph[u][i].weight;
                parent[i] = u;
            }
        }
    }
}

void printsolution(int n, int src){
    printf("Vertex\t Distance from Source\n");
    printf("------\t -------------------\n");
    int i;
    for(i=0; i<n; i++){
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main(){
    int n, m, i, j, src, dest, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    init();

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges with their weights:\n");

    for(i=0; i<m; i++){
        scanf("%d %d %d", &src, &dest, &weight);
        addedge(src, dest, weight);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    printf("The shortest distances from the source vertex are:\n");
    printsolution(n, src);

    return 0;
}