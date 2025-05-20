//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include<stdio.h>
#include<stdlib.h>

// define a struct to represent a node in a doubly linked list
typedef struct node {
    int data;               // holds the integer value in the node
    struct node* prev;      // pointer to the previous node
    struct node* next;      // pointer to the next node
} Node;

// function to create a new node and return its pointer
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// function to insert a node at the end of the list
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
    newNode->prev = temp;
}

// function to print the list
void printList(Node* head) {
    printf("The list is: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// function to delete a node with a given value from the list
void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }
    Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    free(temp);
    printf("Node with value %d deleted\n", value);
}

// function to reverse the list
void reverseList(Node** head) {
    Node* current = *head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
    printf("The list has been reversed\n");
}

int main() {
    Node* head = NULL;
    int choice, value;
    while (1) {
        printf("\n1. Insert node at beginning\n2. Insert node at end\n3. Delete node with value\n");
        printf("4. Reverse the list\n5. Print the list\n6. Exit\n");
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
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                reverseList(&head);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}