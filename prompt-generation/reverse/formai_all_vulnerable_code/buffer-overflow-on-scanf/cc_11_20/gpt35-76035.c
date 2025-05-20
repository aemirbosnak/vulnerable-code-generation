//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 100

int main() {
    int vertices, edges, colors;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int color[MAX_VERTICES] = {0};
    
    srand(time(NULL));
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the number of colors: ");
    scanf("%d", &colors);
    
    // Randomly initialize the adjacency matrix
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            if(i == j) {
                graph[i][j] = 0;
            }
            else {
                int r = rand() % 10;
                if(r < 6) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
                else {
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                }
            }
        }
    }
    
    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    // Implement the graph coloring algorithm
    for(int i=0; i<vertices; i++) {
        int used_colors[MAX_COLORS] = {0};
        for(int j=0; j<vertices; j++) {
            if(graph[i][j] == 1 && color[j] != 0) {
                used_colors[color[j] - 1] = 1;
            }
        }
        int k;
        for(k=0; k<colors; k++) {
            if(used_colors[k] == 0) {
                break;
            }
        }
        color[i] = k + 1;
    }
    
    // Print the color of each vertex
    printf("\nVertex Colors:\n");
    for(int i=0; i<vertices; i++) {
        printf("Vertex %d: Color %d\n", i+1, color[i]);
    }
    
    return 0;
}