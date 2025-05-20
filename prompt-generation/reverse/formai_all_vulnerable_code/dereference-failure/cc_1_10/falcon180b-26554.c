//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    if (new_list == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node at the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    Node* temp = list->head;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Function to delete a node from the linked list
void delete_node(LinkedList* list, int data) {
    Node* temp = list->head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        list->head = temp->next;
        free(temp);
        list->size--;
    } else {
        while (temp!= NULL && temp->data!= data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node not found\n");
        } else {
            prev->next = temp->next;
            free(temp);
            list->size--;
        }
    }
}

// Function to display the linked list
void display_linked_list(LinkedList* list) {
    Node* temp = list->head;
    if (temp == NULL) {
        printf("Empty list\n");
    } else {
        printf("Linked List: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to reverse the linked list
void reverse_linked_list(LinkedList* list) {
    Node* start = list->head;
    Node* end = NULL;
    Node* next = NULL;
    while (start!= NULL) {
        next = start->next;
        start->next = end;
        end = start;
        start = next;
    }
    list->head = end;
}

int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    add_node(list, 4);
    display_linked_list(list);
    reverse_linked_list(list);
    display_linked_list(list);
    delete_node(list, 3);
    display_linked_list(list);
    return 0;
}