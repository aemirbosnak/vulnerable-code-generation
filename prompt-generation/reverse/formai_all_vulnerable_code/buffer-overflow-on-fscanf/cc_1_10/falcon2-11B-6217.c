//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Definitions
#define INFINITY (1 << 30)

// Helper functions

int get_max_color(int n, int *colors) {
    int max_color = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(colors[i] > max_color) {
            max_color = colors[i];
        }
    }
    return max_color;
}

int get_min_color(int n, int *colors) {
    int min_color = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(colors[i] < min_color) {
            min_color = colors[i];
        }
    }
    return min_color;
}

// Main function

int main(int argc, char *argv[]) {
    int n, m, u, v, k, colors[100], d[100], edges[100], colors_count[100];
    int max_color, min_color, i, j, p, q, t;
    FILE *graph;
    char *file_name;

    // Open file
    graph = fopen(argv[1], "r");
    if (graph == NULL) {
        printf("Error: File not found or can't be opened.\n");
        return 1;
    }

    // Read graph data
    fscanf(graph, "%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        fscanf(graph, "%d %d %d", &u, &v, &d[i]);
        edges[i] = u;
        edges[i + m] = v;
        colors_count[u]++;
        colors_count[v]++;
    }

    // Assign initial colors
    for (i = 0; i < n; i++) {
        colors[i] = i;
    }

    // Find maximum and minimum colors
    max_color = get_max_color(n, colors);
    min_color = get_min_color(n, colors);

    // Loop until all vertices are colored
    while (max_color > min_color) {
        for (i = 0; i < n; i++) {
            colors[i] = i;
        }

        // Find the first uncolored vertex
        for (i = 0; i < n; i++) {
            if (colors[i] == -1) {
                break;
            }
        }

        if (i == n) {
            printf("No solution found.\n");
            break;
        }

        // Choose the minimum color
        for (p = 0; p < n; p++) {
            if (colors[p] == min_color) {
                q = p;
                break;
            }
        }

        // Assign the chosen color to the uncolored vertex
        colors[i] = q;

        // Recolor neighboring vertices
        for (j = 0; j < m; j++) {
            t = edges[j];
            if (colors[t] == min_color) {
                colors[t] = colors[i];
            }
        }

        // Find the maximum color
        max_color = get_max_color(n, colors);
        min_color = get_min_color(n, colors);
    }

    // Print colored graph
    printf("Vertex \tColor\n");
    for (i = 0; i < n; i++) {
        printf("%d \t%d\n", i, colors[i]);
    }

    // Close file
    fclose(graph);

    return 0;
}