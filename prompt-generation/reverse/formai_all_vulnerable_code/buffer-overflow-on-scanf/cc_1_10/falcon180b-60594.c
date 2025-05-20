//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

// Graph representation using adjacency matrix
int graph[MAX_NODES][MAX_NODES] = {0};

// Function to initialize the graph with random edges
void initialize_graph(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

// Function to print the current coloring of the graph
void print_graph(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", WHITE);
            } else {
                printf("%d ", BLACK);
            }
        }
        printf("\n");
    }
}

// Function to check if the current coloring is a valid solution
int is_valid_solution(int n, int coloring[MAX_NODES]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1 && coloring[i] == coloring[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to find a valid solution using backtracking
int find_solution(int n, int coloring[MAX_NODES]) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (coloring[i] == WHITE) {
            coloring[i] = GRAY;
            for (j = 0; j < n; j++) {
                if (graph[i][j] == 1 && coloring[j] == WHITE) {
                    coloring[j] = GRAY;
                }
            }
            if (is_valid_solution(n, coloring)) {
                return 1;
            }
            coloring[i] = WHITE;
            for (j = 0; j < n; j++) {
                if (graph[i][j] == 1 && coloring[j] == GRAY) {
                    coloring[j] = WHITE;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n, i, j, coloring[MAX_NODES] = {0};
    srand(time(NULL));
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    initialize_graph(n);

    // Print the initial graph coloring
    print_graph(n);

    // Find a valid solution using backtracking
    if (find_solution(n, coloring)) {
        printf("\nValid solution found:\n");
        print_graph(n);
    } else {
        printf("\nNo valid solution found.\n");
    }

    return 0;
}