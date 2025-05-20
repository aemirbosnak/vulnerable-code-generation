//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *node1;
    int *node2;
    int value;
} resistor;

typedef struct {
    int *node;
    int value;
} voltage_source;

int **create_matrix(int nodes) {
    int **matrix = (int **) malloc(nodes * sizeof(int *));
    for (int i = 0; i < nodes; i++) {
        matrix[i] = (int *) malloc(nodes * sizeof(int));
        for (int j = 0; j < nodes; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void add_resistor(int **matrix, int node1, int node2, int value) {
    matrix[node1][node2] += value;
    matrix[node2][node1] += value;
}

void add_voltage_source(int **matrix, int node, int value) {
    matrix[node][0] += value;
}

int calculate_current(int **matrix, int node1, int node2) {
    return matrix[node1][node2];
}

int main() {
    int nodes = 3;
    int **matrix = create_matrix(nodes);

    add_resistor(matrix, 0, 1, 10);
    add_resistor(matrix, 1, 2, 20);

    add_voltage_source(matrix, 0, 5);

    int current = calculate_current(matrix, 0, 1);
    printf("Current between nodes 0 and 1 is %d\n", current);

    free(matrix[0]);
    free(matrix);
    return 0;
}