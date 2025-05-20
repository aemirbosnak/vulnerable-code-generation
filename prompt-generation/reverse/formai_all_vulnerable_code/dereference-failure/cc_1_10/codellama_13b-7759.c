//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: calm
/* Linked List Operations Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_list(int n) {
    struct node *head = NULL, *temp = NULL;
    int i;
    for (i = 0; i < n; i++) {
        temp = (struct node*) malloc(sizeof(struct node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    return head;
}

void display_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(struct node **head, int index, int data) {
    struct node *temp = *head;
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_node(struct node **head, int index) {
    struct node *temp = *head;
    if (index == 0) {
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next);
    }
}

int main() {
    struct node *head = NULL;
    head = create_list(5);
    display_list(head);
    insert_node(&head, 3, 10);
    display_list(head);
    delete_node(&head, 3);
    display_list(head);
    return 0;
}