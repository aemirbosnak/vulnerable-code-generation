//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
// C Network Topology Mapper Example Program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Structure to store information about a node in the network
struct node {
    char name[100];
    int ip;
    int port;
    struct node *next;
};

// Function to create a new node
struct node* create_node(char* name, int ip, int port) {
    struct node* node = malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->ip = ip;
    node->port = port;
    node->next = NULL;
    return node;
}

// Function to add a new node to the linked list
void add_node(struct node* head, struct node* new_node) {
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to print the linked list
void print_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("Name: %s, IP: %d, Port: %d\n", current->name, current->ip, current->port);
        current = current->next;
    }
}

// Main function
int main() {
    // Create a new linked list to store nodes
    struct node* head = create_node("Node 1", 192, 80);
    struct node* node2 = create_node("Node 2", 192, 81);
    struct node* node3 = create_node("Node 3", 192, 82);
    add_node(head, node2);
    add_node(head, node3);
    print_list(head);
    return 0;
}