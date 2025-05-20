//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: expert-level
/*
 * Linked list operations example program
 *
 * This program demonstrates the basic operations on a linked list,
 * such as inserting, deleting, and searching for elements.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Linked list node structure
 */
typedef struct node {
    int data;
    struct node *next;
} Node;

/*
 * Insert a node at the beginning of the list
 */
void insert_begin(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

/*
 * Insert a node at the end of the list
 */
void insert_end(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

/*
 * Delete a node from the list
 */
void delete(Node **head, int data) {
    if (*head == NULL) {
        return;
    }

    Node *current = *head;
    if (current->data == data) {
        *head = current->next;
        free(current);
        return;
    }

    while (current->next != NULL) {
        if (current->next->data == data) {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

/*
 * Search for a node in the list
 */
int search(Node *head, int data) {
    if (head == NULL) {
        return -1;
    }

    int index = 0;
    while (head != NULL) {
        if (head->data == data) {
            return index;
        }
        head = head->next;
        index++;
    }

    return -1;
}

/*
 * Print the list
 */
void print(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    // Insert elements
    insert_begin(&head, 1);
    insert_begin(&head, 2);
    insert_end(&head, 3);
    insert_end(&head, 4);
    insert_end(&head, 5);

    // Search for an element
    int index = search(head, 3);
    printf("Element 3 is at index %d\n", index);

    // Delete an element
    delete(&head, 2);
    print(head);

    // Print the list
    print(head);

    return 0;
}