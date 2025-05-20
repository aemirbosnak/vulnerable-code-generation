//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINES 500

typedef struct node {
    char name[20];
    int connected_nodes[MAX_NODES];
    int connected_nodes_count;
} Node;

typedef struct line {
    Node* node1;
    Node* node2;
} Line;

Node nodes[MAX_NODES];
Line lines[MAX_LINES];
int lines_count = 0;

void add_node(char* name) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].connected_nodes_count == 0) {
            strcpy(nodes[i].name, name);
            break;
        }
    }
}

void add_line(char* node1_name, char* node2_name) {
    int node1_index, node2_index;
    node1_index = find_node(node1_name);
    node2_index = find_node(node2_name);
    lines[lines_count].node1 = &nodes[node1_index];
    lines[lines_count].node2 = &nodes[node2_index];
    lines_count++;
}

int find_node(char* name) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_nodes() {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].connected_nodes_count > 0) {
            printf("%s\n", nodes[i].name);
        }
    }
}

void print_lines() {
    int i;
    for (i = 0; i < lines_count; i++) {
        printf("%s - %s\n", lines[i].node1->name, lines[i].node2->name);
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (add_node, add_line, print_nodes, print_lines, quit): ");
        scanf("%s", input);
        if (strcmp(input, "add_node") == 0) {
            scanf("%s", input);
            add_node(input);
        } else if (strcmp(input, "add_line") == 0) {
            scanf("%s %s", input, input);
            add_line(input, input);
        } else if (strcmp(input, "print_nodes") == 0) {
            print_nodes();
        } else if (strcmp(input, "print_lines") == 0) {
            print_lines();
        } else if (strcmp(input, "quit") == 0) {
            break;
        }
    }
    return 0;
}