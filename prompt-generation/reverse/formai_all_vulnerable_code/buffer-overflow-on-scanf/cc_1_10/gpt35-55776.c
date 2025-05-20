//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include<stdio.h>
#include<stdlib.h>

//adjacency matrix representation of graph
#define MAX_VERTICES 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

//stack to run DFS
int stack[MAX_VERTICES];
int top = -1;

//function to push elements into the stack
void push(int vertex) {
    if(top == MAX_VERTICES-1) {
        printf("Overflow");
        return;
    } 
    stack[++top] = vertex;
}

//function to pop elements from the stack
int pop() {
    if(top == -1) {
        printf("Underflow");
        return -1;
    }
    return stack[top--];
}

//function for Depth First Traversal
void DFS(int vertex, int num_vertices) {
    visited[vertex] = 1;
    printf("%d ",vertex);

    for(int i=0; i<num_vertices; i++) {
        if(adj_matrix[vertex][i] == 1 && visited[i] == 0) {
            push(i);
            visited[i] = 1;
        }
    }

    while(top != -1) {
        int val = pop();
        DFS(val,num_vertices);
    }
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    //taking input from user
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<num_vertices; i++) {
        for(int j=0; j<num_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    //initializing visited array to 0
    for(int i=0; i<num_vertices; i++) {
        visited[i] = 0;
    }

    //starting DFS from vertex 0
    DFS(0,num_vertices);

    return 0;
}