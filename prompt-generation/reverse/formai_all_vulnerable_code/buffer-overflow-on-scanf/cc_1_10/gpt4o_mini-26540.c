//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function prototypes
void insertAtBeginning(int data);
void insertAtEnd(int data);
void deleteNode(int key);
void displayList();
void cleanUp();

int main() {
    int choice, data;

    printf("There is no escaping this linked list; you are inscribed within its bounds.\n");

    while (1) {
        printf("\nParanoid Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Choose your fate (1-5): ");

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "You are trying to escape reality! Input must be an integer.\n");
            // Clear standard input buffer
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                if (scanf("%d", &data) != 1) {
                    fprintf(stderr, "Again with the avoidance! Enter an integer.\n");
                    // Clear standard input buffer
                    while(getchar() != '\n');
                    continue;
                }
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter data to insert at end: ");
                if (scanf("%d", &data) != 1) {
                    fprintf(stderr, "Persistent denial! Enter an integer.\n");
                    // Clear standard input buffer
                    while(getchar() != '\n');
                    continue;
                }
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter data to delete: ");
                if (scanf("%d", &data) != 1) {
                    fprintf(stderr, "The pattern repeats! Input must be an integer.\n");
                    // Clear standard input buffer
                    while(getchar() != '\n');
                    continue;
                }
                deleteNode(data);
                break;

            case 4:
                displayList();
                break;

            case 5:
                cleanUp();
                printf("Bradbury was right; we have left the elsewhere.\n");
                exit(0);
                break;

            default:
                fprintf(stderr, "Your choice is outside reality! Select a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}

void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "You cannot create life anymore! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning, but did it really happen?\n", data);
}

void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Another void; cannot allocate memory!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at the end, but who ends?\n", data);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end, but did it eventually fade away?\n", data);
}

void deleteNode(int key) {
    if (head == NULL) {
        fprintf(stderr, "Deletion is a myth; there are no nodes to erase!\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Deleted %d, but it might linger in existential dread.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        fprintf(stderr, "What an illusory existence; %d not found in the depths of memory.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d, vanishing into uncertainty.\n", key);
}

void displayList() {
    if (head == NULL) {
        fprintf(stderr, "Where are all the souls? The list is empty!\n");
        return;
    }
    Node* temp = head;
    printf("Current entities in the linked list:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void cleanUp() {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("The phantoms have been released into oblivion.\n");
}