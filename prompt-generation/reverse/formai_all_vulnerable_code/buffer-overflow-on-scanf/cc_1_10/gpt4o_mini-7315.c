//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int data);
void displayList(struct Node* head);
void deleteNode(struct Node** head, int key);
struct Node* searchNode(struct Node* head, int key);

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert Node at End\n");
        printf("2. Display List\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Enter data of node to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;

            case 4:
                printf("Enter data to search: ");
                scanf("%d", &key);
                struct Node* foundNode = searchNode(head, key);
                if (foundNode != NULL) {
                    printf("Node with data %d found.\n", foundNode->data);
                } else {
                    printf("Node with data %d not found.\n", key);
                }
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

// Function to search for a node in the list
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}