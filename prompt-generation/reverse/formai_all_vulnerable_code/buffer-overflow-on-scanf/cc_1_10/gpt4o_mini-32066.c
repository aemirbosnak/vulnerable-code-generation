//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertNode(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int key);
struct Node* searchNode(struct Node* head, int key);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertNode(head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* result = searchNode(head, value);
                if (result) {
                    printf("Value %d found in the list.\n", value);
                } else {
                    printf("Value %d not found in the list.\n", value);
                }
                break;
            case 4:
                printf("Current Linked List: ");
                printList(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to insert a new node
struct Node* insertNode(struct Node* head, int data) {
    if (!head) {
        return createNode(data);
    }
    head->next = insertNode(head->next, data);
    return head;
}

// Recursive function to delete a node with a given key
struct Node* deleteNode(struct Node* head, int key) {
    if (!head) {
        return NULL;
    }

    if (head->data == key) {
        struct Node* temp = head->next;
        free(head);
        return temp;
    }

    head->next = deleteNode(head->next, key);
    return head;
}

// Recursive function to search for a node
struct Node* searchNode(struct Node* head, int key) {
    if (!head || head->data == key) {
        return head;
    }
    return searchNode(head->next, key);
}

// Recursive function to print the linked list
void printList(struct Node* head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    printList(head->next);
}