//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    char name[20];
    int id;
} Node;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes, num_edges;

void read_nodes() {
    FILE *fp;
    char line[50];

    fp = fopen("nodes.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open nodes file.\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    num_nodes = atoi(line);

    for (int i = 0; i < num_nodes; i++) {
        fgets(line, sizeof(line), fp);
        strcpy(nodes[i].name, line);
        nodes[i].id = i;
    }

    fclose(fp);
}

void read_edges() {
    FILE *fp;
    char line[50];

    fp = fopen("edges.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open edges file.\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    num_edges = atoi(line);

    for (int i = 0; i < num_edges; i++) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    fclose(fp);
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", nodes[i].id, nodes[i].name);
    }
}

void print_edges() {
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d, weight = %d\n", edges[i].source, edges[i].destination, edges[i].weight);
    }
}

int main() {
    read_nodes();
    read_edges();

    print_nodes();
    print_edges();

    return 0;
}