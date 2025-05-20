//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(Node** head, int data) {
    Node* node = create_node(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node* curr = *head;
    while (curr->next!= NULL) {
        curr = curr->next;
    }
    curr->next = node;
}

void delete_node(Node** head, int data) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node not found!\n");
        return;
    }
    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

void print_list(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void reverse_list(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    reverse_list(&head);
    print_list(head);
    return 0;
}