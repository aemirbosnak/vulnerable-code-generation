//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;  
        free(temp);          
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; 
    prev->next = temp->next;
    free(temp);
}

Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) return current;
        current = current->next;
    }
    return NULL; 
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Display the list\n");
        printf("5. Free the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter the integer to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter the integer to search: ");
                scanf("%d", &data);
                Node* foundNode = searchNode(head, data);
                if (foundNode) {
                    printf("Node with data %d found\n", foundNode->data);
                } else {
                    printf("Node with data %d not found\n", data);
                }
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                freeList(&head);
                printf("List freed\n");
                break;
            case 6:
                freeList(&head);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}