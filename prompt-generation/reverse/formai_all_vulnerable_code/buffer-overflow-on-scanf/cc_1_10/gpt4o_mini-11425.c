//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void displayMenu();
Node* createNode(int data);
void addNode(Node** head);
void removeNode(Node** head);
void displayList(Node* head);
void freeList(Node* head);

int main() {
    Node* head = NULL;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNode(&head);
                break;
            case 2:
                removeNode(&head);
                break;
            case 3:
                displayList(head);
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 0);
    
    freeList(head);
    return 0;
}

void displayMenu() {
    printf("----- Linked List Menu -----\n");
    printf("1. Add Node\n");
    printf("2. Remove Node\n");
    printf("3. Display List\n");
    printf("0. Exit\n");
    printf("----------------------------\n");
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head) {
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);
    
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;

    printf("Node with data %d added to the list.\n", data);
}

void removeNode(Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to remove.\n");
        return;
    }
    
    int data;
    printf("Enter data to remove: ");
    scanf("%d", &data);

    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found in the list.\n", data);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Node with data %d removed from the list.\n", data);
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    printf("Linked List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}