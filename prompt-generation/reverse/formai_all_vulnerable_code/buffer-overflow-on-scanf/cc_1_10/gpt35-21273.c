//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
/* This C program is an example of creating a circular linked list and inserting nodes at the end of the list. 
   The program displays the list and also finds the length of the list */

#include <stdio.h>
#include <stdlib.h>

/* A structure for creating a node in a linked list */
struct Node {
    int data;
    struct Node* next;
};

/* A function to create a new node and return the node's address */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* A function to insert a node at the end of a circular linked list */
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

/* A function to find the length of the circular linked list */
int length(struct Node* head) {
    int count = 1;
    struct Node* temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* A function to display the contents of the circular linked list */
void display(struct Node* head) {
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

/* The main function */
int main() {
    struct Node* head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter node data: ");
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("Circular Linked List: ");
    display(head);
    printf("\nLength: %d", length(head));
    return 0;
}