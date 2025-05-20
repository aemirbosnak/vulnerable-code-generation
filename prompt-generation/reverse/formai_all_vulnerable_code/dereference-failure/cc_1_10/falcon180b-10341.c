//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a linked list structure
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node at the end of the list
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

// Function to delete a node with given data
void delete_node(LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    } else {
        Node* prev = list->head;
        Node* curr = prev->next;
        while (curr!= NULL && curr->data!= data) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("Node not found\n");
        } else {
            prev->next = curr->next;
            free(curr);
            list->size--;
        }
    }
}

// Function to display the linked list
void display_list(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    display_list(list);
    delete_node(list, 2);
    display_list(list);
    delete_node(list, 1);
    display_list(list);
    delete_node(list, 3);
    display_list(list);
    free(list);
    return 0;
}