//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define FILENAME_LENGTH 50

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

int num_nodes, num_edges;
Edge edges[MAX_EDGES];
int adj_matrix[MAX_NODES][MAX_NODES];

void read_config_file(const char *filename);
void create_adj_matrix();
void print_adj_matrix();

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    read_config_file(argv[1]);
    create_adj_matrix();
    print_adj_matrix();

    return 0;
}

void read_config_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[FILENAME_LENGTH];
    int nodes_count = 0;
    int edges_count = 0;

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, FILENAME_LENGTH, file)) {
        if (sscanf(line, "%d %d %d", &edges[edges_count].source,
                   &edges[edges_count].destination,
                   &edges[edges_count].weight) != 3) {
            fprintf(stderr, "Invalid line: %s\n", line);
            continue;
        }

        edges_count++;
        nodes_count = (nodes_count > edges[edges_count].source)
                          ? nodes_count
                          : edges[edges_count].source;
    }

    fclose(file);
    num_nodes = nodes_count;
    num_edges = edges_count;
}

void create_adj_matrix() {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adj_matrix[i][j] = -1;
        }
    }

    for (int i = 0; i < num_edges; i++) {
        int source = edges[i].source;
        int destination = edges[i].destination;
        int weight = edges[i].weight;

        adj_matrix[source][destination] = weight;
        adj_matrix[destination][source] = weight;
    }
}

void print_adj_matrix() {
    printf("Adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%2d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}