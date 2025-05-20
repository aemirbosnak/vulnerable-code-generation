//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 100
#define MAX_LABEL_LENGTH 20

typedef struct {
    char label[MAX_LABEL_LENGTH];
    int num_links;
    int *links;
} Node;

typedef struct {
    int start;
    int end;
    int weight;
} Link;

Node nodes[MAX_NODES];
Link links[MAX_LINKS];
int num_nodes = 0;
int num_links = 0;

void add_node(char *label) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    strcpy(nodes[num_nodes].label, label);
    nodes[num_nodes].num_links = 0;
    nodes[num_nodes].links = NULL;
    num_nodes++;
}

void add_link(int start, int end, int weight) {
    if (num_links >= MAX_LINKS) {
        printf("Error: Maximum number of links reached.\n");
        exit(1);
    }
    Link *new_link = (Link *) malloc(sizeof(Link));
    new_link->start = start;
    new_link->end = end;
    new_link->weight = weight;
    links[num_links] = *new_link;
    num_links++;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", i+1, nodes[i].label);
    }
}

void print_links() {
    printf("\nLinks:\n");
    for (int i = 0; i < num_links; i++) {
        printf("%d -> %d (%d)\n", links[i].start, links[i].end, links[i].weight);
    }
}

int main() {
    add_node("Node 1");
    add_node("Node 2");
    add_node("Node 3");
    add_link(0, 1, 10);
    add_link(1, 2, 20);
    add_link(2, 0, 30);
    print_nodes();
    print_links();
    return 0;
}