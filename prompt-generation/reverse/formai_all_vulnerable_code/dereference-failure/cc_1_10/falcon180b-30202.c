//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

//Define a struct for a node
typedef struct node {
    int data;
    struct node* next;
} Node;

//Define a struct for a linked list
typedef struct linked_list {
    Node* head;
    int length;
} LinkedList;

//Create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//Create a new linked list
LinkedList* create_linked_list() {
    LinkedList* new_linked_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_linked_list->head = NULL;
    new_linked_list->length = 0;
    return new_linked_list;
}

//Add a node to the end of a linked list
void add_node(LinkedList* linked_list, int data) {
    Node* new_node = create_node(data);
    if(linked_list->head == NULL) {
        linked_list->head = new_node;
    } else {
        Node* current_node = linked_list->head;
        while(current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    linked_list->length++;
}

//Print a linked list
void print_linked_list(LinkedList* linked_list) {
    Node* current_node = linked_list->head;
    printf("Linked List: ");
    while(current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

//Main function
int main() {
    //Create a new linked list
    LinkedList* linked_list = create_linked_list();

    //Add nodes to the linked list
    add_node(linked_list, 1);
    add_node(linked_list, 2);
    add_node(linked_list, 3);
    add_node(linked_list, 4);
    add_node(linked_list, 5);

    //Print the linked list
    print_linked_list(linked_list);

    //Free memory
    Node* current_node = linked_list->head;
    while(current_node!= NULL) {
        Node* temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    free(linked_list);

    return 0;
}