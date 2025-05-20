//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data;
    struct node* next;
};

// Function to create a new node with given data
struct node* createNode(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct node** head, char data) {
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    }
    else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a node with given data
struct node* searchNode(struct node* head, char data) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node with given data
void deleteNode(struct node** head, char data) {
    struct node* temp = *head;
    struct node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice, data;

    do {
        printf("1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf(" %c", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf(" %c", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf(" %c", &data);
                struct node* result = searchNode(head, data);
                if (result!= NULL) {
                    printf("Node found\n");
                }
                else {
                    printf("Node not found\n");
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
    } while (1);

    return 0;
}