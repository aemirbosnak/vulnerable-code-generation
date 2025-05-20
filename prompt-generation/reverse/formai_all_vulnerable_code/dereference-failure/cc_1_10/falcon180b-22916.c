//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 200

// Node structure
struct node {
    char name[20];
    int id;
    struct node *next;
};

// Link structure
struct link {
    int src_id;
    int dest_id;
    struct link *next;
};

// Function to add a node to the network
void add_node(struct node **head, char *name) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->id = (*head)->id + 1;
    new_node->next = (*head);
    (*head) = new_node;
}

// Function to add a link to the network
void add_link(struct link **head, int src_id, int dest_id) {
    struct link *new_link = (struct link *)malloc(sizeof(struct link));
    new_link->src_id = src_id;
    new_link->dest_id = dest_id;
    new_link->next = (*head);
    (*head) = new_link;
}

// Function to display the network topology
void display_network(struct node *head) {
    struct node *temp = head;
    printf("Network topology:\n");
    while (temp!= NULL) {
        printf("%s (%d)\n", temp->name, temp->id);
        temp = temp->next;
    }
}

// Function to display the link connections
void display_links(struct link *head) {
    struct link *temp = head;
    printf("\nLink connections:\n");
    while (temp!= NULL) {
        printf("Link from %d to %d\n", temp->src_id, temp->dest_id);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct node *head = NULL;
    struct link *link_head = NULL;

    // Add nodes to the network
    add_node(&head, "Node 1");
    add_node(&head, "Node 2");
    add_node(&head, "Node 3");
    add_node(&head, "Node 4");

    // Add links to the network
    add_link(&link_head, 1, 2);
    add_link(&link_head, 1, 3);
    add_link(&link_head, 2, 4);

    // Display the network topology
    printf("\nNetwork topology:\n");
    display_network(head);

    // Display the link connections
    printf("\nLink connections:\n");
    display_links(link_head);

    return 0;
}