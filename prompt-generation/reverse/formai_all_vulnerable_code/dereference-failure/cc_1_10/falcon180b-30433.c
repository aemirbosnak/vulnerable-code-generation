//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* create_node(int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(node_t** head, int data) {
    node_t* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_node(node_t** head, int data) {
    node_t* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found.\n");
        return;
    }
    temp->next = temp->next->next;
    free(temp->next);
}

void print_list(node_t* head) {
    node_t* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search_node(node_t* head, int data) {
    node_t* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    node_t* head = NULL;
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    print_list(head);
    delete_node(&head, 20);
    print_list(head);
    printf("%d\n", search_node(head, 30));
    return 0;
}