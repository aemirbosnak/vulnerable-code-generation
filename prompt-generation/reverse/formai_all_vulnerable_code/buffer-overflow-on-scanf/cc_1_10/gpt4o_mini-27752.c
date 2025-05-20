//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Node* next;
} Node;

typedef struct Topology {
    Node* head;
    int count;
} Topology;

Topology* create_topology() {
    Topology* topology = (Topology*)malloc(sizeof(Topology));
    topology->head = NULL;
    topology->count = 0;
    return topology;
}

Node* create_node(const char* name, int id) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}

void add_node(Topology* topology, const char* name) {
    Node* new_node = create_node(name, topology->count);
    new_node->next = topology->head;
    topology->head = new_node;
    topology->count++;
}

void display_topology(const Topology* topology) {
    Node* current = topology->head;
    printf("Network Topology:\n");
    if (current == NULL) {
        printf("No nodes found.\n");
    } else {
        while (current != NULL) {
            printf("Node ID: %d, Name: %s\n", current->id, current->name);
            current = current->next;
        }
    }
}

void free_topology(Topology* topology) {
    Node* current = topology->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(topology);
}

int main() {
    Topology* my_topology = create_topology();
    
    printf("Welcome to the Network Topology Mapper!\n");
    
    int choice;
    char node_name[MAX_NAME_LENGTH];
    
    do {
        printf("\n1. Add Node\n2. Display Topology\n0. Exit\nChoose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", node_name);
                add_node(my_topology, node_name);
                printf("Node '%s' added!\n", node_name);
                break;
            case 2:
                display_topology(my_topology);
                break;
            case 0:
                printf("Exiting... Freeing resources.\n");
                free_topology(my_topology);
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}