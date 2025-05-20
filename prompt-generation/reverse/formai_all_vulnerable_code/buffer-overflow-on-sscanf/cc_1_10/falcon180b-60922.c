//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_LINES 10000

typedef struct {
    int id;
    char name[16];
    int x, y;
} Node;

typedef struct {
    int id;
    int start_node, end_node;
    int weight;
} Edge;

char map[MAX_LINES][80];
int num_nodes = 0, num_edges = 0;
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

void read_nodes() {
    FILE *fp = fopen("nodes.txt", "r");
    char line[80];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Node node;
        sscanf(line, "%d %s %d %d", &node.id, node.name, &node.x, &node.y);
        strcpy(map[num_nodes], line);
        num_nodes++;
    }
    fclose(fp);
}

void read_edges() {
    FILE *fp = fopen("edges.txt", "r");
    char line[80];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Edge edge;
        sscanf(line, "%d %d %d", &edge.id, &edge.start_node, &edge.end_node);
        strcpy(map[num_nodes], line);
        num_nodes++;
        edge.weight = rand() % 100;
        edges[num_edges++] = edge;
    }
    fclose(fp);
}

void print_map() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s\n", map[i]);
    }
}

int main() {
    srand(time(NULL));
    read_nodes();
    read_edges();
    print_map();
    return 0;
}