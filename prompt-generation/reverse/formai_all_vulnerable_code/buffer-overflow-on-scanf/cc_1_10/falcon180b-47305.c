//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 1000

typedef struct {
    int id;
    char name[20];
    int link_count;
    int *links;
} Node;

typedef struct {
    int from;
    int to;
    int weight;
} Link;

Node nodes[MAX_NODES];
Link links[MAX_LINKS];
int link_count = 0;

void add_node(int id, char *name) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].id == -1) {
            nodes[i].id = id;
            strcpy(nodes[i].name, name);
            nodes[i].link_count = 0;
            nodes[i].links = NULL;
            break;
        }
    }
}

void add_link(int from, int to, int weight) {
    Link l;
    l.from = from;
    l.to = to;
    l.weight = weight;
    links[link_count++] = l;
}

void print_links() {
    int i;
    for (i = 0; i < link_count; i++) {
        printf("%d -> %d (%d)\n", links[i].from, links[i].to, links[i].weight);
    }
}

int main() {
    int i, j, k;
    char input[100];
    int id, weight;
    char name[20];

    printf("Enter number of nodes: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        printf("Enter node %d name: ", i+1);
        scanf("%s", name);
        add_node(i+1, name);
    }

    printf("Enter number of links: ");
    scanf("%d", &j);

    for (i = 0; i < j; i++) {
        printf("Enter link %d from node: ", i+1);
        scanf("%d", &id);
        printf("Enter link %d to node: ", i+1);
        scanf("%d", &k);
        printf("Enter link %d weight: ", i+1);
        scanf("%d", &weight);
        add_link(id-1, k-1, weight);
    }

    printf("Network topology:\n");
    for (i = 0; i < k; i++) {
        printf("Node %d: %s\n", i+1, nodes[i].name);
        printf("Links:\n");
        print_links();
    }

    return 0;
}