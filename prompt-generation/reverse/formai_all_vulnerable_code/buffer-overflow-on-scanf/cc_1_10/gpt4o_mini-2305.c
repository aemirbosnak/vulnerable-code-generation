//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void displayList(struct Node* head);
struct Node* search(struct Node* head, int data);
void freeList(struct Node** head);

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Search for a Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &data);
                struct Node* foundNode = search(head, data);
                if (foundNode != NULL) {
                    printf("Node with data %d found.\n", foundNode->data);
                } else {
                    printf("Node with data %d not found.\n", data);
                }
                break;
            case 6:
                freeList(&head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
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

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Node with data %d inserted at the end.\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to delete a node with given data
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If list is empty
    if (temp == NULL) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Change head
        free(temp);
        printf("Node with data %d deleted.\n", data);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If node was not found
    if (temp == NULL) {
        printf("Node with data %d not found. No nodes deleted.\n", data);
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", data);
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
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

// Function to search for a node with a given value
struct Node* search(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Not found
}

// Function to free the entire list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}