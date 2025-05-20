//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_CLASSES 10
#define NO_COLOR -1

// Function prototypes
void printSolution(int color[], int numClasses);
int isSafe(int graph[MAX_CLASSES][MAX_CLASSES], int color[], int classIndex, int c, int numClasses);
int graphColoringUtil(int graph[MAX_CLASSES][MAX_CLASSES], int m, int color[], int classIndex, int numClasses);
int graphColoring(int graph[MAX_CLASSES][MAX_CLASSES], int m, int numClasses);

int main() {
    int numClasses, m; // Number of classes and maximum colors
    int graph[MAX_CLASSES][MAX_CLASSES] = {0};

    printf("Enter the number of classes (max %d): ", MAX_CLASSES);
    scanf("%d", &numClasses);

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge) for the classes:\n");
    for (int i = 0; i < numClasses; i++) {
        for (int j = 0; j < numClasses; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors to use (m): ");
    scanf("%d", &m);

    if (graphColoring(graph, m, numClasses) == 0) {
        printf("No solution exists for the given graph and number of colors.\n");
    }

    return 0;
}

// Function to print the solution
void printSolution(int color[], int numClasses) {
    printf("Color assignment:\n");
    for (int i = 0; i < numClasses; i++) {
        printf("Class %d -> Color %d\n", i + 1, color[i] + 1);
    }
}

// Check if a color can be assigned to a given class
int isSafe(int graph[MAX_CLASSES][MAX_CLASSES], int color[], int classIndex, int c, int numClasses) {
    for (int i = 0; i < numClasses; i++) {
        if (graph[classIndex][i] && color[i] == c) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

// Utility function to solve the graph coloring problem
int graphColoringUtil(int graph[MAX_CLASSES][MAX_CLASSES], int m, int color[], int classIndex, int numClasses) {
    if (classIndex == numClasses) {
        printSolution(color, numClasses);
        return 1;
    }

    for (int c = 0; c < m; c++) {
        if (isSafe(graph, color, classIndex, c, numClasses)) {
            color[classIndex] = c;
            if (graphColoringUtil(graph, m, color, classIndex + 1, numClasses)) {
                return 1;
            }
            color[classIndex] = NO_COLOR; // Backtrack
        }
    }
    return 0; // No solution
}

// Main function to perform graph coloring
int graphColoring(int graph[MAX_CLASSES][MAX_CLASSES], int m, int numClasses) {
    int color[MAX_CLASSES];
    for (int i = 0; i < numClasses; i++) {
        color[i] = NO_COLOR; // Initialize all colors
    }
    if (graphColoringUtil(graph, m, color, 0, numClasses) == 0) {
        return 0; // No solution found
    }
    return 1; // Solution found
}