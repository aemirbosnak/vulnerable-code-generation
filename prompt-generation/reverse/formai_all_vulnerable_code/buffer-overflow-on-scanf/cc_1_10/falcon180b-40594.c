//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define PORT 8080
#define BUFFER_SIZE 1024

struct node {
    char ip[16];
    int port;
    struct node *next;
};

void add_node(struct node **head, char *ip, int port) {
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->ip, ip);
    new_node->port = port;
    new_node->next = *head;
    *head = new_node;
}

struct node *get_node(struct node *head, char *ip) {
    struct node *curr_node = head;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->ip, ip) == 0) {
            return curr_node;
        }
        curr_node = curr_node->next;
    }
    return NULL;
}

void print_nodes(struct node *head) {
    struct node *curr_node = head;
    while (curr_node!= NULL) {
        printf("%s:%d\n", curr_node->ip, curr_node->port);
        curr_node = curr_node->next;
    }
}

int main() {
    struct node *head = NULL;
    char ip[16];
    int port;

    printf("Enter the IP address and port number of the first node: ");
    scanf("%s %d", ip, &port);
    add_node(&head, ip, port);

    int num_nodes;
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    for (int i = 1; i < num_nodes; i++) {
        printf("Enter the IP address and port number of node %d: ", i);
        scanf("%s %d", ip, &port);
        add_node(&head, ip, port);
    }

    print_nodes(head);

    return 0;
}