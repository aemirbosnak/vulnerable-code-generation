//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct linkedlist {
    Node* head;
    int size;
} LinkedList;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    if (new_list == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Add a node to the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Remove a node from the linked list
void remove_node(LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("Error: Linked list is empty\n");
        return;
    }
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }
    Node* temp = list->head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Error: Node not found\n");
    } else {
        Node* node_to_remove = temp->next;
        temp->next = temp->next->next;
        free(node_to_remove);
        list->size--;
    }
}

// Print the linked list
void print_linked_list(LinkedList* list) {
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    Node* temp = list->head;
    printf("Linked list: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 10);
    add_node(list, 20);
    add_node(list, 30);
    print_linked_list(list);
    remove_node(list, 20);
    print_linked_list(list);
    remove_node(list, 10);
    print_linked_list(list);
    remove_node(list, 30);
    print_linked_list(list);
    free(list);
    return 0;
}