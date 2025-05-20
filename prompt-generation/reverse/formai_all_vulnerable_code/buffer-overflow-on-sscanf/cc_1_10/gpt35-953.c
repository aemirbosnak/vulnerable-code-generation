//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

// structure to store information about a node
typedef struct node {
    char name[20];
    int num_of_links;
    struct node* links[MAX_NODES];
} Node;

// add a link to a node
void add_link(Node* node, Node* link) {
    if (node->num_of_links < MAX_NODES) {
        node->links[node->num_of_links++] = link;
    } else {
        printf("Maximum number of links reached for node %s\n", node->name);
    }
}

// display the links of a node
void display_links(Node* node) {
    int i;
    printf("Links for node %s:\n", node->name);
    for (i = 0; i < node->num_of_links; i++) {
        printf("- %s\n", node->links[i]->name);
    }
}

int main() {
    Node* nodes[MAX_NODES];
    int num_of_nodes = 0;
    char input[50];
    char* token;

    // read node information from user input
    printf("Enter node information in the following format:\n");
    printf("node_name link1_name link2_name link3_name ...\n");
    printf("Enter 'done' when finished.\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        if (strcmp(input, "done\n") == 0) {
            break;
        }
        printf("Input: %s", input);
        Node* node = (Node*) malloc(sizeof(Node));
        sscanf(input, "%s", node->name);
        node->num_of_links = 0;
        token = strtok(input, " ");
        while (token != NULL) {
            Node* link = NULL;
            // check if link is already a node
            int i;
            for (i = 0; i < num_of_nodes; i++) {
                if (strcmp(nodes[i]->name, token) == 0) {
                    link = nodes[i];
                    break;
                }
            }
            // create a new node for the link if it does not exist
            if (link == NULL && num_of_nodes < MAX_NODES) {
                link = (Node*) malloc(sizeof(Node));
                strcpy(link->name, token);
                link->num_of_links = 0;
                nodes[num_of_nodes++] = link;
            }
            add_link(node, link);
            token = strtok(NULL, " ");
        }
        nodes[num_of_nodes++] = node;
    }

    // display the links for each node
    int i;
    for (i = 0; i < num_of_nodes; i++) {
        display_links(nodes[i]);
    }

    // free memory allocated for nodes
    for (i = 0; i < num_of_nodes; i++) {
        free(nodes[i]);
    }

    return 0;
}