//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: portable
/**
 * Linked list operations example program in a portable style
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Node structure
 */
typedef struct node {
    int data;
    struct node *next;
} Node;

/**
 * Insert node at the beginning of the list
 *
 * @param list pointer to the list
 * @param data data to be inserted
 * @return pointer to the inserted node
 */
Node *insert_front(Node **list, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
    return new_node;
}

/**
 * Insert node at the end of the list
 *
 * @param list pointer to the list
 * @param data data to be inserted
 * @return pointer to the inserted node
 */
Node *insert_back(Node **list, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
    } else {
        Node *curr = *list;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    return new_node;
}

/**
 * Remove node from the list
 *
 * @param list pointer to the list
 * @param data data to be removed
 * @return pointer to the removed node
 */
Node *remove_node(Node **list, int data) {
    Node *curr = *list;
    Node *prev = NULL;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        return NULL;
    }
    if (prev == NULL) {
        *list = curr->next;
    } else {
        prev->next = curr->next;
    }
    return curr;
}

/**
 * Print the list
 *
 * @param list pointer to the list
 */
void print_list(Node *list) {
    Node *curr = list;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node *list = NULL;
    insert_front(&list, 10);
    insert_front(&list, 20);
    insert_front(&list, 30);
    insert_back(&list, 40);
    insert_back(&list, 50);
    print_list(list);
    remove_node(&list, 40);
    print_list(list);
    return 0;
}