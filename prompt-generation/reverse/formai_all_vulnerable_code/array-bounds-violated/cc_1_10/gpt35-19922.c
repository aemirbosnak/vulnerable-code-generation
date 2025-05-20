//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include<stdio.h>

int matrix[10][10], visited[10] = {0};
int n;

// Recursive DFS Function
void dfs(int v){
    printf("\nVisited node : %d",v);
    visited[v] = 1;
    for(int i=0;i<n;i++){
        if(matrix[v][i] && !visited[i]){
            dfs(i);
        }
    }
}

// Dijstra's Shortest Path Algorithm
void shortest_path(int source){
    int distance[n], min, u;
    for(int i=0;i<n;i++){
        distance[i] = matrix[source][i];
    }
    visited[source]=1;
    distance[source] = 0;
    for(int i=1;i<n;i++){
        min = 999;
        for(int j=0;j<n;j++){
            if(!visited[j] && distance[j]<min){
                min = distance[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(int j=0;j<n;j++){
            if(!visited[j] && matrix[u][j]!=0 && (distance[u]+matrix[u][j]<distance[j])){
                distance[j] = distance[u] + matrix[u][j];
            }
        }
    }
    printf("\nShortest Path : ");
    for(int i=0;i<n;i++){
        printf("%d ",distance[i]);
    }
}

// Main Function
int main(){
    printf("Enter No of vertices : ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix : ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }   
    int source;
    printf("\nEnter source vertex : ");
    scanf("%d",&source);
    printf("\nDFS Traversal : ");
    dfs(source);
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    shortest_path(source);
    return 0;
}