//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct node* insert_beginning(struct node* head, int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

struct node* insert_end(struct node* head, int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

struct node* delete_beginning(struct node* head) {
    struct node* current = head;
    head = head->next;
    free(current);
    return head;
}

struct node* delete_end(struct node* head) {
    struct node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    struct node* temp = current->next;
    current->next = NULL;
    free(temp);
    return head;
}

int main() {
    struct node* head = NULL;
    head = insert_beginning(head, 1);
    head = insert_beginning(head, 2);
    head = insert_end(head, 3);
    head = insert_end(head, 4);
    head = delete_beginning(head);
    head = delete_end(head);
    print_list(head);
    return 0;
}