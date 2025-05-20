//FormAI DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a linked list node
struct node {
    int data;
    struct node* next;
};

// Function to insert new node at the beginning of linked list
void insertAtBeginning(struct node** head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at the beginning\n", val);
}

// Function to insert new node at the end of linked list
void insertAtEnd(struct node** head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at the beginning\n", val);
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    printf("%d inserted at the end\n", val);
}

// Function to delete node from the beginning of linked list
void deleteFromBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    struct node* temp = *head;
    *head = temp->next;
    printf("%d deleted from the beginning\n", temp->data);
    free(temp);
}

// Function to delete node from the end of linked list
void deleteFromEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("%d deleted from the end\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("%d deleted from the end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Function to display the linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List contains: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node* head = NULL;
    int choice, value;
    while (1) {
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at end\n");
        printf("3. Delete node from beginning\n");
        printf("4. Delete node from end\n");
        printf("5. Display the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                deleteFromBeginning(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}