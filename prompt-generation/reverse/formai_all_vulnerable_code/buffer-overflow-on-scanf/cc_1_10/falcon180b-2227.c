//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int graph[10][10]; // Adjacency matrix for the graph
int n; // Number of vertices
int colors[10]; // Array to store the colors assigned to each vertex

void initialize_graph(void) {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }
}

void print_graph(void) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void initialize_colors(void) {
    int i;
    for(i=0; i<n; i++) {
        colors[i] = 0;
    }
}

int color_graph(int v) {
    int i, j;
    int count = 0;
    int colors[10];
    for(i=0; i<v; i++) {
        colors[i] = 0;
    }
    colors[v] = 1;
    count++;
    for(i=0; i<n; i++) {
        if(graph[v][i] == 1) {
            for(j=0; j<n; j++) {
                if(colors[j] == 0) {
                    colors[j] = 1;
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

int main(void) {
    initialize_graph();
    initialize_colors();
    int count = 0;
    int i;
    for(i=0; i<n; i++) {
        if(colors[i] == 0) {
            count += color_graph(i);
        }
    }
    printf("Minimum number of colors: %d\n", count);
    return 0;
}