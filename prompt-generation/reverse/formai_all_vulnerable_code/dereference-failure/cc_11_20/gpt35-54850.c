//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int nodes = rand() % 20; // generate random number of nodes from 0 to 19

    printf("Creating a network topology mapper with %d nodes...\n\n", nodes);

    int** network = (int**) malloc(nodes * sizeof(int*)); // allocate memory for 2D array
    for (int i = 0; i < nodes; i++) {
        network[i] = (int*) malloc(nodes * sizeof(int));
    }

    printf("Mapping network connections...\n\n");

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (i == j) {
                network[i][j] = 0; // no connection to self
            } else if (rand() % 2 == 0) {
                network[i][j] = 1; // random connection
            } else {
                network[i][j] = 0; // no connection
            }
        }
    }

    printf("Network topology map:\n\n");

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            printf("%d ", network[i][j]); // print connections
        }
        printf("\n");
    }

    printf("\nTraversal in progress...\n\n");

    int* visited = (int*) calloc(nodes, sizeof(int)); // allocate memory for visited array
    int current = 0; // start at node 0
    visited[current] = 1; // mark as visited

    while (1) {
        printf("Node %d visited\n", current);
        int next = -1;
        for (int i = 0; i < nodes; i++) {
            if (network[current][i] == 1 && visited[i] == 0) {
                next = i;
                visited[next] = 1;
                break;
            }
        }
        if (next == -1) {
            break;
        } else {
            current = next;
        }
    }

    printf("\nTraversal complete.\n");

    // free memory
    for (int i = 0; i < nodes; i++) {
        free(network[i]);
    }
    free(network);
    free(visited);

    return 0;
}