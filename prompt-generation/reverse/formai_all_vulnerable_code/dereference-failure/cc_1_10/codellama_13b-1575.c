//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: introspective
/*
 * Linked list operations example program
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create_node(int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* insert_begin(struct Node* head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

struct Node* insert_end(struct Node* head, int data) {
    struct Node *new_node = create_node(data);
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

struct Node* delete_begin(struct Node* head) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* delete_end(struct Node* head) {
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

int main() {
    struct Node *head = NULL;

    // Insert elements in the beginning
    head = insert_begin(head, 1);
    head = insert_begin(head, 2);
    head = insert_begin(head, 3);

    // Insert elements in the end
    head = insert_end(head, 4);
    head = insert_end(head, 5);

    // Delete elements from the beginning
    head = delete_begin(head);
    head = delete_begin(head);
    head = delete_begin(head);

    // Delete elements from the end
    head = delete_end(head);
    head = delete_end(head);

    // Print the remaining elements
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}