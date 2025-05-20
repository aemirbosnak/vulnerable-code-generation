//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 200

struct node {
    char name[20];
    int id;
};

struct link {
    int source;
    int destination;
    int weight;
};

void add_node(struct node *nodes, int count, char *name) {
    int i = 0;
    while (i < count && strcmp(nodes[i].name, name)!= 0) {
        i++;
    }
    if (i == count) {
        nodes[count].id = count;
        strcpy(nodes[count].name, name);
        count++;
    }
}

void add_link(struct link *links, int count, int source, int destination, int weight) {
    links[count].source = source;
    links[count].destination = destination;
    links[count].weight = weight;
    count++;
}

int main() {
    struct node nodes[MAX_NODES];
    int node_count = 0;
    char input[100];
    while (node_count < MAX_NODES) {
        printf("Enter a node name (or type 'done' to finish): ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        add_node(nodes, node_count, input);
        node_count++;
    }

    struct link links[MAX_LINKS];
    int link_count = 0;
    while (link_count < MAX_LINKS) {
        printf("Enter a link (or type 'done' to finish): ");
        scanf("%d %d %d", &links[link_count].source, &links[link_count].destination, &links[link_count].weight);
        link_count++;
    }

    // TODO: Implement network topology mapping algorithm

    return 0;
}