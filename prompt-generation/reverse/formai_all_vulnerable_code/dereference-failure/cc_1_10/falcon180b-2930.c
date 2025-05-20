//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_list(int size) {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* tail = head;

    for (int i = 0; i < size; i++) {
        tail->data = i;
        tail->next = (Node*)malloc(sizeof(Node));
        tail = tail->next;
    }

    tail->next = NULL;
    return head;
}

void print_list(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void add_element(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
    } else {
        Node* current = *head;

        while (current->next!= NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
}

void delete_element(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
    } else {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
    }
}

void reverse_list(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    Node* head = create_list(10);
    print_list(head);

    add_element(&head, 20);
    print_list(head);

    delete_element(&head, 5);
    print_list(head);

    reverse_list(&head);
    print_list(head);

    return 0;
}