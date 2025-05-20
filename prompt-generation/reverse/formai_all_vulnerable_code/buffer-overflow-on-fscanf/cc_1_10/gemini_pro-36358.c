//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct transistor {
    int source;
    int gate;
    int drain;
};

struct circuit {
    int num_transistors;
    struct transistor *transistors;
};

int **alloc_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

struct circuit *load_circuit(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening circuit file");
        exit(1);
    }

    int num_transistors;
    fscanf(fp, "%d\n", &num_transistors);

    struct circuit *circuit = (struct circuit *)malloc(sizeof(struct circuit));
    circuit->num_transistors = num_transistors;
    circuit->transistors = (struct transistor *)malloc(num_transistors * sizeof(struct transistor));

    for (int i = 0; i < num_transistors; i++) {
        fscanf(fp, "%d %d %d\n", &circuit->transistors[i].source, &circuit->transistors[i].gate, &circuit->transistors[i].drain);
    }

    fclose(fp);

    return circuit;
}

void free_circuit(struct circuit *circuit) {
    free(circuit->transistors);
    free(circuit);
}

int **create_adjacency_matrix(struct circuit *circuit) {
    int **matrix = alloc_matrix(circuit->num_transistors, circuit->num_transistors);

    for (int i = 0; i < circuit->num_transistors; i++) {
        matrix[circuit->transistors[i].source][circuit->transistors[i].gate] = 1;
        matrix[circuit->transistors[i].gate][circuit->transistors[i].drain] = 1;
    }

    return matrix;
}

void free_adjacency_matrix(int **matrix, int rows) {
    free_matrix(matrix, rows);
}

void print_adjacency_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <circuit file>\n", argv[0]);
        exit(1);
    }

    struct circuit *circuit = load_circuit(argv[1]);

    int **adjacency_matrix = create_adjacency_matrix(circuit);

    printf("Adjacency matrix:\n");
    print_adjacency_matrix(adjacency_matrix, circuit->num_transistors, circuit->num_transistors);

    free_circuit(circuit);
    free_adjacency_matrix(adjacency_matrix, circuit->num_transistors);

    return 0;
}