//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: surrealist
// Linked list operations in a surrealist style

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node* insert_node(struct node* head, int data) {
    struct node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

struct node* delete_node(struct node* head, int data) {
    if (head == NULL) {
        return NULL;
    }
    struct node* current = head;
    if (current->data == data) {
        head = head->next;
        free(current);
        return head;
    }
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next != NULL) {
        struct node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

void print_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);
    head = insert_node(head, 5);
    print_list(head);
    head = delete_node(head, 3);
    print_list(head);
    head = delete_node(head, 5);
    print_list(head);
    return 0;
}