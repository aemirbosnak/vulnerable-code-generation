//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/*
* This is an implementation of the Breadth-first search (BFS) pathfinding algorithm in C
* It finds the shortest path between two nodes in a graph, represented by an adjacency matrix
* The program takes the number of nodes and edges in the graph as inputs, and prompts the user
* to enter the source and destination nodes. It then outputs the shortest path between these 
* nodes, and the distance between them.
*/

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX] = { 0 };

void enqueue(int element)
{
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = element;
    }
}

int dequeue()
{
    int element;
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    else {
        element = queue[front];
        front++;
        return element;
    }
}

int bfs(int adjacency_matrix[][MAX], int *distance, int *parent, int start_vertex, int end_vertex)
{
    int i, j, visited[MAX];

    for (i = 0; i < MAX; i++) {
        visited[i] = 0;
        distance[i] = -1;
        parent[i] = -1;
    }

    visited[start_vertex] = 1;
    distance[start_vertex] = 0;
    enqueue(start_vertex);

    while (front <= rear) {
        int current_vertex = dequeue();
        for (i = 0; i < MAX; i++) {
            if (adjacency_matrix[current_vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                distance[i] = distance[current_vertex] + 1;
                parent[i] = current_vertex;
                enqueue(i);
                if (i == end_vertex)
                    return 1;
            }
        }
    }
    return 0;
}

void print_path(int parent[], int start_vertex, int end_vertex)
{
    if (start_vertex == end_vertex)
        printf("%d ", start_vertex);
    else if (parent[end_vertex] == -1)
        printf("No path from %d to %d\n", start_vertex, end_vertex);
    else {
        print_path(parent, start_vertex, parent[end_vertex]);
        printf("%d ", end_vertex);
    }
}

int main()
{
    int num_nodes, num_edges, i, j, u, v, start_vertex, end_vertex;
    int adjacency_matrix[MAX][MAX], distance[MAX], parent[MAX];

    printf("Enter the number of nodes and edges respectively:\n");
    scanf("%d%d", &num_nodes, &num_edges);

    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    printf("Enter the edges (u, v):\n");

    for (i = 0; i < num_edges; i++) {
        scanf("%d%d", &u, &v);
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
    }

    printf("Enter the start vertex and end vertex:\n");
    scanf("%d%d", &start_vertex, &end_vertex);

    if(bfs(adjacency_matrix, distance, parent, start_vertex, end_vertex)) {
        printf("Shortest distance between %d and %d is %d units\n", start_vertex, end_vertex, distance[end_vertex]);

        printf("Shortest path between %d and %d is: ", start_vertex, end_vertex);
        print_path(parent, start_vertex, end_vertex);
    }
    else {
        printf("No path found between %d and %d\n", start_vertex, end_vertex);
    }
    return 0;
}