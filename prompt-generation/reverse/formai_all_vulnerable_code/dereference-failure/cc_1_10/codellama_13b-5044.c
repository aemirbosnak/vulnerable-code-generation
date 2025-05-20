//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[32];
    struct node *next;
};

struct link {
    char src[32];
    char dest[32];
    struct link *next;
};

struct topology {
    struct node *nodes;
    struct link *links;
};

struct topology *topo_init(void) {
    struct topology *topo = malloc(sizeof(struct topology));
    topo->nodes = NULL;
    topo->links = NULL;
    return topo;
}

void topo_add_node(struct topology *topo, char *name) {
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->next = topo->nodes;
    topo->nodes = new_node;
}

void topo_add_link(struct topology *topo, char *src, char *dest) {
    struct link *new_link = malloc(sizeof(struct link));
    strcpy(new_link->src, src);
    strcpy(new_link->dest, dest);
    new_link->next = topo->links;
    topo->links = new_link;
}

void topo_print(struct topology *topo) {
    printf("Nodes:\n");
    struct node *curr_node = topo->nodes;
    while (curr_node != NULL) {
        printf("- %s\n", curr_node->name);
        curr_node = curr_node->next;
    }
    printf("\nLinks:\n");
    struct link *curr_link = topo->links;
    while (curr_link != NULL) {
        printf("- %s -> %s\n", curr_link->src, curr_link->dest);
        curr_link = curr_link->next;
    }
}

int main(void) {
    struct topology *topo = topo_init();
    topo_add_node(topo, "A");
    topo_add_node(topo, "B");
    topo_add_node(topo, "C");
    topo_add_link(topo, "A", "B");
    topo_add_link(topo, "A", "C");
    topo_add_link(topo, "B", "C");
    topo_print(topo);
    return 0;
}