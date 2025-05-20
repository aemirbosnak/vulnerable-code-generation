//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include<stdio.h>

// Defining graph 
int graph[10][10], v;

// Function to add edges 
void add_edge(int start, int end, int weight) {
    
    // Adding edge from start to end with given weight
    graph[start][end] = weight;
}

// Function to display the graph 
void display_graph() {
    int i, j;
    printf("\n\nGraph:\n\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    
    printf("Welcome to Graph Representation Program!");
    printf("\nEnter number of vertices: ");
    scanf("%d", &v);

    int i, j;
    
    // Initializing all elements as 0
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            graph[i][j] = 0;

    // Adding edges to the graph
    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 2, 8);
    add_edge(1, 7, 11);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(2, 5, 4);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    // Displaying the graph
    display_graph();

    return 0;
}