//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a vertex in the graph
struct Vertex {
    char name[100];
    int degree;
    int color;
};

// Function to find a valid coloring of the graph G
void find_coloring(int n, int colors[], struct Vertex vertices[]) {
    for (int i = 0; i < n; i++) {
        int min_degree = 1000000;
        int min_index = -1;

        // Find the vertex with the minimum degree
        for (int j = 0; j < n; j++) {
            if (vertices[j].degree < min_degree) {
                min_degree = vertices[j].degree;
                min_index = j;
            }
        }

        // Assign a color to the minimum degree vertex
        for (int j = 0; j < colors[i]; j++) {
            vertices[min_index].color = j;
            min_index = (min_index + 1) % n;
        }

        // Decrease the degree of the assigned vertices
        for (int j = 0; j < colors[i]; j++) {
            vertices[min_index].degree--;
        }
    }
}

int main() {
    int n, colors[100];
    struct Vertex vertices[100];

    // Read input from user
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &colors[0]);

    for (int i = 0; i < n; i++) {
        printf("Enter the name of vertex %d: ", i + 1);
        scanf("%s", vertices[i].name);

        printf("Enter the degree of vertex %s: ", vertices[i].name);
        scanf("%d", &vertices[i].degree);
    }

    // Find a valid coloring of the graph G
    find_coloring(n, colors, vertices);

    // Print the coloring of the graph G
    for (int i = 0; i < n; i++) {
        printf("Vertex %s is colored %d\n", vertices[i].name, vertices[i].color);
    }

    return 0;
}