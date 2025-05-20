//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define NODE_NAME_LEN 20

typedef struct {
    char name[NODE_NAME_LEN];
    int num_edges;
    int *edges;
} Node;

typedef struct {
    int src_node;
    int dest_node;
} Edge;

void add_edge(Node *nodes, int n, int src, int dest) {
    nodes[src].num_edges++;
    nodes[src].edges = (int *)realloc(nodes[src].edges, sizeof(int) * nodes[src].num_edges);
    nodes[src].edges[nodes[src].num_edges - 1] = dest;
}

void print_graph(Node *nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Node %d: %s\n", i, nodes[i].name);
        printf("Edges: ");
        for (int j = 0; j < nodes[i].num_edges; j++) {
            printf("%d ", nodes[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    char input_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n = 0;
    while (fscanf(fp, "%s", input_file)!= EOF) {
        n++;
    }
    rewind(fp);

    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s", nodes[i].name);
        nodes[i].num_edges = 0;
        nodes[i].edges = NULL;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, " ");
        int src = -1;
        int dest = -1;
        while (token!= NULL) {
            if (isdigit(token[0])) {
                if (src == -1) {
                    src = atoi(token);
                } else if (dest == -1) {
                    dest = atoi(token);
                } else {
                    printf("Invalid input.\n");
                    return 1;
                }
            } else {
                printf("Invalid input.\n");
                return 1;
            }
            token = strtok(NULL, " ");
        }
        add_edge(nodes, n, src, dest);
    }

    print_graph(nodes, n);

    free(nodes);
    fclose(fp);

    return 0;
}