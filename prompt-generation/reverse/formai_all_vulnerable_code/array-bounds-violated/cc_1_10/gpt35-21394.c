//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
#define INF 99999

int graph[MAX][MAX], n;

void dijkstra(int start){
    int visited[MAX], dist[MAX], u, count, min_distance, next_node;

    for(int i=0;i<n;i++){
        visited[i]=0;
        dist[i]=graph[start][i];
    }

    visited[start]=1;
    count=1;

    while(count<n-1){
        min_distance=INF;

        for(int i=0;i<n;i++){
            if(dist[i]<min_distance && !visited[i]){
                min_distance=dist[i];
                next_node=i;
            }
        }

        visited[next_node]=1;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(min_distance+graph[next_node][i]<dist[i]){
                    dist[i]=min_distance+graph[next_node][i];
                }
            }
        }
        count++;
    }

    printf("Shortest distance from node %d:\n",start);

    for(int i=0;i<n;i++){
        printf("to node %d is %d\n",i,dist[i]);
    }

}

int main(){
    int start;

    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    printf("Enter the weighted adjacency matrix: \n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0 && i!=j){
                graph[i][j]=INF;    
            }
        }
    }

    printf("Enter the starting node: ");
    scanf("%d",&start);

    dijkstra(start);

    return 0;
}