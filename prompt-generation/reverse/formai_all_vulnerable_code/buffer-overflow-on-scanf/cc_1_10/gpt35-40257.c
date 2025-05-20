//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the circuit
#define MAX_SIZE 100

int circuit[MAX_SIZE][3];
int n, m;
bool marked[MAX_SIZE];

// Check whether a circuit is valid
bool is_valid(int node, int* path, int length) {
    // Check whether all nodes have been visited
    for (int i = 0; i < n; i++) {
        if (!marked[i]) {
            return false;
        }
    }
    // Check whether the circuit starts and ends at the same node
    if (node != path[0] || node != path[length - 1]) {
        return false;
    }
    // Check whether the circuit passes through all the edges
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < length - 1; j++) {
            if ((path[j] == circuit[i][0] && path[j + 1] == circuit[i][1])
                || (path[j] == circuit[i][1] && path[j + 1] == circuit[i][0])) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

// Find a circuit in the graph starting from the given node
bool find_circuit(int node, int* path, int length) {
    path[length++] = node;
    marked[node] = true;
    // Try each edge in turn
    for (int i = 0; i < m; i++) {
        int next = -1;
        if (circuit[i][0] == node && !marked[circuit[i][1]]) {
            next = circuit[i][1];
        } else if (circuit[i][1] == node && !marked[circuit[i][0]]) {
            next = circuit[i][0];
        }
        if (next != -1 && find_circuit(next, path, length)) {
            return true;
        }
    }
    // If all edges have been tried and none worked, backtrack
    marked[node] = false;
    return false;
}

int main() {
    // Read the input
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &circuit[i][0], &circuit[i][1], &circuit[i][2]);
    }
    // Find a circuit starting from each node
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        int path[MAX_SIZE];
        found = find_circuit(i, path, 0);
        if (found) {
            // Check whether the circuit is valid
            if (is_valid(i, path, 0)) {
                printf("Valid circuit found starting from node %d\n", i);
                for (int j = 0; j < n; j++) {
                    printf("%d ", path[j]);
                }
                printf("\n");
            } else {
                printf("Invalid circuit found starting from node %d\n", i);
            }
        }
    }
    // If no circuit has been found, the graph is not connected
    if (!found) {
        printf("The graph is not connected\n");
    }
    return 0;
}