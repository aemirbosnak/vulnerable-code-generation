//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

/**
 * This program represents a graph using an adjacency matrix.
 * The graph we are representing is a weighted graph.
 */

#define MAX_VERTICES 20

// Number of vertices in the graph.
int num_vertices;

// Two-dimensional array to store the graph.
int graph[MAX_VERTICES][MAX_VERTICES];

// Structure to represent a vertex.
typedef struct Vertex {
    int vertex_id;
    char* vertex_name;
} Vertex;

// Array to store the vertices in the graph.
Vertex vertices[MAX_VERTICES];

/**
 * Displays a menu to the user, asking them to choose an option.
 */
int display_menu() {
    int option;
    printf("\n1. Add a vertex");
    printf("\n2. Add an edge");
    printf("\n3. Print the graph");
    printf("\n4. Quit");
    printf("\nEnter your option: ");
    scanf("%d", &option);
    return option;
}

/**
 * Adds a new vertex to the graph.
 */
void add_vertex() {
    char* name = (char*)malloc(50*sizeof(char));
    printf("Enter the name of the vertex: ");
    scanf("%s", name);
    Vertex new_vertex;
    new_vertex.vertex_id = num_vertices;
    new_vertex.vertex_name = name;
    vertices[num_vertices] = new_vertex;
    num_vertices++;
}

/**
 * Adds a new edge to the graph.
 */
void add_edge() {
    int start_vertex, end_vertex, weight;
    printf("Enter the start vertex: ");
    scanf("%d", &start_vertex);
    printf("Enter the end vertex: ");
    scanf("%d", &end_vertex);
    printf("Enter the weight of the edge: ");
    scanf("%d", &weight);
    graph[start_vertex][end_vertex] = weight;
}

/**
 * Prints the graph.
 */
void print_graph() {
    printf("Adjacency Matrix:\n");
    for(int i=0;i<num_vertices;i++) {
        printf("%s: ", vertices[i].vertex_name);
        for(int j=0;j<num_vertices;j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

/**
 * Main function to run the program.
 */
int main() {
    num_vertices = 0;
    int option = 0;
    while(option != 4) {
        option = display_menu();
        switch(option) {
            case 1:
                add_vertex();
                break;
            case 2:
                add_edge();
                break;
            case 3:
                print_graph();
                break;
            case 4:
                break;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}