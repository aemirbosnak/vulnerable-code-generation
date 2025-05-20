//FormAI DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>

int main() {
    // Setting up the graph
    int vertices = 10;
    int graph[vertices][vertices];
    
    // Initializing all values to 0
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }
    
    // Adding edges to the graph
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][3] = 1;
    graph[4][5] = 1;
    graph[4][6] = 1;
    graph[5][7] = 1;
    graph[7][8] = 1;
    graph[8][9] = 1;
    graph[9][10] = 1;
    
    printf("The graph: \n");
    printf("   (1)---(2)   \n");
    printf("    |     |    \n");
    printf("   (3)   (4)   \n");
    printf("         |     \n");
    printf("        (5)---(6)\n");
    printf("         |     \n");
    printf("        (7)---(8)\n");
    printf("             |  \n");
    printf("            (9)--(10)\n");
    printf("\n");
    
    // Printing the graph
    printf("The graph in matrix form: \n");
    for(int i=1; i<=vertices; i++) {
        printf("    ");
        for(int j=1; j<=vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}