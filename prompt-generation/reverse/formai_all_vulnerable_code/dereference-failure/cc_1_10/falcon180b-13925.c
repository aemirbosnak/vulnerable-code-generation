//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void add_node(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse_list(struct node** head) {
    struct node* prev = NULL;
    struct node* curr = *head;
    while (curr!= NULL) {
        struct node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void delete_node(struct node** head, int data) {
    struct node* curr = *head;
    struct node* prev = NULL;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node not found\n");
    } else {
        if (prev == NULL) {
            *head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

void sort_list(struct node** head) {
    struct node* curr = *head;
    struct node* prev = NULL;
    while (curr!= NULL) {
        while (curr->next!= NULL && curr->data > curr->next->data) {
            struct node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = curr;
            curr = curr->next;
        }
        prev = curr;
        curr = curr->next;
    }
    *head = prev;
}

int main() {
    struct node* head = NULL;
    add_node(&head, 5);
    add_node(&head, 3);
    add_node(&head, 7);
    add_node(&head, 1);
    add_node(&head, 9);

    printf("Original list:\n");
    print_list(head);

    reverse_list(&head);
    printf("Reversed list:\n");
    print_list(head);

    delete_node(&head, 7);
    printf("List after deleting node with data 7:\n");
    print_list(head);

    sort_list(&head);
    printf("Sorted list:\n");
    print_list(head);

    return 0;
}