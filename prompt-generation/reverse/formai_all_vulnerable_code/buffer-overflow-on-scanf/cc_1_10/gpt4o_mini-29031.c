//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACTIVITIES 20

// Function to display the results
void printSolution(int result[], int n) {
    printf("Activity Schedule:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d -> Time Slot %d\n", i + 1, result[i] + 1);
    }
}

// Check if this color can be assigned to vertex v
int isSafe(int v, int graph[MAX_ACTIVITIES][MAX_ACTIVITIES], int color[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to solve the m-coloring problem
int graphColoringUtil(int graph[MAX_ACTIVITIES][MAX_ACTIVITIES], int m, int color[], int v, int n) {
    if (v == n) {
        return 1; // All activities are scheduled
    }
    
    for (int c = 0; c < m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c; // Assign color

            // Recur to assign colors to rest of the activities
            if (graphColoringUtil(graph, m, color, v + 1, n)) {
                return 1;
            }

            // Backtrack
            color[v] = -1;
        }
    }
    return 0; // If no color can be assigned
}

// Main function to solve the m-coloring problem
void graphColoring(int graph[MAX_ACTIVITIES][MAX_ACTIVITIES], int m, int n) {
    int color[MAX_ACTIVITIES]; // Store the color of activities

    // Initialize all activities as uncolored
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    // Call the recursive utility
    if (graphColoringUtil(graph, m, color, 0, n) == 0) {
        printf("Solution does not exist\n");
    } else {
        printSolution(color, n);
    }
}

int main() {
    int n, m; // n = number of activities, m = number of time slots
    int graph[MAX_ACTIVITIES][MAX_ACTIVITIES];

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Initialize the adjacency matrix
    printf("Enter the adjacency matrix (Enter 1 if activities clash, 0 otherwise): \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of time slots available: ");
    scanf("%d", &m);

    // Call the graph coloring function
    graphColoring(graph, m, n);

    return 0;
}