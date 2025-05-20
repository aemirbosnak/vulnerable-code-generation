//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Node structure for linked list
typedef struct node {
    char data[MAX_LENGTH];
    struct node* next;
} Node;

// Linked list structure
typedef struct list {
    Node* head;
    int size;
} List;

// Function to create a new node
Node* create_node(char* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(List* list, char* data) {
    Node* new_node = create_node(data);
    Node* temp = list->head;
    if (temp == NULL) {
        list->head = new_node;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Function to remove a node from the list
void remove_node(List* list, char* data) {
    Node* prev = NULL;
    Node* temp = list->head;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    list->size--;
}

// Function to display the list
void display_list(List* list) {
    Node* temp = list->head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    List* my_list = (List*)malloc(sizeof(List));
    if (my_list == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    my_list->head = NULL;
    my_list->size = 0;

    add_node(my_list, "Hello");
    add_node(my_list, "World");
    display_list(my_list);

    remove_node(my_list, "World");
    display_list(my_list);

    free(my_list);
    return 0;
}