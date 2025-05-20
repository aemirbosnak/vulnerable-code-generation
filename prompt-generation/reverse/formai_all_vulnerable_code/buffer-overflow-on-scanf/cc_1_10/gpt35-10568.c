//FormAI DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
    printf("%d inserted at the beginning!\n", data);
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at the end!\n", data);
}

void deleteNode(Node **head, int data) {
    if (*head == NULL) {
        printf("Linked list is empty!\n");
    } else {
        Node *temp = *head;
        Node *prev = NULL;
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("%d not found in the linked list!\n", data);
        } else if (prev == NULL) {
            *head = temp->next;
            printf("%d deleted from the beginning!\n", data);
            free(temp);
        } else {
            prev->next = temp->next;
            printf("%d deleted from the linked list!\n", data);
            free(temp);
        }
    }
}

void printList(Node *head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
    } else {
        printf("Linked list: ");
        Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Node *head = NULL;
    int n, data;
    char choice;
    do {
        printf("===============Linked List Operations===============\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Print linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': {
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            }
            case '2': {
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            }
            case '3': {
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            }
            case '4': {
                printList(head);
                break;
            }
            case '5': {
                printf("Exiting the program!\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (choice != '5');
    return 0;
}