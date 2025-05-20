//FormAI DATASET v1.0 Category: Graph representation ; Style: visionary
// Welcome to my visionary C Graph representation program!
// This program aims to create an abstract representation of a graph using C language
// We will be using an adjacency matrix to represent our graph and implement basic graph operations

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for boolean data type

#define MAX_VERTICES 10 // maximum number of vertices in the graph

int adj_mat[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix to store the graph edges
int vertex_count = 0; // current number of vertices in the graph

// function to add a new vertex to the graph
void add_vertex() {
    if(vertex_count<MAX_VERTICES) {
        printf("Enter the new vertex value (an integer between 0 and %d): ", MAX_VERTICES-1);
        int vertex_value;
        scanf("%d", &vertex_value);
        
        // add the new vertex to the adjacency matrix
        for(int i=0; i<=vertex_count; i++) {
            adj_mat[i][vertex_count] = 0;
            adj_mat[vertex_count][i] = 0;
        }
        vertex_count++;
        printf("Vertex %d successfully added to the graph.\n", vertex_value);
    }
    else {
        printf("Error: Maximum number of vertices reached.\n");
    }
}

// function to add a new edge between two vertices
void add_edge() {
    if(vertex_count==0) {
        printf("Error: The graph is currently empty.\n");
        return;
    }
    
    int vertex1, vertex2;
    printf("Enter the two vertices (values between 0 and %d) to add an edge: ", vertex_count-1);
    scanf("%d %d", &vertex1, &vertex2);
    
    if((vertex1<0 || vertex1>=vertex_count) || (vertex2<0 || vertex2>=vertex_count)) {
        printf("Error: Invalid vertices.\n");
        return;
    }
    
    if(adj_mat[vertex1][vertex2]==1 || adj_mat[vertex2][vertex1]==1) {
        printf("Error: Edge already exists between vertices %d and %d.\n", vertex1, vertex2);
        return;
    }
    
    adj_mat[vertex1][vertex2] = 1;
    adj_mat[vertex2][vertex1] = 1;
    printf("Edge successfully added between vertices %d and %d.\n", vertex1, vertex2);
}

// function to remove an edge between two vertices
void remove_edge() {
    if(vertex_count==0) {
        printf("Error: The graph is currently empty.\n");
        return;
    }
    
    int vertex1, vertex2;
    printf("Enter the two vertices (values between 0 and %d) to remove the edge: ", vertex_count-1);
    scanf("%d %d", &vertex1, &vertex2);
    
    if((vertex1<0 || vertex1>=vertex_count) || (vertex2<0 || vertex2>=vertex_count)) {
        printf("Error: Invalid vertices.\n");
        return;
    }
    
    if(adj_mat[vertex1][vertex2]==0 || adj_mat[vertex2][vertex1]==0) {
        printf("Error: No edge exists between vertices %d and %d.\n", vertex1, vertex2);
        return;
    }
    
    adj_mat[vertex1][vertex2] = 0;
    adj_mat[vertex2][vertex1] = 0;
    printf("Edge successfully removed between vertices %d and %d.\n", vertex1, vertex2);
}

// function to print the adjacency matrix of the graph
void print_graph() {
    if(vertex_count==0) {
        printf("The graph is currently empty.\n");
        return;
    }
    
    printf("The adjacency matrix of the graph is:\n");
    for(int i=0; i<vertex_count; i++) {
        for(int j=0; j<vertex_count; j++) {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to C Graph representation program!\n\n");
    
    while(true) {
        printf("\nPlease choose an operation:\n");
        printf("1. Add a vertex\n");
        printf("2. Add an edge\n");
        printf("3. Remove an edge\n");
        printf("4. Print the graph\n");
        printf("5. Quit\n");
        printf("Your choice (1,2,3,4,5): ");
        
        int choice;
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1: add_vertex(); break;
            case 2: add_edge(); break;
            case 3: remove_edge(); break;
            case 4: print_graph(); break;
            case 5: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}