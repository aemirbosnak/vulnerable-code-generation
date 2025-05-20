//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: grateful
/*
 * This program visualizes a linked list data structure using ASCII art.
 * The linked list is implemented as a struct with two fields: data and next.
 * The data field stores an integer value, while the next field points to the
 * next node in the list. The linked list is created dynamically at runtime
 * using malloc() and linked together using pointer arithmetic.
 */

#include <stdio.h>
#include <stdlib.h>

/* Define node struct */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Function prototypes */
void create_list(Node **head);
void print_list(Node *head);

int main() {
    Node *head = NULL;

    /* Create linked list */
    create_list(&head);

    /* Print linked list */
    printf("Linked List:\n");
    print_list(head);

    return 0;
}

/*
 * Function: create_list
 * Parameters:
 *   - head (Node**): pointer to head of linked list
 * Returns: None
 * Description: This function creates a linked list dynamically at runtime
 *              using malloc() and links the nodes together using pointer
 *              arithmetic. The head of the linked list is passed by reference
 *              to allow modification of the head pointer in the calling function.
*/
void create_list(Node **head) {
    int i, n;
    Node *curr = NULL;

    /* Get number of nodes from user */
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* Create first node */
    curr = (Node*) malloc(sizeof(Node));
    curr->data = 0;
    curr->next = NULL;
    *head = curr;

    /* Create remaining nodes */
    for (i = 1; i < n; i++) {
        curr->next = (Node*) malloc(sizeof(Node));
        curr->next->data = i;
        curr->next->next = NULL;
        curr = curr->next;
    }
}

/*
 * Function: print_list
 * Parameters:
 *   - head (Node*): head of linked list
 * Returns: None
 * Description: This function prints the linked list using ASCII art to
 *              visualize the nodes and their connections.
*/
void print_list(Node *head) {
    Node *curr = head;
    int i = 0;

    /* Print each node */
    while (curr!= NULL) {
        printf("Node %d: %d\n", i++, curr->data);

        /* Move to next node */
        curr = curr->next;
    }
}