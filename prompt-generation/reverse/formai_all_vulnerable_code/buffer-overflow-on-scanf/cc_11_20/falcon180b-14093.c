//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int connected_nodes[MAX_NODES];
    int num_connected_nodes;
} Node;

int main() {
    int num_nodes, num_lines;
    char input_line[MAX_LINE_LENGTH];
    Node nodes[MAX_NODES];
    int i, j, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i);
        scanf("%s", nodes[i].name);
    }

    printf("Enter the number of lines: ");
    scanf("%d", &num_lines);

    for (i = 0; i < num_lines; i++) {
        printf("Enter the details of line %d:\n", i);
        printf("Enter the name of the first node: ");
        scanf("%s", input_line);
        j = -1;
        for (k = 0; k < num_nodes; k++) {
            if (strcmp(nodes[k].name, input_line) == 0) {
                j = k;
                break;
            }
        }
        if (j == -1) {
            printf("Invalid node name.\n");
            exit(1);
        }
        printf("Enter the name of the second node: ");
        scanf("%s", input_line);
        k = -1;
        for (j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j].name, input_line) == 0) {
                k = j;
                break;
            }
        }
        if (k == -1) {
            printf("Invalid node name.\n");
            exit(1);
        }
        nodes[j].connected_nodes[nodes[j].num_connected_nodes++] = k;
        nodes[k].connected_nodes[nodes[k].num_connected_nodes++] = j;
    }

    printf("Network topology:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %s:\n", nodes[i].name);
        printf("Connected nodes: ");
        for (j = 0; j < nodes[i].num_connected_nodes; j++) {
            printf("%s ", nodes[nodes[i].connected_nodes[j]].name);
        }
        printf("\n");
    }

    return 0;
}