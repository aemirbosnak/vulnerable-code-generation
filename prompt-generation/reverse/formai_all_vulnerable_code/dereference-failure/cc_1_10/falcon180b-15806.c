//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*) malloc(sizeof(LinkedList));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node to the end of the list
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

// Function to remove a node from the list
void remove_node(LinkedList* list, int data) {
    Node* temp = list->head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found.\n");
    } else {
        if (prev == NULL) {
            list->head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        list->size--;
    }
}

// Function to print the list
void print_linked_list(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverse_linked_list(LinkedList* list) {
    Node* prev = NULL;
    Node* curr = list->head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    print_linked_list(list);
    reverse_linked_list(list);
    print_linked_list(list);
    remove_node(list, 2);
    print_linked_list(list);
    free(list);
    return 0;
}