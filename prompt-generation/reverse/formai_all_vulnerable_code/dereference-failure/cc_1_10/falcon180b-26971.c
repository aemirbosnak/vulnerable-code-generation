//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 100
#define MAX_LINKS 100

typedef struct node {
    char name[50];
    int num_links;
    struct link *links[MAX_LINKS];
} Node;

typedef struct link {
    Node *node1;
    Node *node2;
    double resistance;
} Link;

int num_components = 0;
int num_nodes = 0;
int num_links = 0;

Node *components[MAX_COMPONENTS];
Node *nodes[MAX_NODES];
Link *links[MAX_LINKS];

void add_component() {
    num_components++;
    components[num_components - 1] = (Node *)malloc(sizeof(Node));
    components[num_components - 1]->num_links = 0;
    strcpy(components[num_components - 1]->name, "Component");
}

void add_node() {
    num_nodes++;
    nodes[num_nodes - 1] = (Node *)malloc(sizeof(Node));
    strcpy(nodes[num_nodes - 1]->name, "Node");
    nodes[num_nodes - 1]->num_links = 0;
}

void add_link() {
    num_links++;
    links[num_links - 1] = (Link *)malloc(sizeof(Link));
    strcpy(links[num_links - 1]->node1->name, "Node1");
    strcpy(links[num_links - 1]->node2->name, "Node2");
    links[num_links - 1]->resistance = 0;
}

int main() {
    add_component();
    add_node();
    add_link();

    return 0;
}