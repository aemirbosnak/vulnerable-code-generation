//Falcon-180B DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a structure for a linked list
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Function prototypes
LinkedList* create_linked_list();
void add_node(LinkedList* list, int data);
void print_linked_list(LinkedList* list);
void free_linked_list(LinkedList* list);

int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    print_linked_list(list);
    free_linked_list(list);
    return 0;
}

// Create an empty linked list
LinkedList* create_linked_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Add a node to the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
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

// Print the contents of the linked list
void print_linked_list(LinkedList* list) {
    Node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free the memory used by the linked list
void free_linked_list(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}