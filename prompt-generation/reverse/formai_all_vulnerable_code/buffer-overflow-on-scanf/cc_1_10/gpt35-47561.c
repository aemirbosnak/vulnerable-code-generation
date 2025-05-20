//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>

#define MAX_VERTICES 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

/* This function initializes the elements in the adjacency matrix to 0 */
void initialize_matrix() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

/* This function adds an edge between two vertices */
void add_edge(int i, int j) {
    adj_matrix[i][j] = 1;
    adj_matrix[j][i] = 1;
}

/* This function prints out the adjacency matrix */
void print_matrix() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

/* This function drives the program */
int main() {
    int vertices, edges, i, j;
    printf("Please enter the number of vertices (maximum of 10): ");
    scanf("%d", &vertices);
    printf("Please enter the number of edges: ");
    scanf("%d", &edges);
    
    /* Initialize the adjacency matrix */
    initialize_matrix();
    
    /* Add edges based on user input */
    for (i = 0; i < edges; i++) {
        printf("Please enter the two vertices that are connected by edge %d (separated by a space): ", i+1);
        scanf("%d %d", &i, &j);
        add_edge(i, j);
    }
    
    /* Print out the complete adjacency matrix */
    printf("The adjacency matrix for your graph is:\n");
    print_matrix();
    
    return 0;
}