//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Define the structure of a node in the linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

// Define the structure of the linked list
typedef struct {
    Node *head;
} LinkedList;

// Create a new node with the given data
Node *create_node(char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// Add a new node to the end of the linked list
void add_node(LinkedList *list, char *data) {
    Node *node = create_node(data);
    Node *temp = list->head;

    // If the list is empty, set the new node as the head
    if (temp == NULL) {
        list->head = node;
        return;
    }

    // Traverse the list until the end is reached
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Set the next pointer of the last node to the new node
    temp->next = node;
}

// Print the contents of the linked list
void print_list(LinkedList *list) {
    Node *temp = list->head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

// Free the memory used by the linked list
void free_list(LinkedList *list) {
    Node *temp = list->head;
    while (temp!= NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    LinkedList list;
    list.head = NULL;

    add_node(&list, "Hello, world!");
    add_node(&list, "This is a test.");
    add_node(&list, "How are you today?");

    print_list(&list);

    free_list(&list);

    return 0;
}