//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

int num_nodes, num_edges;
Edge edges[MAX_EDGES];
int degrees[MAX_NODES];
int visited[MAX_NODES];

void read_graph() {
    FILE *fp;
    char filename[100];
    printf("Enter the filename of the graph: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }
    fscanf(fp, "%d %d", &num_nodes, &num_edges);
    printf("Number of nodes: %d\n", num_nodes);
    printf("Number of edges: %d\n", num_edges);
    for (int i = 0; i < num_edges; i++) {
        fscanf(fp, "%d %d %d", &edges[i].node1, &edges[i].node2, &edges[i].weight);
    }
    fclose(fp);
}

void calculate_degrees() {
    for (int i = 0; i < num_nodes; i++) {
        degrees[i] = 0;
    }
    for (int i = 0; i < num_edges; i++) {
        degrees[edges[i].node1]++;
        degrees[edges[i].node2]++;
    }
}

void topological_sort() {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (degrees[i] == 0) {
            queue[rear++] = i;
        }
    }
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < num_nodes; i++) {
            if (edges[i].node1 == node || edges[i].node2 == node) {
                degrees[edges[i].node1]--;
                degrees[edges[i].node2]--;
            }
        }
        for (int i = 0; i < num_nodes; i++) {
            if (degrees[i] == 0) {
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    read_graph();
    calculate_degrees();
    topological_sort();
    return 0;
}