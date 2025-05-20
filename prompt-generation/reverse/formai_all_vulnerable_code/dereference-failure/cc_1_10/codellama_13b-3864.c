//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: intelligent
/*
 * Linked list operations example program in an intelligent style
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Linked list node structure
 */
struct node {
    int data;
    struct node *next;
};

/*
 * Function to create a new node
 */
struct node* newNode(int data) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

/*
 * Function to insert a new node at the beginning of the list
 */
void push(struct node **head_ref, int new_data) {
    struct node *new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/*
 * Function to insert a new node at the end of the list
 */
void append(struct node **head_ref, int new_data) {
    struct node *new_node = newNode(new_data);
    struct node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

/*
 * Function to delete the first node of the list
 */
void pop(struct node **head_ref) {
    struct node *temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

/*
 * Function to delete the last node of the list
 */
void deleteLast(struct node **head_ref) {
    struct node *temp = *head_ref;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

/*
 * Function to print the list
 */
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    /* Creating a list with 3 nodes */
    struct node *head = newNode(1);
    push(&head, 2);
    append(&head, 3);
    printf("List before deleting the last node: ");
    printList(head);
    deleteLast(&head);
    printf("List after deleting the last node: ");
    printList(head);
    pop(&head);
    printf("List after deleting the first node: ");
    printList(head);
    return 0;
}