//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
int colors[MAX_VERTICES]; // array to store colors

int colorGraph(int v, int numVertices, int numColors);

int main()
{
    srand(time(NULL)); // initialize random seed

    int numVertices;
    printf("Enter number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    // initialize all vertices to be uncolored
    for (int i = 0; i < numVertices; i++) {
        colors[i] = 0;
    }

    // randomly generate edges in the graph
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            graph[i][j] = graph[j][i] = rand() % 2;
        }
    }

    int numColors = colorGraph(0, numVertices, 1); // start coloring at vertex 0 with color 1
    printf("Number of colors used: %d\n", numColors);

    printf("Coloring:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Color %d\n", i+1, colors[i]);
    }

    return 0;
}

int colorGraph(int v, int numVertices, int numColors)
{
    // base case: we have colored all vertices
    if (v >= numVertices) {
        return numColors - 1; // subtract 1 since we added an extra color for the base case
    }

    int availableColors[MAX_VERTICES];
    int numAvailableColors = 0;

    // check which colors are available for the current vertex
    for (int i = 1; i <= numColors; i++) {
        int used = 0;
        for (int j = 0; j < numVertices; j++) {
            if (graph[v][j] && colors[j] == i) {
                used = 1;
                break;
            }
        }

        if (!used) {
            availableColors[numAvailableColors++] = i;
        }
    }

    // try each available color recursively
    for (int i = 0; i < numAvailableColors; i++) {
        colors[v] = availableColors[i];
        int numColorsUsed = colorGraph(v + 1, numVertices, numColors);
        if (numColorsUsed < numColors) {
            numColors = numColorsUsed;
        }
    }

    // none of the available colors worked, so add a new color and try again
    colors[v] = ++numColors;
    int numColorsUsed = colorGraph(v + 1, numVertices, numColors);
    if (numColorsUsed < numColors) {
        numColors = numColorsUsed;
    }

    return numColors;
}