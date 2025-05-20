//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000 // Maximum number of vertices

int graph[MAX][MAX], V; // Adjacency matrix and number of vertices
int visited[MAX]; // Array to track visited vertices

int queue[MAX], front = -1, rear = -1; // Queue for BFS traversal

// Function to add edge between two vertices
void addEdge(int v, int u){
    graph[v][u] = 1; 
    graph[u][v] = 1; 
}

// BFS Traversal
void BFS(int start){
    visited[start] = 1;
    queue[++rear] = start;
    while(front != rear){
        int current = queue[++front];
        printf("%d ", current);
        for(int i=0;i<V;i++){
            if(graph[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// Dijkstra's Algorithm
void dijkstra(int start){
    int dist[MAX], min, next;
    for(int i=0;i<V;i++)
        dist[i] = graph[start][i];
    dist[start] = 0;
    visited[start] = 1;
    for(int i=0;i<V;i++){
        min = 999;
        for(int j=0;j<V;j++){
            if(min > dist[j] && visited[j] == 0){
                min = dist[j];
                next = j;
            }
        }
        visited[next] = 1;
        for(int j=0;j<V;j++){
            if(visited[j] == 0){
                if(min+graph[next][j] < dist[j])
                    dist[j] = min+graph[next][j];
            }
        }
    }
    printf("\nShortest distances from vertex %d:\n", start);
    for(int i=0;i<V;i++)
        printf("%d to %d = %d\n", start, i, dist[i]);
}

int main(){
    int choice, vertex, edge;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &edge);
    for(int i=0;i<edge;i++){
        int v, u, weight;
        printf("Enter the vertices for edge %d: ", i+1);
        scanf("%d %d", &v, &u);
        addEdge(v, u);
    }
    printf("\nMenu:\n1. BFS Traversal\n2. Dijkstra's Algorithm\n3. Exit\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("\nEnter the starting vertex for BFS: ");
                scanf("%d", &vertex);
                for(int i=0;i<V;i++)
                    visited[i] = 0;
                BFS(vertex);
                break;
            case 2:
                printf("\nEnter the starting vertex for Dijkstra's Algorithm: ");
                scanf("%d", &vertex);
                for(int i=0;i<V;i++)
                    visited[i] = 0;
                dijkstra(vertex);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }while(1);
    return 0;
}