//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* current = *head;
    Node* prev = NULL;

    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    prev->next = current->next;
    free(current);
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchList(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // element found
        }
        current = current->next;
    }
    return 0; // element not found
}

int getLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    int choice, value;

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete a Node\n");
        printf("3. Display List\n");
        printf("4. Search Element\n");
        printf("5. Get Length of List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Current List: ");
                displayList(head);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (searchList(head, value)) {
                    printf("Element %d found in the list.\n", value);
                } else {
                    printf("Element %d not found in the list.\n", value);
                }
                break;
            case 5:
                printf("Length of the List: %d\n", getLength(head));
                break;
            case 6:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 7);

    freeList(head);
    return 0;
}