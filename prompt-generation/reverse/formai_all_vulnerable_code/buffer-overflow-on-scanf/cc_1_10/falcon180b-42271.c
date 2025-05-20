//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINES 500

typedef struct node {
    char name[20];
    int connected_to[MAX_NODES];
    int num_connections;
} Node;

typedef struct line {
    int from_node;
    int to_node;
} Line;

int num_nodes, num_lines;
Node nodes[MAX_NODES];
Line lines[MAX_LINES];

void add_node() {
    printf("Enter node name: ");
    char name[20];
    scanf("%s", name);
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(name, nodes[i].name) == 0) {
            printf("Node already exists.\n");
            return;
        }
    }
    strcpy(nodes[num_nodes].name, name);
    num_nodes++;
}

void add_line() {
    printf("Enter from node: ");
    int from_node;
    scanf("%d", &from_node);
    printf("Enter to node: ");
    int to_node;
    scanf("%d", &to_node);
    for (int i = 0; i < num_lines; i++) {
        if (lines[i].from_node == from_node && lines[i].to_node == to_node) {
            printf("Line already exists.\n");
            return;
        }
    }
    lines[num_lines].from_node = from_node;
    lines[num_lines].to_node = to_node;
    num_lines++;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%s\n", nodes[i].name);
    }
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("From %d to %d\n", lines[i].from_node, lines[i].to_node);
    }
}

int main() {
    num_nodes = 0;
    num_lines = 0;
    add_node();
    while (num_nodes < 2) {
        add_node();
    }
    while (num_lines < num_nodes - 1) {
        add_line();
    }
    print_nodes();
    print_lines();
    return 0;
}