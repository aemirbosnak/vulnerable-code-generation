//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include<stdio.h>

// Maximum number of vertices in the graph
#define MAXV 100

// Stack implementation for backtrack
typedef struct {
    int data[MAXV];
    int top;
} Stack;

// Stack operation functions
int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int peek(Stack *s) {
    return s->data[s->top];
}

/* Graph Coloring function */
int graph_coloring(int n, int graph[][MAXV], int m, int color[]) {
    // At the beginning, all vertices have no color assigned
    for(int i=0;i<n;i++) {
        color[i] = -1;
    }
    // Start from the first vertex
    color[0] = 0;
    // Create a stack to keep track of visited nodes
    Stack visited;
    visited.top = -1;
    push(&visited, 0);

    while(!is_empty(&visited)) {
        int current = peek(&visited);
        int current_color = color[current];
        int new_color = -1;
        // Check if a vertex has a conflict with its color
        for(int i=0;i<n;i++) {
            if(graph[current][i] && color[i]==current_color) {
                new_color = current_color + 1;
                break;
            }
        }
        // If a vertex has conflict then try another color
        if(new_color != -1) {
            if(new_color >= m) {
                // No solution with m colors
                return 0;
            }
            color[current] = new_color;
        } else {
            // No conflict found, backtrack to previous node
            pop(&visited);
        }
        // Add unvisited neighbors to the stack
        for(int i=0;i<n;i++) {
            if(graph[current][i] && color[i]==-1) {
                push(&visited, i);
            }
        }
    }
    return 1;
}

int main() {
    // User input
    int n, m;
    printf("Enter number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter number of colors to be used: ");
    scanf("%d", &m);
    int graph[MAXV][MAXV];
    printf("Enter adjacency matrix of the graph:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // Call Graph Coloring function
    int color[MAXV];
    int result = graph_coloring(n, graph, m, color);

    if(result) {
        // Print solution
        printf("The graph can be colored with %d colors\n", m);
        for(int i=0;i<n;i++) {
            printf("Vertex %d is colored with %d\n", i+1, color[i]+1);
        }
    } else {
        printf("The graph cannot be colored with %d colors\n", m);
    }
    return 0;
}