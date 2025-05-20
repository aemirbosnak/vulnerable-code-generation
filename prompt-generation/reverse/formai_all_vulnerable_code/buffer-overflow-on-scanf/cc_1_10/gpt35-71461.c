//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
/**
 * This program demonstrates a unique way of representing a graph
 * using adjacency matrices in C programming language.
 *
 * The program prompts the user to enter the number of vertices in the 
 * graph and then allows the user to enter the connections between each pair of vertices.
 * The program then displays the adjacency matrix of the graph.
 *
 * Author: John Smith
 */

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int numberOfNodes);

int main() {
    int numberOfNodes, i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numberOfNodes);

    int **adjMatrix = (int **)malloc(numberOfNodes * sizeof(int *));
    for(i=0; i<numberOfNodes; i++)
        adjMatrix[i] = (int *)malloc(numberOfNodes * sizeof(int));

    printf("Enter the connections between each pair of vertices separated by a space:\n");
    printf("***Enter -1 to exit***\n");

    for(i=0; i<numberOfNodes; i++) {
        for(j=0; j<numberOfNodes; j++) {
            if(i == j) {
                adjMatrix[i][j] = 0;
                continue;
            }
            printf("Enter connection between node %d and node %d: ", i, j);
            scanf("%d", &adjMatrix[i][j]);
            if(adjMatrix[i][j] == -1){
                i = numberOfNodes;
                break;
            }
        }
    }

    printf("The adjacency matrix of the graph is:\n");
    printMatrix(adjMatrix, numberOfNodes);

    //free dynamically allocated memory
    for (i = 0; i < numberOfNodes; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}


/**
 * This function takes an adjacency matrix and prints it to the console.
 * @param matrix The adjacency matrix of the graph
 * @param numberOfNodes The number of nodes in the graph
 */
void printMatrix(int** matrix, int numberOfNodes) {
    int i, j;

    for(i=0; i<numberOfNodes; i++) {
        for(j=0; j<numberOfNodes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}