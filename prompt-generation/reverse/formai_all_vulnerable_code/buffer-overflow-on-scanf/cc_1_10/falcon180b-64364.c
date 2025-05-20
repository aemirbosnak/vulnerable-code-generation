//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10
#define MAX_EDGES 20

typedef struct {
    int id;
    int degree;
    int *neighbors;
} Node;

void create_graph(Node *nodes, int num_nodes) {
    int i, j, k;
    for (i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].degree = 0;
        nodes[i].neighbors = (int *) malloc(MAX_EDGES * sizeof(int));
        for (j = 0; j < MAX_EDGES; j++) {
            nodes[i].neighbors[j] = -1;
        }
    }

    srand(time(NULL));
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < MAX_EDGES; j++) {
            k = rand() % num_nodes;
            if (i!= k) {
                nodes[i].neighbors[j] = k;
                nodes[k].degree++;
            }
        }
    }
}

void print_graph(Node *nodes, int num_nodes) {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (j = 0; j < MAX_EDGES; j++) {
            if (nodes[i].neighbors[j]!= -1) {
                printf("%d ", nodes[i].neighbors[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    Node nodes[MAX_NODES];
    create_graph(nodes, num_nodes);

    printf("Generated graph:\n");
    print_graph(nodes, num_nodes);

    return 0;
}