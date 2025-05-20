//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// define linked list structure
typedef struct linked_list {
    Node* head;
} LinkedList;

// create new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// insert node at end of list
void insert_end(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }
    Node* temp = list->head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// delete node with given data
void delete_node(LinkedList* list, int data) {
    Node* temp = list->head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// print linked list
void print_list(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// main function
int main() {
    LinkedList list;
    list.head = NULL;

    // insert nodes
    insert_end(&list, 1);
    insert_end(&list, 2);
    insert_end(&list, 3);

    // print linked list
    print_list(&list);

    // delete node with data 2
    delete_node(&list, 2);

    // print linked list
    print_list(&list);

    return 0;
}