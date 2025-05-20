//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/* Define a structure to represent a node in the linked list */
typedef struct node {
    int data;
    struct node* next;
} Node;

/* Function to insert a new node at the end of the list */
void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Function to delete a node with a given value from the list */
void delete(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Function to search for a node with a given value in the list */
Node* search(Node* head, int value) {
    Node* temp = head;
    while (temp!= NULL && temp->data!= value) {
        temp = temp->next;
    }

    return temp;
}

/* Function to print the list */
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main function */
int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &value);
                Node* result = search(head, value);
                if (result!= NULL) {
                    printf("Found\n");
                } else {
                    printf("Not found\n");
                }
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}