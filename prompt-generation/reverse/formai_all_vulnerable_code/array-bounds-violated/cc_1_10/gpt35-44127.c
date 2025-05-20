//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int graph[MAX_SIZE][MAX_SIZE];
int vertexCount = 0;

void enqueue(int vertex){
    if(rear == MAX_SIZE-1){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return -1;
    }
    int element = queue[front];
    front++;
    return element;
}

void addVertex(){
    if(vertexCount == MAX_SIZE){
        printf("Maximum vertices reached\n");
        return;
    }
    vertexCount++;
}

void addEdge(int start, int end){
    if(start >= vertexCount || end >= vertexCount){
        printf("Invalid vertex\n");
        return;
    }
    graph[start][end] = 1;
    graph[end][start] = 1;
}

void BFS(int startVertex){
    visited[startVertex] = 1;
    enqueue(startVertex);

    while(front != -1){
        int currentVertex = dequeue();
        printf("%d ",currentVertex);

        for(int i=0;i<vertexCount;i++){
            if(graph[currentVertex][i] == 1 && !visited[i]){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main(){
    addVertex(); // Adding vertex 0
    addVertex(); // Adding vertex 1
    addVertex(); // Adding vertex 2
    addVertex(); // Adding vertex 3
    addVertex(); // Adding vertex 4

    addEdge(0, 1); // Connecting vertex 0 to vertex 1
    addEdge(0, 2); // Connecting vertex 0 to vertex 2
    addEdge(1, 3); // Connecting vertex 1 to vertex 3
    addEdge(2, 4); // Connecting vertex 2 to vertex 4

    printf("BFS Traversal: ");
    BFS(0); // Starting BFS traversal from vertex 0

    return 0;
}