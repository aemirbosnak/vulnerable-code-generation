//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void insert_begin(struct node** head, int data) {
    struct node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_end(struct node** head, int data) {
    struct node* new_node = create_node(data);
    struct node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void insert_pos(struct node** head, int data, int pos) {
    struct node* new_node = create_node(data);
    struct node* curr = *head;
    for (int i = 1; i < pos; i++) {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

void delete_begin(struct node** head) {
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_end(struct node** head) {
    struct node* curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

void delete_pos(struct node** head, int pos) {
    struct node* curr = *head;
    for (int i = 1; i < pos; i++) {
        curr = curr->next;
    }
    struct node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

int main() {
    struct node* head = NULL;
    insert_begin(&head, 1);
    insert_end(&head, 2);
    insert_pos(&head, 3, 1);
    print_list(head);
    delete_begin(&head);
    print_list(head);
    delete_end(&head);
    print_list(head);
    delete_pos(&head, 1);
    print_list(head);
    return 0;
}