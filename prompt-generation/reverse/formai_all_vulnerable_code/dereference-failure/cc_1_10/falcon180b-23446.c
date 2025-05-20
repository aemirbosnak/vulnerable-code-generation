//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list with 5 nodes
    Node* head = NULL;
    head = (Node*) malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    Node* second = (Node*) malloc(sizeof(Node));
    second->data = 2;
    second->next = NULL;
    Node* third = (Node*) malloc(sizeof(Node));
    third->data = 3;
    third->next = NULL;
    Node* fourth = (Node*) malloc(sizeof(Node));
    fourth->data = 4;
    fourth->next = NULL;
    Node* fifth = (Node*) malloc(sizeof(Node));
    fifth->data = 5;
    fifth->next = NULL;

    // Connect the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Print the linked list
    print_list(head);

    // Reverse the linked list
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    // Print the reversed linked list
    print_list(head);

    // Free the memory used by the nodes
    Node* temp = head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}