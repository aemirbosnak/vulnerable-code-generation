//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
/*
 * A unique C Linked list operations example program in a medieval style
 */

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Prototype of function to insert a node at the beginning of the list */
void insertAtBeginning(struct node **head, int data);

/* Prototype of function to insert a node at the end of the list */
void insertAtEnd(struct node **head, int data);

/* Prototype of function to insert a node after a given node */
void insertAfter(struct node **head, int data, int position);

/* Prototype of function to insert a node before a given node */
void insertBefore(struct node **head, int data, int position);

/* Prototype of function to delete a node from the list */
void deleteNode(struct node **head, int position);

/* Prototype of function to print the list */
void printList(struct node *head);

/* Function to insert a node at the beginning of the list */
void insertAtBeginning(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

/* Function to insert a node at the end of the list */
void insertAtEnd(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/* Function to insert a node after a given node */
void insertAfter(struct node **head, int data, int position) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL && temp->data != position) {
            temp = temp->next;
        }
        if (temp->data == position) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Position %d not found in the list.\n", position);
        }
    }
}

/* Function to insert a node before a given node */
void insertBefore(struct node **head, int data, int position) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL && temp->data != position) {
            temp = temp->next;
        }
        if (temp->data == position) {
            newNode->next = temp;
            *head = newNode;
        } else {
            printf("Position %d not found in the list.\n", position);
        }
    }
}

/* Function to delete a node from the list */
void deleteNode(struct node **head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
    } else {
        struct node *temp = *head;
        while (temp->next != NULL && temp->data != position) {
            temp = temp->next;
        }
        if (temp->data == position) {
            *head = temp->next;
            free(temp);
        } else {
            printf("Position %d not found in the list.\n", position);
        }
    }
}

/* Function to print the list */
void printList(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    /* Initialize the list */
    struct node *head = NULL;

    /* Insert nodes at the beginning of the list */
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);

    /* Insert nodes at the end of the list */
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    /* Insert nodes after a given node */
    insertAfter(&head, 50, 20);
    insertAfter(&head, 60, 50);

    /* Insert nodes before a given node */
    insertBefore(&head, 15, 20);
    insertBefore(&head, 25, 15);

    /* Delete a node from the list */
    deleteNode(&head, 15);

    /* Print the list */
    printList(head);

    /* Free the list */
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}