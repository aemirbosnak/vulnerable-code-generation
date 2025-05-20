//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct list {
    Node* head;
    int size;
} List;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Add a node to the end of the list
void list_append(List* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

// Remove a node from the list by its data
bool list_remove(List* list, int data) {
    if (list->head == NULL) {
        return false;
    }
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return true;
    }
    Node* current = list->head;
    while (current->next!= NULL && current->next->data!= data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return false;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
    return true;
}

// Print the list
void list_print(List* list) {
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    List* my_list = (List*)malloc(sizeof(List));
    my_list->head = NULL;
    my_list->size = 0;

    // Add some nodes to the list
    list_append(my_list, 10);
    list_append(my_list, 20);
    list_append(my_list, 30);

    // Print the list
    list_print(my_list);

    // Remove a node from the list
    list_remove(my_list, 20);

    // Print the list again
    list_print(my_list);

    // Free the memory used by the list
    free(my_list);

    return 0;
}